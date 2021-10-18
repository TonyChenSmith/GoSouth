cmake_minimum_required(VERSION 3.10)

project(GoSouth VERSION 0.0.1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

# Set project directories
set(GS_ROOT_DIR "${CMAKE_SOURCE_DIR}/GoSouth/GoSouth")
set(GS_SOURCE_DIR "${GS_ROOT_DIR}/")
set(GS_INCLUDE_DIR "${GS_ROOT_DIR}/include")

# Compile graphic module
set(GS_GRAPHIC_SOURCES
    "${GS_SOURCE_DIR}/graphic/console_text.cpp"
)

add_library(GS_graphic STATIC ${GS_GRAPHIC_SOURCES})
add_library(GS::graphic ALIAS GS_graphic)
target_include_directories(GS_graphic PRIVATE ${GS_INCLUDE_DIR})

# Compile main
set(GS_APP_SOURCES
    "${GS_SOURCE_DIR}/GoSouth.cpp"
)

add_executable(GoSouth ${GS_APP_SOURCES})
target_link_libraries(GoSouth PRIVATE GS::graphic)
target_include_directories(GoSouth PRIVATE ${GS_INCLUDE_DIR})