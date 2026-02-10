file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNREASONABLE_PARAMETER ${hdr} ${src})
