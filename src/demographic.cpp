#include "demographic/demographic.hpp"

namespace dg {

const std::string Demographic::nome() const {
    return name_;
}

const std::string Demographic::cognome() const {
    return surname_;
}

const std::string Demographic::luogo_nascita() const {
    return luogo_nascita_;
}

const std::string Demographic::codice_fiscale() const {
    return codice_fiscale_;
}

void Demographic::set_nome(const std::string& name) {
    name_ = name;
}

void Demographic::set_cognome(const std::string& surname) {
    surname_ = surname;
}

void Demographic::set_luogo_nascita(const std::string& luogo_nascita) {
    luogo_nascita_ = luogo_nascita;
}

void Demographic::set_codice_fiscale(const std::string& codice_fiscale) {
    codice_fiscale_ = codice_fiscale;
}

} // namespace dg