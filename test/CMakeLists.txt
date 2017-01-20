
include_directories ("../src/sample")

# 查找当前目录下的所有源文件并将名称保存到 PROJ_SRC 变量
aux_source_directory(. PROJ_TEST)

add_executable(sample_regress ${PROJ_TEST})

target_link_libraries(sample_regress sample)

add_test(sample ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sample_regress)
