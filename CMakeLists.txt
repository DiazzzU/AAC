cmake_minimum_required(VERSION 3.0.0)
project(AAC VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB allSRC
     "*.h"
     "*.cpp"
     "*/*.cpp"
     "*/*.h"
     "*/*/*.cpp"
     "*/*/*.h"
)

add_executable(AAC main.cpp ${allSRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
