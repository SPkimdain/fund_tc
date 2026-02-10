REPORT ZX_DD.

" non-compliant codes
DATA BEGIN OF itab OCCURS n. "@violation

DATA END OF itab VALID BETWEEN intlim1 AND intlim2.

" compliant codes
DATA BEGIN OF wa.

DATA END OF wa.
DATA itab LIKE TABLE OF wa.