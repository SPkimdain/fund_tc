file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(NULL_DEREF.CHECK_AFTER_DEREF ${hdr} ${src})
