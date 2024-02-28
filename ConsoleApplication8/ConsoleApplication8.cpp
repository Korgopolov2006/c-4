#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::wstring word;
    int choice;
    do{
    std::wcout << L"Введите слово: ";
    std::wcin >> word;

    std::wcout << L"Выберите действие:" << std::endl;
    std::wcout << L"1. Слово выводится задом наперед" << std::endl;
    std::wcout << L"2. Вывести слово без гласных" << std::endl;
    std::wcout << L"3. Вывести слово без согласных" << std::endl;
    std::wcout << L"4. Рандомно раскидывать буквы заданного слова" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
        std::wstring reversedWord = word;
        std::reverse(reversedWord.begin(), reversedWord.end());
        std::wcout << L"Результат: " << reversedWord << std::endl;

    }
    else if (choice == 2) {
        std::wstring result = L"";
        for (wchar_t c : word) {
            if (c != L'а' && c != L'е' && c != L'ё' && c != L'и' && c != L'о' &&
                c != L'у' && c != L'ы' && c != L'э' && c != L'ю' && c != L'я' &&
                c != L'А' && c != L'Е' && c != L'Ё' && c != L'И' && c != L'О' &&
                c != L'У' && c != L'Ы' && c != L'Э' && c != L'Ю' && c != L'Я') {
                result += c;
            }
        }
        std::wcout << L"Результат: " << result << std::endl;
    }
    else if (choice == 3) {
        std::wstring result = L"";
        for (wchar_t c : word) {
            if (c == L'а' || c == L'е' || c == L'ё' || c == L'и' || c == L'о' ||
                c == L'у' || c == L'ы' || c == L'э' || c == L'ю' || c == L'я' ||
                c == L'А' || c == L'Е' || c == L'Ё' || c == L'И' || c == L'О' ||
                c == L'У' || c == L'Ы' || c == L'Э' || c == L'Ю' || c == L'Я') {
                result += c;
            }
        }
        std::wcout << L"Результат: " << result << std::endl;
    }
    else if (choice == 4) {
        std::wstring shuffledWord = word;
        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(shuffledWord.begin(), shuffledWord.end(), generator);
        std::wcout << L"Результат: " << shuffledWord << std::endl;

    }
    else {
        std::wcout << L"Некорректный выбор." << std::endl;
    }
    }while (true);
  
}
