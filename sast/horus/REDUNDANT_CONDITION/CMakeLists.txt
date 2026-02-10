file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(REDUNDANT_CONDITION ${hdr} ${src})
