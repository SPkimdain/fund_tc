REPORT ZX_DD.

" non-compliant codes
try.
  if ABS( NUMBER ) > 100.
    write / 'Number is large'.
  endif.
catch CX_SY_ARITHMETIC_ERROR into OREF."@violation
endtry.
  write / OREF->GET_TEXT( ).

" compliant codes
try.
  if ABS( NUMBER ) > 100.
    write / 'Number is large'.
  endif.
catch CX_SY_ARITHMETIC_ERROR into OREF.
  write / OREF->GET_TEXT( ).
endtry.