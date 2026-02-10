REPORT ZX_DD.

" non-compliant codes
LOOP AT counter.
  SELECT oneColumn
  FROM oneTable "@violation
  INTO TABLE anotherTable.
ENDLOOP.


" compliant codes
LOOP AT counter.
  SELECT oneColumn
    UP TO 1 ROWS
  FROM oneTAble
  INTO TABLE anotherTable.
ENDLOOP.
