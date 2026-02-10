file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(LDAP_INJECTION ${hdr} ${src})
