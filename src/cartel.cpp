#include "clinical/cartel.hpp"
#include <iostream>

clinicaldata::Cartel& clinicaldata::Cartel::operator+=(const Clinical& clinic){
    add(clinic);
    return *this;
}

void clinicaldata::Cartel::add(const Clinical& clinic){
    data_.push_back(clinic);
}

std::vector<clinicaldata::Clinical>& clinicaldata::Cartel::getAll() noexcept{
    return data_;
}

const std::vector<clinicaldata::Clinical>& clinicaldata::Cartel::getAll() const noexcept{
    return data_;
}

std::size_t clinicaldata::Cartel::size() const noexcept{
    return data_.size();
}

bool clinicaldata::Cartel::empty() const noexcept{
    return data_.empty();
}

clinicaldata::Clinical& clinicaldata::Cartel::operator[](std::size_t index){
    return data_[index];
}

const clinicaldata::Clinical& clinicaldata::Cartel::operator[](std::size_t index) const{
    return data_[index];
}

clinicaldata::Clinical& clinicaldata::Cartel::at(std::size_t index){
    return data_.at(index);
}

const clinicaldata::Clinical& clinicaldata::Cartel::at(std::size_t index) const{
    return data_.at(index);
}

void clinicaldata::Cartel::clear() noexcept{
    data_.clear();
}

dg::Demographic& clinicaldata::Cartel::getDemographic() noexcept{
    return patient_;
}

const dg::Demographic& clinicaldata::Cartel::getDemographic() const noexcept{
    return patient_;
}

clinicaldata::Cartel::~Cartel() {
    std::cout << "Destroying Cartel with size: " << data_.size() << '\n';
}