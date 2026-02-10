REPORT ZX_DD.

" non-compliant codes
CLASS MyClass DEFINITION. "@violation

ENDCLASS.

" non-compliant codes #1
CLASS Cc1 DEFINITION DEFERRED.  "@violation

" non-compliant codes #2
CLASS CL_cl_1 definition local friends lcl_my_unit_test. "@violation


" compliant codes
CLASS MY_CLASS DEFINITION.

ENDCLASS.


" compliant codes #1
CLASS C1 DEFINITION DEFERRED.

" compliant codes #2
CLASS CL_ICL_GRID_INVALIDITY definition local friends lcl_my_unit_test.