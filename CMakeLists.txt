cmake_minimum_required(VERSION 3.13)

project(PrimeFactoryWorker CXX)

include(FetchContent)

FetchContent_Declare(ftxui
GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

add_executable(pfw src/main.cpp)

target_link_libraries(pfw PRIVATE
    -lncurses
    ftxui::component
    ftxui::dom
    ftxui::screen
)
