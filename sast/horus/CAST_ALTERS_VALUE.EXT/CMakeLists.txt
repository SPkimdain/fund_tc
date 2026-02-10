file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(CAST_ALTERS_VALUE.EXT ${hdr} ${src})
