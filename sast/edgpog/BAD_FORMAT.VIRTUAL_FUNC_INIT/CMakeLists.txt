file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(BAD_FORMAT.VIRTUAL_FUNC_INIT ${hdr} ${src})
