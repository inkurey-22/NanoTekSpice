/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** False
*/

#pragma once

#include "../../Abstracts/AComponent.hpp"

namespace nts {
    class False : public AComponent {
      public:
        False();
        void     simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    };
}
