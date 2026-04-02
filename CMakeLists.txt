cmake_minimum_required(VERSION 3.16)

project(oop_lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(oop_lab1 main.cpp
    figure.h



    rectangle.h

    triangle.h

    printer.h
    printer.cpp



    menu.h
    menu.cpp
    point.h
    circle.h
    figurecreator.h


    rectanglecreator.h

    trianglecreator.h



    inputhandler.h
    validator.h
    circlecreator.h
    solution.h

    figuretypes.h
    validationexception.h
    figureexception.h
    creatorfactory.h
    app.h
)

include(GNUInstallDirs)
install(TARGETS oop_lab1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
