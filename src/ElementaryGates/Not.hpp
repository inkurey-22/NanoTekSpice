/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Not
*/

#pragma once

#include "../Abstracts/AComponent.hpp"

namespace nts {
    class Not : public AComponent {
      public:
        Not();
        void     simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    };
}
