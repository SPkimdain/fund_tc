file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(OVERRUN.DYNAMIC ${hdr} ${src})
