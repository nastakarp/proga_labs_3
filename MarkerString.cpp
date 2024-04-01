#include "MarkerString.h"

const char NULL_CHAR = '\0';

MarkerString::MarkerString() : chars(nullptr), marker(NULL_CHAR) {}

MarkerString::MarkerString(const char* chars, char marker) {
    int length = 0;
    while (chars[length++] != NULL_CHAR) {}

    this->chars = new char[length + 1];
    for (int index = 0; index < length + 1; ++index) {
        this->chars[index] = chars[index];
    }

    this->marker = marker;
}


int MarkerString::smallest_length() const {
    int result = 512; // Начальное значение
    int current = 0;

    int index = 0;
    while (this->chars[index] != marker && this->chars[index] != '\0') {
        if (this->chars[index] == ' ') {
            // Если найдено пробельное разделение, обновляем результат, если длина текущего слова меньше
            if (current < result) {
                result = current;
            }
            current = 0; // Сбрасываем текущую длину слова для следующего слова
        } else {
            current++; // Увеличиваем длину текущего слова
        }
        index++;
    }
    // Проверяем длину последнего слова после выхода из цикла
    if (current > 0 && current < result) {
        result = current;
    }
    return result;
}

void MarkerString::printBeforeMarker(std::ofstream &output) const {
    int index = 0;
    while (chars[index] != NULL_CHAR && chars[index] != marker) output << chars[index++];
    output << std::endl;
}

MarkerString::~MarkerString() {
    delete[] chars;
}
