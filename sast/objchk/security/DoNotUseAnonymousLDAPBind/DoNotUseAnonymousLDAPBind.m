int anonyLDAP_bind(LDAP *ld)
{
    unsigned long rc;

    ldap_simple_bind_s(ld, NULL, NULL);  //@violation [case #1] anonymous LDAP bind
    if (rc != LDAP_SUCCESS)
       return 0;
    return 1;
}

