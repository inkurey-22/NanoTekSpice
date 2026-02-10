/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Input
*/

#include "Input.hpp"

namespace nts {
    Input::Input() : AComponent(1), _value(UNDEFINED) {}

    void     Input::simulate(std::size_t) {}

    Tristate Input::compute(std::size_t pin) {
        if (pin == 1) {
            return _value;
        }
        return UNDEFINED;
    }

    void Input::setValue(Tristate value) {
        _value = value;
    }

    Tristate Input::getValue() const {
        return _value;
    }
}
