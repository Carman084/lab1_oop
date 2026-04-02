#ifndef APP_H
#define APP_H

#include "menu.h"

class App {
private:
    CreatorFactory* factory;
    InputHandler* inputHandler;
    Solution* solution;
    Menu* menu;
    CreatorFactory* createFactory() {
        CreatorFactory* currentFactory = factory;
        if (!currentFactory)
            currentFactory = new CreatorFactory();
        return currentFactory;
    }

    InputHandler* createInputHandler() {
        InputHandler* currentInputHandler = inputHandler;
        if (!currentInputHandler)
            currentInputHandler = new InputHandler();
        return currentInputHandler;
    }

    Solution* createSolution(CreatorFactory* factory, InputHandler* inputHandler) {
        return new Solution(*factory, *inputHandler);
    }

    Menu* createMenu(Solution* solution) {
        return new Menu(*solution);
    }
public:
    App(){
        menu = createMenu(createSolution(createFactory(), createInputHandler()));
    }
    ~App() {
        delete menu;
        delete solution;
        delete inputHandler;
        delete factory;
    }
    void run(){
        menu->run();
    }
};

#endif // APP_H
