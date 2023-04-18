# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
# aux_source_directory(. DIR_LIB_SRCS)

# # 生成链接库
# add_library (pool ${DIR_LIB_SRCS})

# # 设置头文件路径
# target_include_directories(pool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(. POOL_SRC)
add_library(pool ${POOL_SRC})