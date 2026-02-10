file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(PROHIBIT_DELETE_CONTAIN_ELEMENT_NUM ${hdr} ${src})
