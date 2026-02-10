file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(CLEARTEXT_TRANSMISSION_OF_SENSITIVE_INFORMATION ${hdr} ${src})
