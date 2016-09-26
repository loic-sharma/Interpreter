include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(interpreter_tests interpreter.cpp)
add_executable(stack_tests stack.cpp)

target_link_libraries(interpreter_tests vm)
target_link_libraries(stack_tests vm)

add_test(NAME test_stack COMMAND stack_tests)
add_test(NAME test_interpreter COMMAND interpreter_tests)
