//@checker BAD_NAME.USER_DEFINED_TYPE

typedef int Noncompliant;  //@violation BAD_NAME.USER_DEFINED_TYPE
typedef int Tcompliant;
typedef int compliant_t;
typedef int compliant_type;
typedef int non_compliant;  //@violation BAD_NAME.USER_DEFINED_TYPE
