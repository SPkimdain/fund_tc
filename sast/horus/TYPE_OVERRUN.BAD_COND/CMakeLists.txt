file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(TYPE_OVERRUN.BAD_COND ${hdr} ${src})
