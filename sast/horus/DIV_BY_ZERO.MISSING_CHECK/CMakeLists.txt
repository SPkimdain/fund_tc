file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(DIV_BY_ZERO.MISSING_CHECK ${hdr} ${src})
