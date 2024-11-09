#include "HomeInsurancePolicy.h"


HomeInsurancePolicy::HomeInsurancePolicy(std::string name, std::string number, std::string object_name)
                       : InsurancePolicy(name, number), insurance_object(object_name) {}

void HomeInsurancePolicy::setObcjectName(std::string object_name) {

    insurance_object = object_name;

}

void HomeInsurancePolicy::displayholderName() {

    InsurancePolicy::displayholderName();

}

void HomeInsurancePolicy::displayInsuranceObject() {

    std::cout << "Объект страхования: " << insurance_object << "\n";

}

void HomeInsurancePolicy::displayInfo() {

    std::cout << "\n------------------Полис Жилищного Страхования---------------------\n";
    InsurancePolicy::displayInfo();
    displayInsuranceObject();
    std::cout << "------------------------------------------------------------------\n";
    
}
