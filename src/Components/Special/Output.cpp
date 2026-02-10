/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Output
*/

#include "Output.hpp"

namespace nts {
    Output::Output() : AComponent(1), _value(UNDEFINED) {}

    void Output::simulate(std::size_t) {
        _value = getLinkValue(1);
    }

    Tristate Output::compute(std::size_t pin) {
        if (pin == 1) {
            return getLinkValue(1);
        }
        return UNDEFINED;
    }

    Tristate Output::getValue() const {
        return _value;
    }
}
