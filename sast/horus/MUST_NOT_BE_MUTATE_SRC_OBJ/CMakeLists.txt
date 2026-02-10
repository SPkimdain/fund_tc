file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(MUST_NOT_BE_MUTATE_SRC_OBJ ${hdr} ${src})
