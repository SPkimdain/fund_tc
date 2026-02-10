file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNDERRUN.STATIC.IN_FUNC_CALL ${hdr} ${src})
