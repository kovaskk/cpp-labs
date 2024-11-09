#include "MedicalInsurancePolicy.h"


MedicalInsurancePolicy::MedicalInsurancePolicy(std::string name, std::string number, std::string level)
                       : InsurancePolicy(name, number), insurance_level(level) {}

void MedicalInsurancePolicy::setInsuranceLevel(std::string level) {

    insurance_level = level;

}

void MedicalInsurancePolicy::displayholderName() {

    InsurancePolicy::displayholderName();

}

void MedicalInsurancePolicy::displayInsuranceLevel() {

    std::cout << "Уровень страхования: " << insurance_level << "\n";

}

void MedicalInsurancePolicy::displayInfo() {

    std::cout << "\n------------------Полис Медицинского Страхования------------------\n";
    InsurancePolicy::displayInfo();
    displayInsuranceLevel();
    std::cout << "------------------------------------------------------------------\n";
    
}
