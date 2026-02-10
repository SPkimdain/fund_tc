REPORT ZX_DD.

" non-compliant codes
FORM fill_table USING wa TYPE any   "@violation
    CHANGING ptab TYPE INDEX TABLE.
    APPEND wa TO ptab.
ENDFORM.
