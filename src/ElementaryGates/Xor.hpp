/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** XOr
*/

#pragma once

#include "../Abstracts/AComponent.hpp"

namespace nts {
    class XOr : public AComponent {
      public:
        XOr();
        void     simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    };
}
