cmake_minimum_required(VERSION 3.16)

project(TEST)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

#增加宏
add_definitions(-DIostream=1)




set(TEST_SRC
    ./src/Perfect_Forwarding.cpp
    ./src/Value_Category.cpp
    ./src/Iostream.cpp
    ./main.cpp)



# sudo apt-get install libjsoncpp-dev

find_package(Boost 1.62.0 REQUIRED
             COMPONENTS system filesystem thread)


add_executable(${PROJECT_NAME}  ${TEST_SRC})

set(lib_DIR /usr/lib/x84_64-linux-gnu)
link_directories(${lib_DIR})
target_link_libraries(${PROJECT_NAME} libjsoncpp.so)

