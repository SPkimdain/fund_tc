file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(IMPROPER_AUTHORIZATION ${hdr} ${src})
