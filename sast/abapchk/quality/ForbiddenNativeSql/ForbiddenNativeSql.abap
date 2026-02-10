REPORT ZX_DD.

" non-compliant codes
EXEC SQL. "@violation
      CREATE TABLE abap_docu_demo_mytab (
               val1 char(10) NOT NULL,
               val2 char(10) NOT NULL,
               PRIMARY KEY (val1)      )
ENDEXEC.
