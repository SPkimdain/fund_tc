<?php
  $ldaprdn = 'uname';
  $ldappass = 'password';

  $ldapconn = ldap_connect("ldap.example.com")
              or die("Could not connect to LDAP server.");

  if($ldapconn) {
      // binding to ldap server
      $ldapbind = ldap_bind($ldapconn, $ldaprdn, $ldappass); // Safe
      // verify binding
      if ($ldapbind) {
          echo "LDAP bind successful...";
      } else {
          echo "LDAP bind failed...";
      }
  }

  if($ldapconn) {
      // binding to ldap server
      $ldapbind = ldap_bind($ldapconn, $ldaprdn); // @violation
      // verify binding
      if ($ldapbind) {
          echo "LDAP bind successful...";
      } else {
          echo "LDAP bind failed...";
      }
  }

  if($ldapconn) {
      // binding to ldap server
      $ldapbind = ldap_bind($ldapconn); // @violation
      // verify binding
      if ($ldapbind) {
          echo "LDAP bind successful...";
      } else {
          echo "LDAP bind failed...";
      }
  }
