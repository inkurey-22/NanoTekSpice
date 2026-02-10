/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** False
*/

#include "False.hpp"

namespace nts {
    False::False() : AComponent(1) {}

    void     False::simulate(std::size_t) {}

    Tristate False::compute(std::size_t pin) {
        if (pin == 1) {
            return FALSE;
        }
        return UNDEFINED;
    }
}
