#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "");

    int choice;
    std::string word;
    std::string consonants = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    std::string vowels = "аеёиоуыэюяАЕЁИОУЫЭЮЯ";

    std::cout << "Введите слово: ";
    std::getline(std::cin, word);

    std::cout << "Меню операций: \n";
    std::cout << "1. Слово выводится задом наперед\n";
    std::cout << "2. Вывести слово без гласных\n";
    std::cout << "3. Вывести слово без согласных\n";
    std::cout << "4. Рандомно раскидывать буквы заданного слова\n";
    std::cout << "Выберите опцию: ";
    std::cin >> choice;

    std::cin.ignore();

    std::string result;

    switch (choice) {
    case 1:
        result = word;
        std::reverse(result.begin(), result.end());
        std::cout << "Ответ: " << result << std::endl;
        break;
    case 2:
        result = "";
        for (char c : word) {
            if (vowels.find(c) == std::string::npos) {
                result += c;
            }
        }
        std::cout << "Ответ: " << result << std::endl;
        break;
    case 3:
        result = "";
        for (char c : word) {
            if (consonants.find(c) == std::string::npos) {
                result += c;
            }
        }
        std::cout << "Ответ: " << result << std::endl;
        break;
    case 4:
        result = word;
        std::srand(std::time(0));
        std::random_shuffle(result.begin(), result.end());
        std::cout << "Ответ: " << result << std::endl;
        break;
    default:
        std::cout << "Вы сделали неверный выбор" << std::endl;
        break;
    }

    return 0;
}
