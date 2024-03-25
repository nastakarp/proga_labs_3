#ifndef PROGA_LAB3_NODE_H
#define PROGA_LAB3_NODE_H

#include <iostream>
#include <fstream>

#include "MarkerString.h"
struct Node {
    MarkerString data; // Значение данных
    Node* next; // Указатель на следующий узел

    Node(const MarkerString &value);

    int findMinimum();
    void printListToFile(std::ofstream &output);
    void printListToLog(std::ofstream& log);
};

#endif //PROGA_LAB3_NODE_H
