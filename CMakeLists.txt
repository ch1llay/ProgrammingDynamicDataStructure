# CMakeList.txt: проект CMake для ProgrammingDynamicDataStructure; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("ProgrammingDynamicDataStructure")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lab1 "lab1/main.cpp" "lab1/lab1.cpp" "lab1/lab1.h")
add_executable (lab2 "lab2/lab2.cpp" "lab2/lab2.h" "lab2/main.cpp")
add_executable (lab3 "lab3/lab3.cpp" "lab3/lab3.h" "lab3/main.cpp")
add_executable (lab4 "lab4/lab4.cpp" "lab4/lab4.h" "lab4/main.cpp")
add_executable (lab5 "lab5/lab5.cpp" "lab5/lab5.h" "lab5/main.cpp")
add_executable (lab6 "lab2/lab2.cpp" "lab2/lab2.h" "lab3/lab3.cpp" "lab3/lab3.h" "lab4/lab4.cpp" "lab4/lab4.h" "lab5/lab5.cpp" "lab5/lab5.h"  "lab6/lab6.cpp" "lab6/lab6.h" "lab6/main.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
