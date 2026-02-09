/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Or
*/

#pragma once

#include "../Abstracts/AComponent.hpp"

namespace nts {
    class Or : public AComponent {
      public:
        Or();
        void     simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    };
}
