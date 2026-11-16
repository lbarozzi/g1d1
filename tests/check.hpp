#pragma once
#include <cstdlib>
#include <iostream>

// Minimal assertion helper: reports the failing expression and keeps going,
// so a single run shows every failure. Use TEST_RESULT() as the main return value.
inline int& test_failures() {
    static int failures = 0;
    return failures;
}

#define CHECK(expr)                                                         \
    do {                                                                    \
        if (!(expr)) {                                                      \
            std::cerr << __FILE__ << ':' << __LINE__                        \
                      << ": CHECK failed: " #expr "\n";                     \
            ++test_failures();                                              \
        }                                                                   \
    } while (false)

#define TEST_RESULT() (test_failures() == 0 ? EXIT_SUCCESS : EXIT_FAILURE)
