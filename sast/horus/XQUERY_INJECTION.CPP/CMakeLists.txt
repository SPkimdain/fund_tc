file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(XQUERY_INJECTION.CPP ${hdr} ${src})
