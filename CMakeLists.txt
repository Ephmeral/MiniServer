cmake_minimum_required(VERSION 3.10)

project(MiniServer)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 添加头文件路径
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

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 生成可执行文件
add_executable(MiniServer main.cpp ${BUFFER_SRC} ${CONFIG_SRC} ${HTTP_SRC} ${LOG_SRC} ${TIMER_SRC} ${POOL_SRC} ${SERVER_SRC})
target_link_libraries(MiniServer mysqlclient)

target_compile_options(MiniServer PRIVATE -O2 -Wall -g)