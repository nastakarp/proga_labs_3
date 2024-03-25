#include "MarkerText.h"
#include "Node.h"
#include <iostream>
#include <fstream>

// Конструктор для инициализации узла с заданными данными и указателем на следующий узел
Node::Node(const MarkerString& value) : data(value), next(nullptr) {}

int Node::findMinimum(const Node* head) {
    // Проверка, что список не пустой
    if (!head) {
        std::cerr << "List is empty!" << std::endl;
        return -1; // Возвращаем отрицательное значение, чтобы обозначить ошибку
    }

    int minVal = head->data.smallest_length(); // Первый элемент списка как начальное минимальное значение

    // Проходим по остальным элементам списка, обновляя минимальное значение
    const Node* current = head->next; // Начинаем со второго элемента
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
