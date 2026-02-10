file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(INFORMATION_LEAK ${hdr} ${src})
