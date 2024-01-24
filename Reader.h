/*
Joseph Calise
ID#: 2380565
calise@chapman.edu
CPSC-350 Section 03
PA6: Spanning The Gamut
*/
#ifndef READER_H
#define  READER_H
#include <string>


class Reader{
    private:

    public:
    std::string input;
    int n;
    Reader();
    ~Reader();
    void importFile(std::string input);
    double** processArrays();
};

#endif