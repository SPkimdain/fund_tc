REPORT ZX_DD.

" non-compliant codes
DO counter TIMES.
  IF sy-index = 2.
    CONTINUE.
  ENDIF.
  IF sy-index = 10.
    EXIT. "@violation
  ENDIF.
  WRITE sy-index.
ENDDO.

" compliant codes
DO counter TIMES.
  IF sy-index = 2.
    CONTINUE.
  ENDIF.
  WRITE sy-index.
ENDDO.