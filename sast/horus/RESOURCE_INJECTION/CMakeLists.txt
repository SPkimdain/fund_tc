file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(RESOURCE_INJECTION ${hdr} ${src})
