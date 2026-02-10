file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNDERRUN.DYNAMIC.IN_FUNC_CALL ${hdr} ${src})
