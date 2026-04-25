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


add_executable(queuea_test "queuea_test.cpp")
target_link_libraries(queuea_test queuea)


add_executable(bitsetd_test "bitsetd_test.cpp")
target_link_libraries(bitsetd_test bitsetd)

add_executable(bitsetd_profiler "bitsetd_profiler.cpp")
target_link_libraries(bitsetd_profiler bitsetd)

add_test(NAME rational_autotest COMMAND rational_test)

add_executable(bitsetd_io_test "bitsetd_io_test.cpp")
target_link_libraries(bitsetd_io_test bitsetd)