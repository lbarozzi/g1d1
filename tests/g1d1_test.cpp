#include <cstdlib>

#include "g1d1/g1d1.hpp"
#include "clinical/clinical.hpp"
#include "demographic/md.hpp"
#include "demographic/demographic.hpp"

int main() {
    if (g1d1::answer() != 42) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int test_demographic() {
    dg::MD md{"Leonardo","Barozzi","Torino","BRZLRDXXXXXXX","Proctologo"};
    
    dg::Demographic demographic;
    // Initialize md and demographic as needed

    return EXIT_SUCCESS;
}
