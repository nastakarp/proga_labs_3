#include "MarkerText.h"

const char NULL_CHAR = '\0';

MarkerText::MarkerText() : strings(nullptr), length(0) {}

void MarkerText::print(std::ofstream &output) const {
    output << length << std::endl;
    for (int index = 0; index < length; ++index)
        strings[index].printBeforeMarker(output);
}

MarkerText::~MarkerText() {
    delete[] strings;
}
