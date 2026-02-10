file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNDERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND ${hdr} ${src})
