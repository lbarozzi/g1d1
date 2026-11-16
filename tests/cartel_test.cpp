#include "check.hpp"
#include "clinical/cartel.hpp"

namespace {

clinicaldata::Clinical make_clinical(const dg::Demographic& patient) {
    const clinicaldata::ClinicalType type{"Consultation"};
    const dg::MD physician{"Ada", "Lovelace", "London", "MD123", "Cardiology"};
    return {"Notes", type, physician, "2026-11-16", patient};
}

void test_default_constructor_and_add() {
    clinicaldata::Cartel cartel;
    const dg::Demographic patient{"Grace", "Hopper", "New York", "GH123"};
    const clinicaldata::Clinical clinical = make_clinical(patient);

    CHECK(cartel.empty());
    cartel.add(clinical);
    CHECK(cartel.size() == 1);
    CHECK(!cartel.empty());
    CHECK(&cartel.at(0) != &clinical);
}

void test_append_and_clear() {
    const dg::Demographic patient{"Grace", "Hopper", "New York", "GH123"};
    const clinicaldata::Clinical clinical = make_clinical(patient);
    clinicaldata::Cartel cartel{patient};

    cartel += clinical;
    cartel += clinical;
    CHECK(cartel.size() == 2);
    CHECK(cartel.getAll().size() == 2);
    CHECK(&cartel[1] == &cartel.getAll()[1]);
    CHECK(cartel.getDemographic().nome() == "Grace");

    cartel.clear();
    CHECK(cartel.empty());
}

void test_const_access() {
    const dg::Demographic patient{"Grace", "Hopper", "New York", "GH123"};
    const clinicaldata::Clinical clinical = make_clinical(patient);
    clinicaldata::Cartel mutable_cartel{patient};
    mutable_cartel.add(clinical);
    const clinicaldata::Cartel& cartel = mutable_cartel;

    CHECK(cartel.getAll().size() == 1);
    CHECK(&cartel.at(0) == &cartel.getAll()[0]);
}

} // namespace

int main() {
    test_default_constructor_and_add();
    test_append_and_clear();
    test_const_access();
    return TEST_RESULT();
}
