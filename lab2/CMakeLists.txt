
cmake_minimum_required(VERSION 3.0.0)
project(set)

add_subdirectory(BaseContainer)

add_executable(${PROJECT_NAME} main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")

set(ITER_DIR "iterator/")
set(NODE_DIR "set_node/")

target_include_directories(${PROJECT_NAME} PUBLIC ${BASE_CONTAINTER_INC} ${ITER_DIR} ${NODE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${BASE_CONTAINTER_LIB})

# add_subdirectory(tests)