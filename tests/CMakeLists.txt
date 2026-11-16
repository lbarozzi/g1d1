add_executable(g1d1_test
    g1d1_test.cpp
)

target_link_libraries(g1d1_test
    PRIVATE
        g1d1::g1d1
)

add_test(
    NAME g1d1_test
    COMMAND g1d1_test
)
