file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(SIGNAL_HANDLER_CALLS_UNSAFE_FUNCTION ${hdr} ${src})
