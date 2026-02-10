file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(PARAMETER_POINTER_TO_LOCAL ${hdr} ${src})
