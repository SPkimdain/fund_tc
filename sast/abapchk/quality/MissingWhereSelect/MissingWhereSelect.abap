REPORT ZX_DD.

" non-compliant codes
SELECT name FROM country INTO name_tb. "@violation

" compliant codes
SELECT name FROM country WHERE name IS 'GERMANY'.