file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(PLAINTEXT_PASSWORD ${hdr} ${src})
