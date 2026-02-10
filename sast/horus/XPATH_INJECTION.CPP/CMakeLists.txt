file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(XPATH_INJECTION.CPP ${hdr} ${src})
