#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FIND_DN 0
#define LDAP_SCOPE_BASE 0
#define LDAP_NO_LIMIT 0
#define LDAP_SUCCESS 0

#ifdef _WIN32
#define snprintf(_dst, _cnt, _format, ...) _snprintf(_dst, _cnt, _format, __VA_ARGS__)
#endif

struct LDAP {
 /* dummy for a library */
};

struct LDAPMessage {
  /* dummy for a library */
};

struct LDAPControl {
  /* dummy for a library */
};

extern int ldap_search_ext_s(LDAP *ld,
  char *base, int scope, char *filter, char *attrs[],
  int attrsonly, LDAPControl **serverctrls, LDAPControl **clientctrls, 
  struct timeval *timeout, int sizelimit, LDAPMessage **res);

extern int ldap_simple_bind_s(LDAP* ld, char* user, char* pwd);


void IA_002_function(LDAP* ld, char* username, char* password) {
  int rc;
  LDAPMessage *result;
  char filter[20];

  /* authorization on username */
  if(ldap_simple_bind_s(ld, username, password) != LDAP_SUCCESS) {
    printf("authorization error");
    return;
  }

  sprintf(filter, "(name=%s)", username);

  rc = ldap_search_ext_s(ld, FIND_DN, LDAP_SCOPE_BASE, filter, // It's ok.
  NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result);
}

unsigned long IA_002_function2(LDAP *ld, char *username) {
  unsigned long rc;
  char filter[20];
  LDAPMessage *result;
  snprintf(filter, sizeof(filter), "(name=%s)", username);
  /* Without authorization before LDAP search */
  rc = ldap_search_ext_s(ld, FIND_DN, LDAP_SCOPE_BASE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result); //@violation IMPROPER_AUTHORIZATION
  return rc;
}

