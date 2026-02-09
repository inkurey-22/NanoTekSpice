/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AndGate
*/

#include "And.hpp"
#include "TristateLogic.hpp"

namespace nts {
    And::And() : AComponent(3) {}

    void     And::simulate(std::size_t) {}

    Tristate And::compute(std::size_t pin) {
        if (pin == 3) {
            return andGate(getLinkValue(1), getLinkValue(2));
        }
        if (pin == 1 || pin == 2) {
            return getLinkValue(pin);
        }
        return UNDEFINED;
    }
}
