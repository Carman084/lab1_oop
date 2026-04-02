#ifndef MENU_H
#define MENU_H

#include <map>
#include "figure.h"
#include "printer.h"
#include <algorithm>
#include "solution.h"
#include <vector>

class Menu {
public:
    enum class Commands : int;
private:
    std::map<Commands, void (Menu::*)()> commands;
    std::vector<Figure*> figures;
    Solution& solver;
    void addFigure();
    void showParams();
    void showArea();
    void sumArea();
    void sortArea();
    void deleteByIndex();
    void deleteByArea();
    void exit();
public:
    Menu(Solution& solver) : solver(solver){
        initCommandsMap();
    }
    ~Menu();
    void initCommandsMap();
    void execute(Commands command);
    void run();
    enum class Commands{
        ADD_FIGURE = 1,
        SHOW_PARAMS,
        SHOW_AREA,
        SUM_AREA,
        SORT_AREA,
        DELETE_BY_INDEX,
        DELETE_BY_AREA,
        EXIT
    };
    static const int countFigure = 3;
};

#endif // MENU_H
