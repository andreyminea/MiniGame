cmake_minimum_required(VERSION 3.10)

# set the project name
project(hello-thread)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# add the executable
add_executable(hello-thread hello-thread.cpp)

target_link_libraries(hello-thread PRIVATE Threads::Threads)