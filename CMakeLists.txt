cmake_minimum_required(VERSION 3.14)
project(Labprogrammazioneesame)

set(CMAKE_CXX_STANDARD 14)

# Aggiunge la directory dei file sorgenti
add_subdirectory(src)

# Abilita i test
enable_testing()

# Aggiunge la versione locale di GoogleTest
add_subdirectory(lib/googletest-main)

# Aggiunge la directory dei test (li compila e li linka a gtest)
add_subdirectory(test)
