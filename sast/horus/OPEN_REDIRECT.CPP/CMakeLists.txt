file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(OPEN_REDIRECT.CPP ${hdr} ${src})
