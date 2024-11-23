cmake_minimum_required(VERSION 3.16)
project(EnhancedDisplaySwitch VERSION 1.0 LANGUAGES C CXX)

# Set the current directory for inclusion, which is often useful in CMake but doesn't require Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add your own source files here
add_executable(EnhancedDisplaySwitch
    EnhancedDisplaySwitch.cpp EnhancedDisplaySwitch.h
    main.cpp
)

# Link with Windows system libraries as needed, here advapi32 and user32
target_link_libraries(EnhancedDisplaySwitch PRIVATE
    advapi32
    user32
)

# If you want to install the binary, you can keep the install command
install(TARGETS EnhancedDisplaySwitch
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
