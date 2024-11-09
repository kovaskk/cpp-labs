#include <iostream>
#include <vector>
#include <string.h>
#include "MedicalInsurancePolicy.h"
#include "HomeInsurancePolicy.h"
#include "InsurancePolicy.h"

void displayMenu() {
    std::cout << "\nВыберите дейсвтие для выполнения: " << "\n"
              << "1. Внести данные о новом полисе; " << "\n"
              << "2. Вывести информацию о полисе по номеру;" << "\n"
              << "3. Изменить параметры полиса;" << "\n"
              << "4. Вычислить количество полисов по фамилии; " << "\n"
              << "5. Вывод всех полисов; " << "\n"
              << "6. Завершить работу программы." << "\n";
}

void createPolicy(std::vector <InsurancePolicy*>& policies) {
    std::string name{};
    std::string number{};
    std::string level{};

    char choice {};
    std::cout << "\nДоступно 2 вида полиса: 1 - полис медицинского страхования; "
              << "2 - полис жилищного страхования" << "\n"
              << "\nВведите тип полиса, который вы хотите создать: ";
    std::cin >> choice;
    std::cin.ignore();
    
    std::cout << "Введите Ваше имя и фамилию: ";
    std::getline(std::cin, name);

    std::cout << "Введите номер полиса: ";
    std::getline(std::cin, number);
    
    switch (choice)
    {
    case '1':
    {
        std::string level;
        std::cout << "Введите уровень страхования: ";
        std::getline(std::cin, level);
        policies.push_back(new MedicalInsurancePolicy(name, number, level));
        break;
    }

    case '2':
    {
        std::string object_name;
        std::cout << "Введите имущество для страхования: ";
        std::getline(std::cin, object_name);
        policies.push_back(new HomeInsurancePolicy(name, number, object_name));
        break;
    }

    default:
        std::cout << "\nВы ввели недопустимый параметр!";
        break;
    }   

}

void displayPolicy(std::vector<InsurancePolicy*>& policies, std::string number) {

    bool check_flag = false;

    for (auto policy : policies) {
        if (policy->policy_number == number) {
            policy->displayInfo();
            check_flag = true;
        }
    }

    if (check_flag == false) {
        std::cout << "По указанному номеру полис не найден!";
    }

}

void displayAll(std::vector <InsurancePolicy*>& policies) {
    
    for (int i = 0; i < policies.size(); i++) {
        policies[i]->displayInfo();
    }

}

void changeParams(std::vector <InsurancePolicy*>& policies) {

    int index{};

    std::cout << "\nВведите порядковый номер полиса, параметр которого хотели бы изменить: ";
    std::cin >> index;
    index -= 1 ;

    if (index != 0 && dynamic_cast<MedicalInsurancePolicy*>(policies[index])) {

        MedicalInsurancePolicy* medpol = dynamic_cast<MedicalInsurancePolicy*>(policies[index]);
        
        std::cout << "\nДоступные параметры для изменения: " << "\n"
                  << "1 - Владелец полиса" << "\n"
                  << "2 - Номер полиса" << "\n"
                  << "3 - Уровень страхования" << "\n" ;
        
        char choice{};

        std::cout << "Введите параметр, который хотите изменить: ";
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {

            case '1':
            {
                std::string new_name{};
                std::cout << "Введите нового владельца: ";
                std::getline(std::cin, new_name);
                policies[index]->changeholderName(new_name);
                break;
            }
            case '2':
            {
                std::string new_number{};
                std::cout << "Введите новый номер полиса: ";
                std::getline(std::cin, new_number);
                policies[index]->changepolicyNumber(new_number);
                break;
            }
            case '3':
            {
                std::string new_level{};
                std::cout << "Введите новый уровень страхования: ";
                std::getline(std::cin, new_level);
                medpol->setInsuranceLevel(new_level);
                break;
            }

        }
    }

    if (index != 0 && dynamic_cast<HomeInsurancePolicy*>(policies[index])) {

        HomeInsurancePolicy* homepol = dynamic_cast<HomeInsurancePolicy*>(policies[index]);
        
        std::cout << "\nДоступные параметры для изменения: " << "\n"
                  << "1 - Владелец полиса" << "\n"
                  << "2 - Номер полиса" << "\n"
                  << "3 - Объект страхования" << "\n" ;
        
        char choice{};

        std::cout << "\nВведите параметр, который хотите изменить: ";
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {

            case '1':
            {
                std::string new_name{};
                std::cout << "\nВведите нового владельца: ";
                std::getline(std::cin, new_name);
                policies[index]->changeholderName(new_name);
                break;
            }

            case '2':
            {
                std::string new_number{};
                std::cout << "\nВведите новый номер полиса: ";
                std::getline(std::cin, new_number);
                policies[index]->changepolicyNumber(new_number);
                break;
            }

            case '3':
            {
                std::string new_name{};
                std::cout << "\nВведите новый объект страхования: ";
                std::getline(std::cin, new_name);
                homepol->setObcjectName(new_name);
                break;
            }
            
            default:
                std::cout << "Введено неверное значение!\n";
        }
    }
}

int performAction(std::vector <InsurancePolicy*>& policies, std::string surname) {
    int count {};

    for (int index = 0; index < policies.size(); index++) {
        if (policies[index]->holder_name.find(surname)) {
            count += 1;
        }
    } return count;
}



int main() {

    std::vector <InsurancePolicy*> policies;

    std::cout << "Данная программа реализует систему управления страховыми полисами.";

    char choice{};

    do {
        displayMenu();

        
        std::cout << "\nВведите действие, которое хотите выполнить: ";
        std::cin >> choice;

        switch(choice) {

            case '1':
                createPolicy(policies);
                break;
            
            case '2':
            {
                std::string number{};
                
                std::cout << "\nВведите номер полиса, который хотите вывести: ";
                std::cin >> number;

                displayPolicy(policies, number);
                break;
            }

            case '3':
                changeParams(policies);
                break;

            case '4':
            {
                std::string surname;

                std::cout << "\nВведите фамилию, по которой будет осуществляться поиск: ";
                std::cin >> surname;

                std::cout << "Количество полисов с фамилией " << surname << " равно: " << performAction(policies, surname) << ".\n";
                break;
            }
            
            case '5':
                std::cout << "\nВсе имеющиеся полисы: \n";
                displayAll(policies);
                break;

            case '6':
                std::cout << "Завершение работы...\n";
                break;

            default:
                std::cout << "Введено неверное значение!\n";
                break;
                
        }
    } while (choice != '6');

    return 0;

} 