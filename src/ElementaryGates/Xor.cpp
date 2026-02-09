/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** XOr
*/

#include "Xor.hpp"
#include "TristateLogic.hpp"

namespace nts {
    XOr::XOr() : AComponent(3) {}

    void     XOr::simulate(std::size_t) {}

    Tristate XOr::compute(std::size_t pin) {
        if (pin == 3) {
            return xorGate(getLinkValue(1), getLinkValue(2));
        }
        if (pin == 1 || pin == 2) {
            return getLinkValue(pin);
        }
        return UNDEFINED;
    }
}
