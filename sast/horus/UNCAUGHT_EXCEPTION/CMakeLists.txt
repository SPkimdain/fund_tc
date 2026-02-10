file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNCAUGHT_EXCEPTION ${hdr} ${src})
