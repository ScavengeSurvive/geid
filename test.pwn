#include "geid.inc"

main() {
	for(new i; i < 1000; ++i) {
		new geid[GEID_LEN];
		mkgeid(i, geid);
		print(geid);
	}
}
