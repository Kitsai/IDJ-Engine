//
// Created by luck3 on 5/19/2024.
//

#ifndef IDJ_ENGINE_GAMENOTSTARTEDEXCEPTION_H
#define IDJ_ENGINE_GAMENOTSTARTEDEXCEPTION_H

#include <exception>
#include <string>

namespace fyrebird {
    class GameNotStartedException : public std::exception {
    public:
        GameNotStartedException();

        [[nodiscard]] const char *what() const noexcept override;
    };
}

#endif //IDJ_ENGINE_GAMENOTSTARTEDEXCEPTION_H
