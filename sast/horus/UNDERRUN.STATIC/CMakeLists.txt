file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNDERRUN.STATIC ${hdr} ${src})
