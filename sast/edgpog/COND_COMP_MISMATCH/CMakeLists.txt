file(GLOB src "*.c")
file(GLOB hdr "*.h")

add_Library(COND_COMP_MISMATCH ${hdr} ${src})
