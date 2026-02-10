/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Output
*/

#pragma once

#include "../../Abstracts/AComponent.hpp"

namespace nts {
    class Output : public AComponent {
      public:
        Output();
        void     simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;

        Tristate getValue() const;

      private:
        Tristate _value;
    };
}
