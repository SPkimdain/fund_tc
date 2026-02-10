file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNBOUNDED_SOURCE_TO_ARRAY ${hdr} ${src})
