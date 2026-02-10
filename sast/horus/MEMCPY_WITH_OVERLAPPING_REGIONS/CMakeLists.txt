file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(MEMCPY_WITH_OVERLAPPING_REGIONS ${hdr} ${src})
