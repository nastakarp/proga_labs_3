#ifndef MARKER_STRING_H
#define MARKER_STRING_H

#include <fstream>

struct MarkerString {
    char *chars;
    char marker;

    MarkerString();
    MarkerString(const char* chars, char marker);
    int longest_length() const;
    int smallest_length() const;
    void printBeforeMarker(std::ofstream &output) const;
    ~MarkerString();
};

#endif  // MARKER_STRING_H
