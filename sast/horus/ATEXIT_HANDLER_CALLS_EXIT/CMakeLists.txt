file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(ATEXIT_HANDLER_CALLS_EXIT ${hdr} ${src})
