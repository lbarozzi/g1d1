#pragma once
#include "demographic/demographic.hpp"

namespace dg {
    class MD : public Demographic {
    public:
        MD() = default;
        MD(const std::string& name, const std::string& surname, 
            const std::string& luogo_nascita, const std::string& codice_fiscale,
            const std::string& specialty)
            : Demographic(name, surname, luogo_nascita, codice_fiscale),
              specialty_(specialty) {}
        const std::string specialty() const;
        void set_specialty(const std::string& specialty);
        bool operator==(const MD& other) const;
        protected:
        std::string specialty_;

    };
} // namespace dg