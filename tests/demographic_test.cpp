#include "check.hpp"
#include "demographic/demographic.hpp"

namespace {

void test_default_constructor() {
    const dg::Demographic d;
    CHECK(d.nome().empty());
    CHECK(d.cognome().empty());
    CHECK(d.luogo_nascita().empty());
    CHECK(d.codice_fiscale().empty());
}

void test_full_constructor() {
    const dg::Demographic d{"Mario", "Rossi", "Milano", "RSSMRA80A01F205X"};
    CHECK(d.nome() == "Mario");
    CHECK(d.cognome() == "Rossi");
    CHECK(d.luogo_nascita() == "Milano");
    CHECK(d.codice_fiscale() == "RSSMRA80A01F205X");
}

void test_setters() {
    dg::Demographic d;
    d.set_nome("Giulia");
    d.set_cognome("Bianchi");
    d.set_luogo_nascita("Roma");
    d.set_codice_fiscale("BNCGLI90B41H501Y");

    CHECK(d.nome() == "Giulia");
    CHECK(d.cognome() == "Bianchi");
    CHECK(d.luogo_nascita() == "Roma");
    CHECK(d.codice_fiscale() == "BNCGLI90B41H501Y");
}

void test_setter_overwrites_only_its_field() {
    dg::Demographic d{"Mario", "Rossi", "Milano", "RSSMRA80A01F205X"};
    d.set_nome("Luigi");

    CHECK(d.nome() == "Luigi");
    CHECK(d.cognome() == "Rossi");
    CHECK(d.luogo_nascita() == "Milano");
    CHECK(d.codice_fiscale() == "RSSMRA80A01F205X");
}

void test_copy_is_independent() {
    dg::Demographic original{"Mario", "Rossi", "Milano", "RSSMRA80A01F205X"};
    dg::Demographic copy = original;
    copy.set_cognome("Verdi");

    CHECK(original.cognome() == "Rossi");
    CHECK(copy.cognome() == "Verdi");
    CHECK(copy.nome() == "Mario");
}

void test_getter_returns_copy() {
    dg::Demographic d{"Mario", "Rossi", "Milano", "RSSMRA80A01F205X"};
    std::string nome = d.nome();
    nome = "Altro";
    CHECK(d.nome() == "Mario");
}

void test_equality() {
    const dg::Demographic a{"Mario", "Rossi", "Milano", "RSSMRA80A01F205X"};
    const dg::Demographic b{"Mario", "Rossi", "Milano", "RSSMRA80A01F205X"};
    CHECK(a == b);
    CHECK(!(a != b));
    CHECK(dg::Demographic{} == dg::Demographic{});

    CHECK(a != (dg::Demographic{"Luigi", "Rossi", "Milano", "RSSMRA80A01F205X"}));
    CHECK(a != (dg::Demographic{"Mario", "Verdi", "Milano", "RSSMRA80A01F205X"}));
    CHECK(a != (dg::Demographic{"Mario", "Rossi", "Roma", "RSSMRA80A01F205X"}));
    CHECK(a != (dg::Demographic{"Mario", "Rossi", "Milano", "XXXXXXXXXXXXXXXX"}));
}

} // namespace

int main() {
    test_equality();
    test_default_constructor();
    test_full_constructor();
    test_setters();
    test_setter_overwrites_only_its_field();
    test_copy_is_independent();
    test_getter_returns_copy();
    return TEST_RESULT();
}
