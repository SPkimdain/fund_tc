file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(NORETURN_DECLARED ${hdr} ${src})
