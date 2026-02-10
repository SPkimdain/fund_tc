file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(PREVENT_DATA_RACES ${hdr} ${src})
