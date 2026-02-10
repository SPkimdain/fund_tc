file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(PATH_TRAVERSAL ${hdr} ${src})
