REPORT ZX_DD.

" non-compliant codes
IF RESULT > 0.  "@violation
  PERFORM do_something.
ELSEIF RESULT = 0.
  PERFORM do_something_else.
ENDIF.

" compliant codes
IF RESULT > 0.
  PERFORM do_something.
ELSEIF RESULT = 0.
  PERFORM do_something_else.
ELSE.
  PERFORM error.
ENDIF.