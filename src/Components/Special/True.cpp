/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** True
*/

#include "True.hpp"

namespace nts {
    True::True() : AComponent(1) {}

    void     True::simulate(std::size_t) {}

    Tristate True::compute(std::size_t pin) {
        if (pin == 1) {
            return TRUE;
        }
        return UNDEFINED;
    }
}
