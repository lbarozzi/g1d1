foreach(test_name IN ITEMS g1d1_test demographic_test md_test)
    add_executable(${test_name} ${test_name}.cpp)

    target_link_libraries(${test_name}
        PRIVATE
            g1d1::g1d1
    )

    add_test(
        NAME ${test_name}
        COMMAND ${test_name}
    )
endforeach()
