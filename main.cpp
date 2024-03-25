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

// Функция для создания списка из данных, считанных из файла
Node* createListFromText(const MarkerText& text) {
    Node* head = nullptr; // Указатель на начало списка
    Node* tail = nullptr; // Указатель на конец списка

    for (int i = 0; i < text.length; ++i) {
        Node* newNode = new Node(text.strings[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Функция для удаления всех узлов с минимальным значением из списка
void deleteMinimumNodes(Node*& head) {
    // Проверка, что список не пустой
    if (!head) {
        std::cerr << "List is empty!" << std::endl;
        return;
    }

    int minVal = head->findMinimum();

    // Удаляем все узлы с минимальным значением из начала списка
    while (head && head->data.smallest_length() == minVal) {
        head = head->next;
    }

    // Удаляем все узлы с минимальным значением, кроме начального, из остальной части списка
    Node* current = head;
    while (current && current->next) {
        if (current->next->data.smallest_length() == minVal) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
}

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
    //output<<"Карпенко Анастасия\n";
    //output<<"3. Удалить:\n14) элементы, содержащие самые минимальные подэлементы (по длине слов);\n";
    MarkerText text = readTextFromFile(input);

    Node* head = createListFromText(text);
    deleteMinimumNodes(head);
    head->printListToFile(output);

    input.close();
    output.close();
}
