#include "MarkerText.h"
#include "Node.h"
#include <iostream>
#include <fstream>

// Конструктор для инициализации узла с заданными данными и указателем на следующий узел
Node::Node(const MarkerString& value) : data(value), next(nullptr) {}

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
void Node::printListToFile(const Node* head, std::ofstream& output) {
    const Node* current = head;
    while (current) {
        output << current->data.chars << std::endl;
        current = current->next;
    }
    output << std::endl;
}
