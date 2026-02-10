file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(DECLARE_OBJECTS_SHARED_BETWEEN_THREADS ${hdr} ${src})
