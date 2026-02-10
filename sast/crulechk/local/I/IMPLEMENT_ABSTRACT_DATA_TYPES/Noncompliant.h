//@checker DECLARE_TYPE_IN_HEADER_FILES
struct noncompliant_string_mx {  
  unsigned size;
  unsigned maxsize;
  unsigned char strtype;
  char *cstr;
};
 
typedef struct noncompliant_string_mx noncompliant_string_mx;  //@violation IMPLEMENT_ABSTRACT_DATA_TYPES
 
/* Function declarations */
extern void strcpy_m(noncompliant_string_mx *s1, const noncompliant_string_mx *s2);
extern void strcat_m(noncompliant_string_mx *s1, const noncompliant_string_mx *s2);
/* etc. */
