file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(DO_NOT_CALL_SIGNAL_WITHIN_HANDLER ${hdr} ${src})
