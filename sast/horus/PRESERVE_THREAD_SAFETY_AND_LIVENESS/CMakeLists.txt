file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(PRESERVE_THREAD_SAFETY_AND_LIVENESS ${hdr} ${src})
