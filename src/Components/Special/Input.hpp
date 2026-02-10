/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Input
*/

#pragma once

#include "../../Abstracts/AComponent.hpp"

namespace nts {
    class Input : public AComponent {
      public:
        Input();
        void     simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

        void     setValue(Tristate value);
        Tristate getValue() const;

      private:
        Tristate _value;
    };
}
