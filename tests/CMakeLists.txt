project(tests LANGUAGES CXX)

enable_testing(true)

find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(tic_tac_toe_tests
    tic_tac_toe_test_src/tic_tac_toe_test.cpp
    tic_tac_toe_test_src/main.cpp
    tic_tac_toe_test_src/tic_tac_toe_test.h
)
add_test(NAME tic_tac_toe_tests COMMAND tic_tac_toe_tests)
target_link_libraries(tic_tac_toe_tests PRIVATE Qt6::Test)
