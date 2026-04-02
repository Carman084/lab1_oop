#ifndef VALIDATIONEXCEPTION_H
#define VALIDATIONEXCEPTION_H

#include <exception>
#include <string>

class ValidationException : public std::exception{
private:
    std::string message;
public:
    ValidationException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // VALIDATIONEXCEPTION_H
