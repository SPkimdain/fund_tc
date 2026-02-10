file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(AVOID_DEADLOCK ${hdr} ${src})
