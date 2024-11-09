#ifndef INSURANCEPOLICY_H
#define INSURANCEPOLICY_H

#include <iostream>
#include <string.h>

class InsurancePolicy {
    protected:
        std::string holder_name {};
        std::string policy_number {};    
        InsurancePolicy(std::string& name, std::string& number);

    public:
        virtual void displayInfo();
        void displayholderName();
        void changeholderName(std::string new_name);
        void changepolicyNumber(std::string new_number);
        std::string getholderName();
        std::string getpolicyNumber();

};

#endif