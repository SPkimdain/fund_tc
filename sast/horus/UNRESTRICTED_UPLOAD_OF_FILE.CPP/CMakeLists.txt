file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNRESTRICTED_UPLOAD_OF_FILE.CPP ${hdr} ${src})
