file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(USE_AFTER_MOVE ${hdr} ${src})
