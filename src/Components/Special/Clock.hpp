/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Clock
*/

#pragma once

#include "../../Abstracts/AComponent.hpp"

namespace nts {
    class Clock : public AComponent {
      public:
        Clock();
        void     simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

        void     setValue(Tristate value);
        Tristate getValue() const;

      private:
        Tristate    _value;
        std::size_t _lastTick;
    };
}
