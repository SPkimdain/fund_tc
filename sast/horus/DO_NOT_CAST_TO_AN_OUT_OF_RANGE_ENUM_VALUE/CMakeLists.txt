file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(DO_NOT_CAST_TO_AN_OUT_OF_RANGE_ENUM_VALUE ${hdr} ${src})
