# buffer/CMakeLists.txt

aux_source_directory(. BUFFER_SRC)
add_library(buffer ${BUFFER_SRC})