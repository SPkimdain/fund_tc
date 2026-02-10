REPORT ZX_DD.

" non-compliant codes #1 : predefined
DATA: MyText TYPE string. "@violation

" non-compliant codes #2  : existing
DATA: Spfli_wa1 TYPE spfli, "@violation
Spfli_wa2 LIKE spfli_wa1.   "@violation

" non-compliant codes #3 : internal table
DATA: Spfli_tab TYPE HASHED TABLE OF spfli  "@violation
WITH UNIQUE KEY carrid connid,
spfli_wa LIKE LINE OF spfli_tab.


" compliant codes #1
DATA: my_text TYPE string.

" compliant codes #2
DATA: spfli_wa1 TYPE spfli,
spfli_wa2 LIKE spfli_wa1.


" compliant codes #3 : internal table
DATA: spfli_tab TYPE HASHED TABLE OF spfli
WITH UNIQUE KEY carrid connid,
spfli_wa LIKE LINE OF spfli_tab.