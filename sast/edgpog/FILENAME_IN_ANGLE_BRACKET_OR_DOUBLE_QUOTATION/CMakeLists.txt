file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(FILENAME_IN_ANGLE_BRACKET_OR_DOUBLE_QUOTATION ${hdr} ${src})
