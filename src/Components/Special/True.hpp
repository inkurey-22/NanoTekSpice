/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** True
*/

#pragma once

#include "../../Abstracts/AComponent.hpp"

namespace nts {
    class True : public AComponent {
      public:
        True();
        void     simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    };
}
