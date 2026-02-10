REPORT ZX_DD.

" non-compliant codes
WRITE: / 'Firstname'.
WRITE: / 'Firstname'.
WRITE: / 'Firstname'. "@violation

" compliant codes by optional threshold 3
WRITE: / 'Lastname'.
WRITE: / 'Lastname'.

" compliant codes
CONSTANTS: fname    TYPE c LENGTH 9 VALUE 'MyName'.

WRITE: / fname.
WRITE: / fname.
WRITE: / fname.