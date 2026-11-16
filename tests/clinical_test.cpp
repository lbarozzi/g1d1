#include "check.hpp"
#include "clinical/clinical.hpp"

namespace {

void test_clinical_type() {
    clinicaldata::ClinicalType type;
    type.set_clinical_type("Consultation");
    CHECK(type.clinical_type() == "Consultation");
}

void test_clinical_accessors() {
    clinicaldata::Clinical clinical;
    const clinicaldata::ClinicalType type{"Consultation"};
    const dg::MD physician{"Ada", "Lovelace", "London", "MD123", "Cardiology"};
    const dg::Demographic patient{"Grace", "Hopper", "New York", "GH123"};

    clinical.set_clinical_data("Notes");
    clinical.set_clinical_type(type);
    clinical.set_md(physician);
    clinical.set_timestamp("2026-11-16");
    clinical.set_demographic(patient);

    CHECK(clinical.clinical_data() == "Notes");
    CHECK(clinical.clinical_type().clinical_type() == "Consultation");
    CHECK(clinical.md().specialty() == "Cardiology");
    CHECK(clinical.timestamp() == "2026-11-16");
    CHECK(clinical.demographic().nome() == "Grace");
}

} // namespace

int main() {
    test_clinical_type();
    test_clinical_accessors();
    return TEST_RESULT();
}
