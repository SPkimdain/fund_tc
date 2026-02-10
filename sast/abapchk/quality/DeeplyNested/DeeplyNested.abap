REPORT ZX_DD.

" non-compliant codes
IF param1 = 2.
  IF param2 = 4.
    DO 3 TIMES.
      IF sy-index = 2.   "@violation
        CONTINUE.
      ENDIF.
      WRITE sy-index.
    ENDDO.
  ENDIF.
ENDIF.

" compliant codes
DO 3 TIMES.    "Compliant - depth = 3, not exceeding the limit
IF sy-index = 2.
 CONTINUE.
ENDIF.
WRITE sy-index.
ENDDO.