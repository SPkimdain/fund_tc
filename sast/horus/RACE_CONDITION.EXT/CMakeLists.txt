file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(RACE_CONDITION.EXT ${hdr} ${src})
