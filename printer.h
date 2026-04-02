#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>

class Printer{
public:
    Printer() = delete;
    static void outputMenu();
    static void outputSubMenu();
    static void outputFinish();
};

#endif // PRINTER_H
