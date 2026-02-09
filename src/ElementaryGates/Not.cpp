/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Not
*/

#include "Not.hpp"
#include "TristateLogic.hpp"

namespace nts {
    Not::Not() : AComponent(2) {}

    void     Not::simulate(std::size_t) {}

    Tristate Not::compute(std::size_t pin) {
        if (pin == 2) {
            return notGate(getLinkValue(1));
        }
        if (pin == 1) {
            return getLinkValue(1);
        }
        return UNDEFINED;
    }
}
