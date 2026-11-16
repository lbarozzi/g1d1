#include "demographic/md.hpp"

namespace dg {

const std::string MD::specialty() const {
    return specialty_;
}

void MD::set_specialty(const std::string& specialty) {
    specialty_ = specialty;
}

} // namespace dg