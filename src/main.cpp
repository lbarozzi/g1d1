#include <iostream>
#include <memory>

#include "g1d1/g1d1.hpp"
#include "clinical/cartel.hpp"    
#include "demographic/md.hpp"


int main() {
    /*/
    std::cout << g1d1::name << " says: "
              << g1d1::answer() << '\n';
    //*/

    dg::MD medico{"Leonardo","dr. Barozzi", "torino", "BRZlRDXXXXX","Cardiology"};
    dg::Demographic paziente{"Leonardo","Barozzi", "torino", "BRZlRDXXXXX"};
    auto cli1= std::make_unique<clinicaldata::Cartel>(paziente);

    for (int i=0;i<10;i++){
        auto car1=clinicaldata::Clinical();
            
        car1.set_demographic(paziente);
        car1.set_md(medico);
        car1.set_clinical_data("Cli data " + std::to_string(i));
        cli1->add(car1);
    }

    std::cout << "Cartel size: " << cli1->size() << '\n';
    for (const auto& clinical : cli1->getAll()) {
        std::cout << "Clinical data: " << clinical.clinical_data() << '\n';
    }   

}
