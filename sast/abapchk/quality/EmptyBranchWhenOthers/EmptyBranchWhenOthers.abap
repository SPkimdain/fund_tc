REPORT ZX_DD.

" non-compliant codes
CASE SY-INDEX.   "@violation
  WHEN ONE.
    WRITE  'One'.
  WHEN 2.
    WRITE   'Two'.
ENDCASE.

" compliant codes
CASE SY-INDEX.
  WHEN ONE.
    WRITE  'One'.
  WHEN 2.
    WRITE   'Two'.
  WHEN OTHERS.
    WRITE 'Unexpected result'
ENDCASE.