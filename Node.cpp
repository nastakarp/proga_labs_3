#include "MarkerText.h"
#include "Node.h"
#include <iostream>
#include <fstream>

// Конструктор для инициализации узла с заданными данными и указателем на следующий узел
Node::Node(const MarkerString& value) : data(value), next(nullptr) {}

int Node::findMinimum() {
    // Проверка, что список не пустой
    if (this == nullptr) {
        std::cerr << "List is empty!" << std::endl;
        return -1; // Возвращаем отрицательное значение, чтобы обозначить ошибку
    }

    int minVal = this->data.smallest_length(); // Первый элемент списка как начальное минимальное значение

    // Проходим по остальным элементам списка, обновляя минимальное значение
    const Node* current = this->next; // Начинаем со второго элемента
    while (current) {
        int currentSmallestLength = current->data.smallest_length(); // Получаем длину самого короткого слова текущего узла
        if (currentSmallestLength < minVal) {
            minVal = currentSmallestLength;
        }
        current = current->next;
    }

    return minVal;
}

// Функция для вывода списка в файл
void Node::printListToFile(std::ofstream& output) {
    const Node* current = this;
    while (current) {
        output << current->data.chars << std::endl;
        current = current->next;
    }
    output << std::endl;
}
// Функция для вывода списка в файл
void Node::printListToLog(std::ofstream& log) {
    const Node* current = this;
    log<<"Head\n"
        <<" | " << "\n"
        <<"\\|/ " << "\n";

    while (current) {

        log << current->data.chars << std::endl;
        log<<" | \n"<<"\\|/ " << "\n";
        current = current->next;
    }
    log <<"nullptr" << "\n";
}
