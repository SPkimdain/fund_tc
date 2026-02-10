file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(BAD_INIT.PURE_VIRTUAL ${hdr} ${src})
