file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND ${hdr} ${src})
