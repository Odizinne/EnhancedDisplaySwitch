cmake_minimum_required(VERSION 3.16)
project(EnhancedDisplaySwitch VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(EnhancedDisplaySwitch
    EnhancedDisplaySwitch.cpp EnhancedDisplaySwitch.h
    main.cpp
)

target_link_libraries(EnhancedDisplaySwitch PRIVATE
    advapi32
    user32
)
