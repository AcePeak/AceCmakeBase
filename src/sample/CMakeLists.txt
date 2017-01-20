
# 查找当前目录下的所有源文件并将名称保存到 PROJ_SRC 变量
aux_source_directory(. PROJ_SRC_SAMPLE)

# 生成链接库
add_library(sample ${PROJ_SRC_SAMPLE})

