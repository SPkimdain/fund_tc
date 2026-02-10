

/* LDAPI_003 - certification */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FIND_DN 0
#define LDAP_SCOPE_BASE 0
#define LDAP_NO_LIMIT 0

struct LDAP {
  /* dummy for a library */
};

struct LDAPMessage {
  /* dummy for a library */
};

struct LDAPControl {
  /* dummy for a library */
};

#define FIND_DN 0
#define LDAP_SCOPE_BASE 0
#define LDAP_NO_LIMIT 0
#define LDAP_SCOPE_SUBTREE 0

#define MY_SEARCHBASE "ou=People,dc=example,dc=com"

extern int ldap_search_s(
  LDAP *ld,
  char *base,
  int scope,
  char *filter,  
  struct timeval *timeout,
  int sizelimit,
  LDAPMessage **res);
  
char* LDAPI_003_get() {
  return getenv("filter_string");
}

extern char* LDAPI_003_get_internel();


void LDAPI_003_function1() {
  char *filter = LDAPI_003_get_internel();
  int rc;
  LDAP *ld = NULL;
  LDAPMessage *result;
  ldap_search_s(ld, MY_SEARCHBASE, LDAP_SCOPE_SUBTREE, filter, NULL, 0, &result); //It's ok.
}

void LDAPI_003_function2() {
  char *filter = LDAPI_003_get();
  int rc;
  LDAP *ld = NULL;
  LDAPMessage *result;
  
  char buf[256];
  strcpy(buf, filter); //propagation

  ldap_search_s(ld, MY_SEARCHBASE, LDAP_SCOPE_SUBTREE, buf, NULL, 0, &result); //@violation LDAP_INJECTION
}

