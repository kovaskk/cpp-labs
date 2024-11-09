#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Printer {

  std::string mark{};
  std::string paper_format{};
  double speed{};
  double price{};
};

int stringCounter(std::ifstream& fin) {

  int cnt{};
  std::string input;

  while (getline(fin, input)) {
    cnt++;
  }
  fin.clear();
  fin.seekg(0);
  return cnt;
}

void readFile(std::ifstream& fin, std::vector<Printer>& printers) {

  for (int indx = 0; indx < printers.size(); indx++) {
    fin >> printers[indx].mark >> printers[indx].paper_format >> printers[indx].speed >> printers[indx].price;
  }

}

int changeData(std::vector<Printer>& printers) {

    int indx{};
    std::cout << "Укажите номер принтера, данные которого хотите изменить: ";
    std::cin >> indx;

    if (indx > printers.size() || indx == 0) {
        std::cout << "Указанного принтера не существует! \n";
        return 0;
    }

    indx --;
    int choice{};
    do {
        std::cout << "\nУкажите номер параметра, который вы хотите изменить (вывод справочной информации - 5): ";
        std::cin  >> choice;

        switch (choice) {
            case 1:
                std::cout << "Введите новую марку: ";
                std::cin >> printers[indx].mark;
                std::cout << "Новая марка принтера: " << printers[indx].mark << "\n";
                break;
            case 2:
                std::cout << "Введите новый формат бумаги: ";
                std::cin >> printers[indx].paper_format;
                std::cout << "Новый формат бумаги: " << printers[indx].paper_format << "\n";
                break;
            case 3:
                std::cout << "Введите новую скорость печати: ";
                std::cin >> printers[indx].speed;
                std::cout << "Новая скорость принтера: " << printers[indx].speed << "\n";
                break;
            case 4:
                std::cout << "Введите новую цену принтера: ";
                std::cin >> printers[indx].price;
                std::cout << "Новая цена принтера: " << printers[indx].price << "\n";
                break;

            case 5:
                std::cout << "\nСписок доступных параметров: \n"
                          << "1. Марка принтера; \n"
                          << "2. Формат бумаги принтера; \n"
                          << "3. Скорость печати; \n"
                          << "4. Цена принтера; \n"
                          << "5. Вывести это сообщение.\n"
                          << "Чтобы выйти из режима редактирования, нажмите 6. \n";
                break;
            case 6:
                std::cout << "Выход из режима редактирования...\n";
                break;
            default:
                std::cout << "Неверно указан номер!\n";
                break;
        }
    } while (choice != 6);
    return 0;
}

void displayInfo (std::vector <Printer>& printers) {
    int cnt = 1;
    for (int indx = 0; indx < printers.size(); indx++) {
        std::cout << cnt << ". "
             << "Марка принтера: "     << printers[indx].mark
             << "; Формат бумаги: "   << printers[indx].paper_format
             << "; Скорость печати: " << printers[indx].speed
             << "; Цена принтера: "   << printers[indx].price
             << "\n";
        cnt++;
    }
}

void findlowCost(std::vector <Printer>& printers) {
    int min_cost{100000};
    int min_indx{};
    for (int i = 0; i < printers.size(); i++) {
        if (printers[i].price < min_cost) {
            min_cost = printers[i].price;
            min_indx = i;
        }
    }
    std::cout << "Самый дешёвый принтер с маркой: " << printers[min_indx].mark
              << ", его цена: "                     << printers[min_indx].price << "\n";
}

int writeFile(std::vector<Printer>& printers) {
    std::string filename;
    std::cout << "Введите название файла, куда будут записаны данные: ";
    std::cin >> filename;
    std::ofstream fout(filename);

    if (!fout) {
        std::cout << "Error while opening file!\n";
        return 0;
  }

    for (int i = 0; i < printers.size(); i++) {
        fout << printers[i].mark  << ' ' << printers[i].paper_format << ' '
            << printers[i].speed << ' ' << printers[i].price       << "\n";
    }

    std::cout << "Данные записаны успешно!\n";
    return 0;
}

void helpText() {

    std::cout << "Программа предназначена для работы с текстовыми файлами. \n"
              << "Список доступных команд: \n"
              << "1. Вывести текущие данные о принтерах; \n"
              << "2. Изменить данные о принтере; \n"
              << "3. Найти самый дешёвый принтер; \n"
              << "4. Осуществить запись данных в новый файл; \n"
              << "5. Вывод этой информационной справки; \n"
              << "6. Завершение работы программы; \n";
}

int main() {

  std::ifstream fin("input.txt");

  if (!fin) {
    std::cout << "Error while opening file!\n";
    return 0;
  }

  int str_cnt = stringCounter(fin);
  std::vector<Printer> printers(str_cnt);

  readFile(fin, printers);
  helpText();


  int choice;
  do {

    std::cout << "\nВведите команду: ";
    std::cin >> choice;

    switch (choice) {

            case 1:
                displayInfo(printers);
                break;

            case 2:
                changeData(printers);
                break;

            case 3:
                findlowCost(printers);
                break;

            case 4:
                writeFile(printers);
                break;

            case 5:
                helpText();
                break;

            case 6:
                std::cout << "Завершение работы...\n";
                break;

            default:
                std::cout << "Неверная команда!\n";
                break;
    }

  } while (choice != 6);

  return 0;
}

