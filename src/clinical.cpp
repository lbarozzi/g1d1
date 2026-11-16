#include "clinical/clinical.hpp"

namespace clinicaldata {

const std::string ClinicalType::clinical_type() const {
    return clinical_type_;
}

void ClinicalType::set_clinical_type(const std::string& clinical_type) {
    clinical_type_ = clinical_type;
}

const std::string& Clinical::clinical_data() const {
    return clinical_data_;
}

void Clinical::set_clinical_data(const std::string& clinical_data) {
    clinical_data_ = clinical_data;
}

const ClinicalType& Clinical::clinical_type() const {
    return clinical_type_;
}

void Clinical::set_clinical_type(const ClinicalType& clinical_type) {
    clinical_type_ = clinical_type;
}

const dg::MD& Clinical::md() const {
    return md_;
}

void Clinical::set_md(const dg::MD& md) {
    md_ = md;
}

const std::string& Clinical::timestamp() const {
    return timestamp_;
}

void Clinical::set_timestamp(const std::string& timestamp) {
    timestamp_ = timestamp;
}

const dg::Demographic& Clinical::demographic() const {
    return demographic_;
}

void Clinical::set_demographic(const dg::Demographic& demographic) {
    demographic_ = demographic;
}

} // namespace clinicaldata
