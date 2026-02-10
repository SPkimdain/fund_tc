file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(RETURN_FREE ${hdr} ${src})
