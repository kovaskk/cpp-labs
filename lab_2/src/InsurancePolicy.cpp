#include "InsurancePolicy.h"

InsurancePolicy::InsurancePolicy(std::string& name, std::string& number) : holder_name(name), policy_number(number) {};

void InsurancePolicy::displayInfo() {
    std::cout << "Номер полиса: " << policy_number << '\n'
              << "Владелец полиса: " << holder_name << '\n';
    
}

void InsurancePolicy::displayholderName() {
    std::cout << "Владелец полиса: " << holder_name << '\n';
}

void InsurancePolicy::changeholderName(std::string new_name) {
    holder_name = new_name;
}

void InsurancePolicy::changepolicyNumber(std::string new_number) {
    policy_number = new_number;
}


