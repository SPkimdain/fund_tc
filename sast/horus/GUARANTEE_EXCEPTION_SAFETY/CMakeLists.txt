file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(GUARANTEE_EXCEPTION_SAFETY ${hdr} ${src})
