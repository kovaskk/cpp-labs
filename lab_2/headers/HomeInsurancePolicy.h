#ifndef HOMEINSURANCEPOLICY_H
#define HOMEINSURANCEPOLICY_H


#include "InsurancePolicy.h"
#include <iostream>
#include <string.h>

class HomeInsurancePolicy : public InsurancePolicy {
    public:
        std::string insurance_level;
        std::string insurance_object;

        HomeInsurancePolicy(std::string name, std::string number, std::string object_name);

        void setObcjectName(std::string object_name);
        void displayInfo() override;
        void displayholderName();
        void displayInsuranceObject();

};

#endif