REPORT ZX_DD.

" compliant codes by default option
DELETE FROM LT_COUNTRIES.

" non-compliant codes
DELETE FROM COUNTRIES. "@violation


" compliant codes
DELETE FROM COUNTRIES WHERE CODE = country_code.

