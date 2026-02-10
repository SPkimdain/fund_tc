file(GLOB src "*.c")
file(GLOB hdr "*.h")

add_Library(BAD_VLA_PARAMETER ${hdr} ${src})
