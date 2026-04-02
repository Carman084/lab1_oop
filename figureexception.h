#ifndef FIGUREEXCEPTION_H
#define FIGUREEXCEPTION_H

#include <exception>
#include <string>

class FigureException : public std::exception{
private:
    std::string message;
public:
    FigureException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};


#endif // FIGUREEXCEPTION_H
