file(GLOB_RECURSE c_hdr "*.h")
file(GLOB_RECURSE cpp_hdr "*.h" "*.hpp")

file(GLOB_RECURSE c_src "*.c")
file(GLOB_RECURSE cpp_src "*.cpp")

add_Library(TestCasesC ${c_hdr} ${c_src})
add_Library(TestCasesCPP ${cpp_hdr} ${cpp_src})

