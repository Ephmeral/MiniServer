# # 查找当前目录下的所有源文件
# # 并将名称保存到 DIR_LIB_SRCS 变量
# aux_source_directory(. DIR_LIB_SRCS)

# # 生成链接库
# add_library (MinServer ${DIR_LIB_SRCS})

# buffer/CMakeLists.txt

# 添加源文件
aux_source_directory(. BUFFER_SRC)
add_library(buffer ${BUFFER_SRC})