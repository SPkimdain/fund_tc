file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(DANGEROUS_USE_OF_TAINTED_VALUES ${hdr} ${src})
