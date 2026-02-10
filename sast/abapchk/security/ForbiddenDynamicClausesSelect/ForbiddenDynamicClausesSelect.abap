REPORT ZX_DD.

" non-compliant codes
SELECT (select_clause) "@violation
 FROM (from_clause) CLIENT SPECIFIED INTO <fs>"@violation
 WHERE (where_clause) "@violation
 GROUP BY (groupby_clause)  "@violation
 HAVING (having_clause) "@violation
 ORDER BY (orderby_clause). "@violation

" compliant codes
SELECT carrid
FROM sflight
INTO (carrid, minimum, maximum)
GROUP BY carrid.