file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(ALTERNATING_INPUT_OUTPUT ${hdr} ${src})
