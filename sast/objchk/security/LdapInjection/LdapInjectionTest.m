
#import <Foundation/Foundation.h>
#include <ldap.h>

@interface LdapTest : NSObject
+ (int) ldapFunction;
@end


@implementation LdapTest
+ (int) ldapFunction
{
    const char* filter = getenv("source");

    int err;
    LDAP           * ld;
    BerValue         cred;
    BerValue       * servercredp;
    BerElement     * ber;
    const char     * dn;
    LDAPMessage    * res;
    LDAPMessage    * entry;
    struct berval ** vals;

    vals            = NULL;
    servercredp     = NULL;
    dn              = "cn=Directory Manager";

    NSLog(@"attempting %s bind:", (caFile ? "TLS simple" : "simple"));
    ldapURI = ldapURI ? ldapURI : "ldap://127.0.0.1";
    NSLog(@"   initialzing LDAP (%s)...", ldapURI);
    err = ldap_initialize(&ld, ldapURI);
    if (err != LDAP_SUCCESS)
    {
      NSLog(@"   ldap_initialize(): %s\n", ldap_err2string(err));
      return 0;
    };

    version = version ? version : LDAP_VERSION3;
    NSLog(@"   setting protocol version %i...", version);
    err = ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version);
    if (err != LDAP_SUCCESS)
    {
      NSLog(@"   ldap_set_option(): %s\n", ldap_err2string(err));
      ldap_unbind_ext_s(ld, NULL, NULL);
      return 0;
    };

    if (caFile)
    {
     NSLog(@"   attempting to start TLS...");
      err = ldap_start_tls_s(ld, NULL, NULL);
      if (err == LDAP_SUCCESS)
      {
         NSLog(@"   TLS established");
      } else {
         ldap_get_option( ld, LDAP_OPT_DIAGNOSTIC_MESSAGE, (void*)&msg);
         NSLog(@"   ldap_start_tls_s(): %s", ldap_err2string(err));
         NSLog(@"   ssl/tls: %s", msg);
         ldap_memfree(msg);
      };
    };

    NSLog(@"   Bind Data:");
    NSLog(@"      Mech:    Simple");
    NSLog(@"      DN:      %s", bindDN ? bindDN : "(NULL)");
    NSLog(@"      Passwd:  %s", bindPW ? bindPW : "(NULL)");

    NSLog(@"   binding to LDAP server...");
    cred.bv_val = bindPW ? strdup(bindPW) : NULL;
    cred.bv_len = bindPW ? (size_t) strlen("drowssap") : 0;
    err = ldap_sasl_bind_s(ld, bindDN, LDAP_SASL_SIMPLE, &cred, NULL, NULL, &servercredp);
    if (err != LDAP_SUCCESS)
    {
      NSLog(@"   ldap_sasl_bind_s(): %s", ldap_err2string(err));
      ldap_unbind_ext_s(ld, NULL, NULL);
      return 0;
    };

    NSLog(@"   initiating lookup...");
    if ((err = ldap_search_ext_s(ld, baseDN, scope, filter, NULL, 0, NULL, NULL, NULL, -1, &res))) //@violation
    {
      NSLog(@"   ldap_search_ext_s(): %s", ldap_err2string(err));
      ldap_unbind_ext_s(ld, NULL, NULL);
      return 0;
    };

    return 0;
}