#ifndef HOMEINSURANCEPOLICY_H
#define HOMEINSURANCEPOLICY_H


#include "InsurancePolicy.h"
#include <iostream>
#include <string.h>

class HomeInsurancePolicy : public InsurancePolicy {
    protected:
        std::string insurance_object;

    public:
        HomeInsurancePolicy(std::string name, std::string number, std::string object_name);

        void setObcjectName(std::string object_name);
        void displayInfo() override;
        void displayholderName();
        void displayInsuranceObject();

};

#endif