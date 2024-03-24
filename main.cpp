#include <iostream>
#include <fstream>

using namespace std;

const int MAX_LENGTH = 512;

#include "MarkerString.h"
#include "MarkerText.h"
#include "Node.h"



MarkerText readTextFromFile(fstream &input) {
    char marker;
    input.get(marker);

    int length = 0;
    auto *strings = new MarkerString[MAX_LENGTH];

    char symbol;
    input.get(symbol);
    while (input.get(symbol)) {
        int index = 0;
        char *chars = new char[MAX_LENGTH];
        chars[index++] = symbol;
        while (input.get(symbol) && symbol != '\n') chars[index++] = symbol;
        chars[index] = '\0';
        strings[length].chars = chars;
        strings[length].marker = marker;
        length++;
    }

    MarkerText text = MarkerText();
    text.strings = new MarkerString[length];
    text.length = length;

    for (int index = 0; index < length; ++index) {
        text.strings[index] = strings[index];
    }

    return text;
}
// Определение класса для узла списка


int main() {
    fstream input("input.txt", ios::in);
    ofstream output("output.txt", ios::out);

    if (!input.is_open()) {
        output << "Не удалось открыть файл input.txt" << endl;
        throw std::runtime_error("Ошибка открытия файла");
    }
    if (input.peek() == std::ifstream::traits_type::eof()) {
        output << "Файл input.txt пуст" << std::endl;
        throw std::runtime_error("Входной файл пуст");
    }
    output<<"Карпенко Анастасия\n";
    output<<"3. Удалить:\n14) элементы, содержащие самые минимальные подэлементы (по длине слов);\n";
    MarkerText text = readTextFromFile(input);
    Node* head = Node createListFromText(text);
    Node printListToFile(head, output);

    input.close();
    output.close();
}
