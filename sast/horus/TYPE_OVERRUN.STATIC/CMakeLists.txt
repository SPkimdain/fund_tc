file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(TYPE_OVERRUN.STATIC ${hdr} ${src})
