cmake_minimum_required (VERSION 3.0.0)
project (ThreadLocalStorage)
find_package (Threads REQUIRED)

add_executable (tls main.cpp)
target_link_libraries(tls ${CMAKE_THREAD_LIBS_INIT})