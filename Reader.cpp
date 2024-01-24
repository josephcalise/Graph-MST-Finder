/*
Joseph Calise
ID#: 2380565
calise@chapman.edu
CPSC-350 Section 03
PA6: Spanning The Gamut
*/
#include "Reader.h"
#include <iostream>
#include <fstream>
#include <string>

Reader::Reader(){
    std::string input;
    int n;

}

Reader::~Reader(){
    
}

/*
importFile will intake a string of a file name and read said file it will intake the input file name as a string.
This will then delete the BEGIN and END lines since they are not needed for the processing.
The method will also keep track of how many lines it has parsed to pass to the member variable
for the program to know how many rows there are in the file.
The file also ignores the new lines it will store the values in a single line.
*/
void Reader::importFile(std::string input){
    std::string fileContent = "";
    std::fstream readingFile;
    readingFile.open(input, std::ios::in);
    if (readingFile.is_open()){
        std::string fileLine;
        while (std::getline(readingFile, fileLine)){
            if (fileLine == "BEGIN" || fileLine == "END"){
                continue;
            }
            fileContent += fileLine;
            fileContent += " ";
        }
        readingFile.close();
    }
    this->n = 0;
    this->n = (int)fileContent[0] - '0'; //https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
    fileContent.erase(0, 2);
    this->input = fileContent;
}


/*
processArrays will take the information calculated to size the correct arrays to hold our inputs.
This method will then place each of these values in the correct indexes in the 2D array.
The method will then parse through the chars of the input file and store each char until it reaches a space.

*/
double** Reader::processArrays(){
    int counter = 0;
    double** matrix = new double*[this->n]; 
    for (int i = 0; i < this->n; i++){
        matrix[i] = new double[this->n];
    }
    //Below is code that will store each char into a string until it reaches a space.
    //A space signals the end of a float and it will store those digits into the correct place in the array
    //and repeat until all values are placed.
    std::string current = "";
    int currentPlacementRow = 0;
    int currentPlacementValue = 0;
    for (char c : this->input){
        if (c != ' '){
            current+=c;
        }else{
            matrix[currentPlacementRow][currentPlacementValue] = std::stod(current);
            if (currentPlacementValue == this->n-1){ //This conditional checks if we are at the last value in the row.
                currentPlacementRow++; //This will tick the row counter to begin placing in the next row when first is filled.
                currentPlacementValue = 0;
            }else{
                currentPlacementValue++;
            }
            current.clear();
        }
    }

    
    return matrix;
}