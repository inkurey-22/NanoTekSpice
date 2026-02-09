/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AComponent
*/

#pragma once

#include <vector>

#include "../Interfaces/IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
      public:
        explicit AComponent(std::size_t pinCount) : _links(pinCount + 1, {nullptr, 0}) {}

        void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override {
            if (!isValidPin(pin)) {
                return;
            }
            _links[pin] = {.other = &other, .otherPin = otherPin};
        }

      protected:
        struct Link {
            IComponent* other;
            std::size_t otherPin;
        };

        Tristate getLinkValue(std::size_t pin) {
            if (!isValidPin(pin)) {
                return UNDEFINED;
            }
            Link& link = _links[pin];
            if (link.other == nullptr) {
                return UNDEFINED;
            }
            return link.other->compute(link.otherPin);
        }

        bool isValidPin(std::size_t pin) const {
            return pin > 0 && pin < _links.size();
        }

      private:
        std::vector<Link> _links;
    };
}
