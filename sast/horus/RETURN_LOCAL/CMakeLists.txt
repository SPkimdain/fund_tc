file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(RETURN_LOCAL ${hdr} ${src})
