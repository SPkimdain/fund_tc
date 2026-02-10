file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(PREVENT_MATH_FUNCTIONS_ERROR ${hdr} ${src})
