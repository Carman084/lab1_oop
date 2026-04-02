#include "printer.h"

void Printer::outputMenu(){
    std::cout << "=========== MAIN MENU ===========\n";
    std::cout << "1. Add a figure\n";
    std::cout << "2. Output a list of figures with parameters\n";
    std::cout << "3. Output a numbered list of figures with the type of figure and its area\n";
    std::cout << "4. Print the sum of the areas of all figures\n";
    std::cout << "5. Sort the figures in the collection in ascending order of area\n";
    std::cout << "6. Delete a figure from the collection by its number\n";
    std::cout << "7. Delete figures whose area is larger than the entered value\n";
    std::cout << "8. Exit\n";
    std::cout << "Select an item: ";
}

void Printer::outputSubMenu(){
    std::cout << "Select a figure to add:\n1. Circle\n2. Rectangle \n3. Triangle\nSelect a point: ";
}

void Printer::outputFinish(){
    std::cout << "The program was completed successfully";
}
