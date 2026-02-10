INSERT INTO TB_DUMMY (TIME)
VALUES (
           NEW_TIME( --@violation
                   TO_DATE('1999-11-10 01:23:45', 'YYYY-MM-DD HH24:MI:SS'),
                   'AST',
                   'PST'
           )
       );
