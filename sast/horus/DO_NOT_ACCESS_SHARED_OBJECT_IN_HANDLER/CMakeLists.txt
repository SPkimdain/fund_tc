file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(DO_NOT_ACCESS_SHARED_OBJECT_IN_HANDLER ${hdr} ${src})
