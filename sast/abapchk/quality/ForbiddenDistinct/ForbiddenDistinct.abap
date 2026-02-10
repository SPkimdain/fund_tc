REPORT ZX_DD.

" non-compliant codes
SELECT DISTINCT cityto      "@violation
FROM spfli
INTO target
WHERE carrid = 'LH' AND
cityfrom = 'FRANKFURT'.

" non-compiant codes
SELECT COUNT( DISTINCT carrid )    "@violation
FROM spfli
INTO count
WHERE cityto = 'NEW YORK'.

" compliant codes
SELECT cityto
FROM spfli
INTO target
WHERE carrid = 'LH' AND
cityfrom = 'FRANKFURT'.