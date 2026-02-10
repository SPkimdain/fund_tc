file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(SQL_INJECTION ${hdr} ${src})
