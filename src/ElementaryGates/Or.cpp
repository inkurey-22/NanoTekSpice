/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Or
*/

#include "Or.hpp"
#include "TristateLogic.hpp"

namespace nts {
    Or::Or() : AComponent(3) {}

    void     Or::simulate(std::size_t) {}

    Tristate Or::compute(std::size_t pin) {
        if (pin == 3) {
            return orGate(getLinkValue(1), getLinkValue(2));
        }
        if (pin == 1 || pin == 2) {
            return getLinkValue(pin);
        }
        return UNDEFINED;
    }
}
