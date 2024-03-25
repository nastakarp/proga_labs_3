#ifndef PROGA_LAB3_NODE_H
#define PROGA_LAB3_NODE_H

#include <iostream>
#include <fstream>

#include "MarkerString.h"
struct Node {
    MarkerString data; // Значение данных
    Node* next; // Указатель на следующий узел

    Node(const MarkerString &value);

    Node* createListFromText(MarkerText text);
    int findMinimum(const Node* head);
    void printListToFile(const Node* head, std::ofstream &output);
};

#endif //PROGA_LAB3_NODE_H
