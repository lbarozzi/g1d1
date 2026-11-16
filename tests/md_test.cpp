#include <type_traits>

#include "check.hpp"
#include "demographic/md.hpp"

static_assert(std::is_base_of_v<dg::Demographic, dg::MD>,
              "MD must derive from Demographic");

namespace {

void test_default_constructor() {
    const dg::MD md;
    CHECK(md.nome().empty());
    CHECK(md.cognome().empty());
    CHECK(md.luogo_nascita().empty());
    CHECK(md.codice_fiscale().empty());
    CHECK(md.specialty().empty());
}

void test_full_constructor() {
    const dg::MD md{"Leonardo", "Barozzi", "Torino", "BRZLRDXXXXXXX", "Proctologo"};
    CHECK(md.nome() == "Leonardo");
    CHECK(md.cognome() == "Barozzi");
    CHECK(md.luogo_nascita() == "Torino");
    CHECK(md.codice_fiscale() == "BRZLRDXXXXXXX");
    CHECK(md.specialty() == "Proctologo");
}

void test_set_specialty() {
    dg::MD md{"Leonardo", "Barozzi", "Torino", "BRZLRDXXXXXXX", "Proctologo"};
    md.set_specialty("Cardiologo");

    CHECK(md.specialty() == "Cardiologo");
    // Demographic fields are untouched
    CHECK(md.nome() == "Leonardo");
    CHECK(md.cognome() == "Barozzi");
}

void test_inherited_setters() {
    dg::MD md;
    md.set_nome("Anna");
    md.set_cognome("Neri");
    md.set_luogo_nascita("Napoli");
    md.set_codice_fiscale("NRENNA85C41F839Z");
    md.set_specialty("Neurologo");

    CHECK(md.nome() == "Anna");
    CHECK(md.cognome() == "Neri");
    CHECK(md.luogo_nascita() == "Napoli");
    CHECK(md.codice_fiscale() == "NRENNA85C41F839Z");
    CHECK(md.specialty() == "Neurologo");
}

void test_usable_as_demographic() {
    const dg::MD md{"Leonardo", "Barozzi", "Torino", "BRZLRDXXXXXXX", "Proctologo"};
    const dg::Demographic& as_base = md;
    CHECK(as_base.nome() == "Leonardo");
    CHECK(as_base.codice_fiscale() == "BRZLRDXXXXXXX");

    // Slicing copy keeps the demographic part
    const dg::Demographic sliced = md;
    CHECK(sliced.cognome() == "Barozzi");
    CHECK(sliced.luogo_nascita() == "Torino");
}

void test_copy_is_independent() {
    dg::MD original{"Leonardo", "Barozzi", "Torino", "BRZLRDXXXXXXX", "Proctologo"};
    dg::MD copy = original;
    copy.set_specialty("Ortopedico");
    copy.set_nome("Marco");

    CHECK(original.specialty() == "Proctologo");
    CHECK(original.nome() == "Leonardo");
    CHECK(copy.specialty() == "Ortopedico");
    CHECK(copy.nome() == "Marco");
}

} // namespace

int main() {
    test_default_constructor();
    test_full_constructor();
    test_set_specialty();
    test_inherited_setters();
    test_usable_as_demographic();
    test_copy_is_independent();
    return TEST_RESULT();
}
