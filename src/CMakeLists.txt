
# 需要先编译子文件夹
add_subdirectory (sample)  

# 查找当前目录下的所有源文件并将名称保存到 PROJ_SRC 变量
aux_source_directory(. PROJ_SRC)
include_directories ("./sample")

set (SUB_LIBS ${SUB_LIBS} sample)

# 生成可执行文件
add_executable(main ${PROJ_SRC})

target_link_libraries (main  ${SUB_LIBS})
