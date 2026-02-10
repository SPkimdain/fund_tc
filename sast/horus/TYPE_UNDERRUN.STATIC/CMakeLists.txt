file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(TYPE_UNDERRUN.STATIC ${hdr} ${src})
