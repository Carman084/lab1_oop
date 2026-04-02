#include "menu.h"

Menu::~Menu(){
    for (int i = 0; i < figures.size(); ++i)
        delete figures[i];
    commands.clear();
}

void Menu::run(){
    Commands command = Commands::ADD_FIGURE;
    do {
        Printer::outputMenu();
        try{
            int choice;
            std::cin >> choice;
            Validator::checkInput(std::cin.fail());
            Validator::checkChoice(choice, commands.size());
            command = static_cast<Commands>(choice);
            execute(command);
        }
        catch (const ValidationException& e){
            std::cout << e.what();
        }
    } while (command != Commands::EXIT);
}

void Menu::execute(Commands command){
    auto it = commands.find(command);
    if (it != commands.end())
        (this->*(it->second))();
}

void Menu::initCommandsMap(){
    commands[Commands::ADD_FIGURE] = &Menu::addFigure;
    commands[Commands::SHOW_PARAMS] = &Menu::showParams;
    commands[Commands::SHOW_AREA] = &Menu::showArea;
    commands[Commands::SUM_AREA] = &Menu::sumArea;
    commands[Commands::SORT_AREA] = &Menu::sortArea;
    commands[Commands::DELETE_BY_INDEX] = &Menu::deleteByIndex;
    commands[Commands::DELETE_BY_AREA] = &Menu::deleteByArea;
    commands[Commands::EXIT] = &Menu::exit;
}

void Menu::addFigure(){
    int choice;
    Printer::outputSubMenu();
    try{
        std::cin >> choice;
        Validator::checkInput(std::cin.fail());
        Validator::checkChoice(choice, static_cast<int>(countFigure));
        FigureType figure = static_cast<FigureType>(choice);
        Figure* f = solver.makeFigure(figure);
        figures.push_back(f);
        std::cout << "The figure has been added!\n";
    }
    catch (const FigureException& e){
        std::cout << e.what();
    }
    catch (const ValidationException& e){
        std::cout << e.what();
    }
}

void Menu::showParams(){
    Validator::checkEmptyVector(figures.empty());
    for (int i = 0; i < figures.size(); ++i){
        std::cout << i + 1 << ". " << figures[i]->getType() << " " << figures[i]->getName() << figures[i]->getParams();
        std::cout << "\n";
    }
}

void Menu::showArea(){
    Validator::checkEmptyVector(figures.empty());
    for (int i = 0; i < figures.size(); ++i){
        std::cout << i + 1 << ". " << figures[i]->getType()<< " " << figures[i]->getName()
        << ", area: " << figures[i]->getArea() << "\n";
    }
}

void Menu::sumArea(){
    double sum = 0;
    Validator::checkEmptyVector(figures.empty());
    for (int i = 0; i < figures.size(); ++i)
        sum += figures[i]->getArea();
    std::cout<< "The total area of all the figures: " << sum << "\n";
}

void Menu::sortArea(){
    Validator::checkEmptyVector(figures.empty());
    std::sort(figures.begin(), figures.end(), [](Figure* a, Figure* b){return a->getArea() < b->getArea();});
    std::cout << "The shapes are sorted by area \n";
}

void Menu::deleteByIndex(){
    Validator::checkEmptyVector(figures.empty());
    std::cout<<"Enter the figure number: ";
    int choice;
    std::cin >> choice;
    Validator::checkInput(std::cin.fail());
    Validator::checkDelFigure(choice < 1 || choice > figures.size());
    delete figures[choice - 1];
    figures.erase(figures.begin() + choice - 1);
    std::cout <<"The figure was deleted\n";
}

void Menu::deleteByArea(){
    Validator::checkEmptyVector(figures.empty());
    double area;
    std::cout<<"Enter the area: ";
    std::cin >> area;
    Validator::checkInput(std::cin.fail());
    Validator::checkArea(area);
    for (int i = 0; i < figures.size(); ){
        if (figures[i]->getArea() <= area)
            ++i;
        else{
            delete figures[i];
            figures.erase(figures.begin() + i);
        }
    }
    std::cout << "Figures are deleted\n";
}

void Menu::exit(){
    Printer::outputFinish();
}
