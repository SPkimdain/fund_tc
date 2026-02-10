file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(CONFIGURATION_SETTING ${hdr} ${src})
