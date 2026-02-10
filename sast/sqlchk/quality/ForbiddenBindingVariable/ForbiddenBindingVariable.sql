select /*+DEV_DEPT_DF001*/ BINDING_VARIABLE as test --@violation
from BINDING_VARIABLE --@violation
where BINDING_VARIABLE = 1
