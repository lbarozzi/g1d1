#pragma once

#include <cstddef>
#include <vector>

#include "clinical/clinical.hpp"
#include "demographic/demographic.hpp"

namespace clinicaldata {
    class Cartel {
    public:
        Cartel() = default;
        explicit Cartel(const dg::Demographic& patient) : patient_(patient) {}
        ~Cartel();

        Cartel& operator+=(const Clinical& clinic);

        void add(const Clinical& clinic);
        std::vector<Clinical>& getAll() noexcept;
        const std::vector<Clinical>& getAll() const noexcept;
        std::size_t size() const noexcept;
        bool empty() const noexcept;
        Clinical& operator[](std::size_t index);
        const Clinical& operator[](std::size_t index) const;
        Clinical& at(std::size_t index);
        const Clinical& at(std::size_t index) const;
        void clear() noexcept;
        dg::Demographic& getDemographic() noexcept;
        const dg::Demographic& getDemographic() const noexcept;

    private:
        std::vector<Clinical> data_;
        dg::Demographic patient_;
    };

} // namespace clinicaldata