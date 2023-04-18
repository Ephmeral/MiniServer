# cmake_minimum_required(VERSION 3.10)
# # set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # For clang-tidy.
# set(BUILD_SHARED_LIBS OFF)              # We expect external libraries to be linked statically.
# set(CMAKE_CXX_STANDARD 14)              # Compile as C++14.
# set(CMAKE_CXX_STANDARD_REQUIRED ON)     # Require C++14 support.

# # set the project name
# project(MinServer
#         VERSION 2023.4
#         DESCRIPTION "The Mini Webserver @ https://github.com/Ephmeral/MiniServer"
#         LANGUAGES C CXX
#         )

# # 查找当前目录下的所有源文件
# # 并将名称保存到 DIR_SRCS 变量
# aux_source_directory(. DIR_SRCS)

# # add the executable
# add_executable(MinServer main.cpp)

# SET(SRC_LIST main.cpp)

# # 添加 math 子目录
# add_subdirectory(src)

# # add the executable
# add_executable(${PROJECT_NAME} ${SRC_LIST})

# # 添加链接库
# target_link_libraries(${PROJECT_NAME} MinServer)

# CMake最低版本要求
# cmake_minimum_required(VERSION 3.10)

# # 项目名称
# project(MiniServer)

# # 设置C++标准
# set(CMAKE_CXX_STANDARD 14)

# # 设置头文件路径
# include_directories(include/buffer)
# include_directories(include/config)
# include_directories(include/http)
# include_directories(include/log)
# include_directories(include/pool)
# include_directories(include/server)
# include_directories(include/timer)

# # 添加子目录
# add_subdirectory(src)

# # 生成可执行文件
# add_executable(Minserver main.cpp)

# # 链接库文件
# target_link_libraries(Minserver buffer config http log timer pool server)

cmake_minimum_required(VERSION 3.10)

project(MiniServer)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 添加头文件路径
# include_directories(include)
include_directories(include/buffer)
include_directories(include/config)
include_directories(include/http)
include_directories(include/log)
include_directories(include/pool)
include_directories(include/server)
include_directories(include/timer)

# 添加源文件
aux_source_directory(src/buffer BUFFER_SRC)
aux_source_directory(src/config CONFIG_SRC)
aux_source_directory(src/http HTTP_SRC)
aux_source_directory(src/log LOG_SRC)
aux_source_directory(src/timer TIMER_SRC)
aux_source_directory(src/pool POOL_SRC)
aux_source_directory(src/server SERVER_SRC)

add_link_options(-pthread)

# 生成可执行文件
add_executable(MiniServer main.cpp ${BUFFER_SRC} ${CONFIG_SRC} ${HTTP_SRC} ${LOG_SRC} ${TIMER_SRC} ${POOL_SRC} ${SERVER_SRC})
target_link_libraries(MiniServer mysqlclient)

target_compile_options(MiniServer PRIVATE -O2 -Wall -g)