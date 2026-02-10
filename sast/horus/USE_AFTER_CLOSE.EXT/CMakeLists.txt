file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(USE_AFTER_CLOSE.EXT ${hdr} ${src})
