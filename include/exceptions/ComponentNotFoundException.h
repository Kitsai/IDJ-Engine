//
// Created by luck3 on 5/18/2024.
//

#ifndef IDJ_ENGINE_COMPONENTNOTFOUNDEXCEPTION_H
#define IDJ_ENGINE_COMPONENTNOTFOUNDEXCEPTION_H

#include <exception>
#include <string>

namespace fyrebird {
    class ComponentNotFoundException : public std::exception {
    private:
        std::string message;
    public:
        explicit ComponentNotFoundException(const std::string &type);

        [[nodiscard]] const char *what() const noexcept override;
    };
}

#endif //IDJ_ENGINE_COMPONENTNOTFOUNDEXCEPTION_H
