file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(USE_OF_HARDCODED_CRYPTOGRAPHIC_KEY ${hdr} ${src})
