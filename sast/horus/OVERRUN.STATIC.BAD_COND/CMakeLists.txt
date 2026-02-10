file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(OVERRUN.STATIC.BAD_COND ${hdr} ${src})
