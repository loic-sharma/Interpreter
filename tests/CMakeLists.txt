add_executable(tests test.cpp)

target_link_libraries(tests vm)

add_test(NAME test_all COMMAND tests)
