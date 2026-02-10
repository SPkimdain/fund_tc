file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(MISSING_RETURN ${hdr} ${src})
