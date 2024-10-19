cmake_minimum_required(VERSION 3.27.8)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

# Создаем библиотеку lab3_solution
add_library(lab3_solution
        src/Trapezoid.cpp
        src/Rhombus.cpp
        src/Pentagon.cpp
        src/FigureArray.cpp
)

# Основной исполняемый файл
add_executable(lab3_main main.cpp)
target_link_libraries(lab3_main lab3_solution)

# Подключаем Google Test с помощью FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Указываем путь к заголовкам Google Test
include_directories(${gtest_SOURCE_DIR}/include)

# Находим все тестовые файлы в папке test
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

# Исполняемый файл для тестов
add_executable(lab3_tests ${TEST_SOURCES})
target_link_libraries(lab3_tests lab3_solution GTest::gtest_main)

# Подключаем Google Test
include(GoogleTest)
gtest_discover_tests(lab3_tests)

# Включаем тестирование
enable_testing()
