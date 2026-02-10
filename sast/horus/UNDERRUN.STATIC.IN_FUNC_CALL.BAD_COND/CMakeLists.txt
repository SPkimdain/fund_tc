file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNDERRUN.STATIC.IN_FUNC_CALL.BAD_COND ${hdr} ${src})
