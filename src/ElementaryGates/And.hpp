/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** And
*/

#pragma once

#include "../Abstracts/AComponent.hpp"

namespace nts {
    class And : public AComponent {
      public:
        And();
        void     simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    };
}
