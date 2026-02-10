file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(DO_NOT_RETURN_SIGNAL_HANDLERS  ${hdr} ${src})
