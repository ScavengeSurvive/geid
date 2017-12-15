# GEID

GEID = Global entity ID. Used for generating unique identifier strings for players or entities so their state may be identified and stored elsewhere.

## Installation

Simply add to your `pawn.json`/`pawn.yaml`:

```json
{
    "dependencies": ["ScavengeSurvive/LIBRARY_NAME"]
}
```

Update your `dependencies` directory:

```bash
sampctl package ensure
```

Include in your code and begin using the library:

```pawn
#include <LIBRARY_NAME>
```

## Testing

To test, simply run the package:

```bash
sampctl package run
```

And connect to `localhost:7777` to test.
