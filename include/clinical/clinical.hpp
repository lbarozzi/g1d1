#pragma once
#include <string>
#include "demographic/md.hpp"

namespace clinicaldata {
    class ClinicalType{
        public:
            ClinicalType() = default;
            ClinicalType(const std::string& clinical_type)
                : clinical_type_(clinical_type) {}
            const std::string clinical_type() const;
            void set_clinical_type(const std::string& clinical_type);
        protected:
            std::string clinical_type_;
    };

    class Clinical{
        public:
            //linical() = default;
            Clinical(const std::string& clinical_data,
                     const ClinicalType& clinical_type,
                     const dg::MD& md,
                     const std::string& timestamp,
                     const dg::Demographic& demographic)
                : clinical_data_(clinical_data),
                  clinical_type_(clinical_type),
                  md_(md),
                  timestamp_(timestamp),
                  demographic_(demographic) {}

            Clinical(const Clinical& Clinical) = delete;
            
            const std::string& clinical_data() const;
            void set_clinical_data(const std::string& clinical_data);

            const ClinicalType& clinical_type() const;
            void set_clinical_type(const ClinicalType& clinical_type);

            const dg::MD& md() const;
            void set_md(const dg::MD& md);

            const std::string& timestamp() const;
            void set_timestamp(const std::string& timestamp);

            const dg::Demographic& demographic() const;
            void set_demographic(const dg::Demographic& demographic);

        protected:
            std::string clinical_data_;
            ClinicalType clinical_type_;
            dg::MD md_;
            std::string timestamp_;
            dg::Demographic demographic_;
    };
} // namespace clinicaldata