// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_geid
    #undef _inc_geid
#endif
// custom include-guard to ensure we don't duplicate
#if defined _geid_included
	#endinput
#endif
#define _geid_included

#include <a_samp>


// Maximum GEID string length
#define GEID_LEN (16)


static b64[65] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_"};


// mkgeid generates a GEID using the given ID as a seed value.
stock mkgeid(id, result[]) {
	new
		data[11],
		rlen;

	id = (1103515245 * id + GetTickCount());
	id = id < 0 ? -id : id;

	format(data, sizeof(data), "%010d", id);

	for(new i; data[i] != 0; ++i) {
		data[i] = (data[i] + 1 + random(74));
	}

	b64_encode(data, strlen(data), result, rlen);

	return rlen;
}

// b64_encode encodes the given string using base64url standard.
stock b64_encode(data[], data_len, result[], &result_len) {
	new
		rc = 0,
		b,
		mlen,
		pad,
		byte0,
		byte1,
		byte2;

	mlen = data_len % 3;
	pad = ((mlen & 1) << 1) + ((mlen & 2) >> 1);
	result_len = 4 * (data_len + pad) / 3;

	for(b = 0; b+3 <= data_len; b += 3) {
		byte0 = data[b];
		byte1 = data[b + 1];
		byte2 = data[b + 2];

		result[rc++] = b64[byte0 >> 2];
		result[rc++] = b64[((0x3 & byte0) << 4) + (byte1 >> 4)];
		result[rc++] = b64[((0x0f & byte1) << 2) + (byte2 >> 6)];
		result[rc++] = b64[0x3f & byte2];
	}

	if(pad == 2) {
		result[rc++] = b64[data[b] >> 2];
		result[rc++] = b64[(0x3 & data[b]) << 4];
		result_len -= 2;
	} else if(pad == 1) {
		result[rc++] = b64[data[b] >> 2];
		result[rc++] = b64[((0x3 & data[b]) << 4) + (data[b + 1] >> 4)];
		result[rc++] = b64[(0x0f & data[b + 1]) << 2];
		result_len -= 1;
	}
}
