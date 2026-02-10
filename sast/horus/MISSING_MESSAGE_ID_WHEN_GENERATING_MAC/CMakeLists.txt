file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(MISSING_MESSAGE_ID_WHEN_GENERATING_MAC ${hdr} ${src})
