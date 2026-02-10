file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNDERRUN.DYNAMIC.BAD_COND ${hdr} ${src})
