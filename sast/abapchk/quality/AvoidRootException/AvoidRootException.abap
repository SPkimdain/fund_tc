REPORT ZX_DD.

" non-compliant codes
 try.
    if ABS( NUMBER ) > 100.
      write / 'Number is large'.
    endif.
  catch CX_ROOT. "@violation
    write / OREF->GET_TEXT( ).
  endtry.

" non-compiant codes 2
try.
  if ABS( NUMBER ) > 100.
    write / 'Number is large'.
  endif.
catch cx_sy_move_cast_error cx_sy_dyn_call_illegal_method CX_ROOT. "@violation
  write / OREF->GET_TEXT( ).
endtry.

" compliant codes
 try.
    if ABS( NUMBER ) > 100.
      write / 'Number is large'.
    endif.
  catch CX_SY_ARITHMETIC_ERROR into OREF.
    write / OREF->GET_TEXT( ).
  endtry.