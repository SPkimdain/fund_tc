file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(INVALID_ITERATOR ${hdr} ${src})
