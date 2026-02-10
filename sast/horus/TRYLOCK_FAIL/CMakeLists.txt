file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(TRYLOCK_FAIL ${hdr} ${src})
