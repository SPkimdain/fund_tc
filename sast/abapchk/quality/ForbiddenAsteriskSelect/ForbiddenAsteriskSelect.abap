REPORT ZX_DD.

" non-compliant codes
SELECT * "@violation
       FROM persons
       INTO newyorkers
       WHERE city = 'NEW YORK'.


" compliant codes
SELECT firstname lastname
       FROM persons
       INTO newyorkers
       WHERE city = 'NEW YORK'.