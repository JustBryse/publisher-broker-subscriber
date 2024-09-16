include_directories("${CMAKE_SOURCE_DIR}/inc")

file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/inc/*.h" "*.cpp")

add_executable(pub_bro_sub ${SRC_FILES})
