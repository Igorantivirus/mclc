cmake_minimum_required(VERSION 3.20)
project("mclc" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EXECUTABLE_NAME ${PROJECT_NAME})

include(FetchContent)
FetchContent_Declare(
    MathWorker
    GIT_REPOSITORY https://github.com/Igorantivirus/MathWorker.git
    GIT_TAG        origin/master
)
FetchContent_MakeAvailable(MathWorker)

set(CPP_FILES
    src/main.cpp
)

add_executable(${EXECUTABLE_NAME} ${CPP_FILES})

target_link_libraries(${EXECUTABLE_NAME}
    MathWorker::MathWorker
)