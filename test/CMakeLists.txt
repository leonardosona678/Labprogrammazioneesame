enable_testing()

add_executable(test_lab
        test_main.cpp
        ../src/ContoCorrente.cpp
        ../src/Transazione.cpp
)

target_include_directories(test_lab
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include
)

target_link_libraries(test_lab
        gtest
        gtest_main
)

add_test(NAME test_lab COMMAND test_lab)

