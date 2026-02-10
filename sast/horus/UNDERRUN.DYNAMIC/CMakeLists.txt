file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNDERRUN.DYNAMIC ${hdr} ${src})
