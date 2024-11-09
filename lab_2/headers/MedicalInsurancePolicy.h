#ifndef MEDICALINSURANCEPOLICY_H
#define MEDICALINSURANCEPOLICY_H

#include "InsurancePolicy.h"

#include <iostream>
#include <string.h>

class MedicalInsurancePolicy : public InsurancePolicy {

    protected:
        std::string insurance_level;

    public: 
        MedicalInsurancePolicy(std::string name, std::string number, std::string level);
        
        void setInsuranceLevel(std::string level);
        void displayInsuranceLevel();
        void displayholderName();
        void displayInfo() override;


};

#endif