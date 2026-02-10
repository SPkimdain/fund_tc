file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND ${hdr} ${src})
