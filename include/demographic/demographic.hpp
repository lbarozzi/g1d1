#pragma once
#include <string>

namespace dg {
    class Demographic {
        public:
        Demographic() = default;
        Demographic(const std::string& name, const std::string& surname, 
            const std::string& luogo_nascita, const std::string& codice_fiscale)
            : name_(name), surname_(surname), luogo_nascita_(luogo_nascita),
             codice_fiscale_(codice_fiscale) {}
        const std::string nome() const;
        const std::string cognome() const;
        const std::string luogo_nascita()const ;
        const std::string codice_fiscale() const;
        void set_nome(const std::string& name);
        void set_cognome(const std::string& surname);
        void set_luogo_nascita(const std::string& luogo_nascita);
        void set_codice_fiscale(const std::string& codice_fiscale);
    protected:
        std::string name_;
        std::string surname_;
        std::string luogo_nascita_;
        std::string codice_fiscale_;
    };
} // namespace dg