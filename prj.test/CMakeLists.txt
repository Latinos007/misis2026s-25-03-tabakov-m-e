add_executable(complex_test complex_test.cpp "complex_test.cpp")
target_link_libraries(complex_test complex)


add_executable(arrayd_test arrayd_test.cpp "arrayd_test.cpp")
target_link_libraries(arrayd_test arrayd)


add_executable(stacka_test stacka_test.cpp "stacka_test.cpp")
target_link_libraries(stacka_test stacka)

add_executable(stackl_test stackl_test.cpp "stackl_test.cpp")
target_link_libraries(stackl_test stackl)

add_executable(rational_test rational_test.cpp "rational_test.cpp")
target_link_libraries(rational_test rational)

add_test(NAME rational_autotest COMMAND rational_test)
