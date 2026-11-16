#include <cstdlib>

#include "g1d1/g1d1.hpp"

int main() {
    if (g1d1::answer() != 42) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
