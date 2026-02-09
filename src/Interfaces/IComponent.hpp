/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** IComponent
*/

#pragma once

#include <cstdint>

namespace nts {
    enum Tristate : int8_t {
        UNDEFINED = -true,
        FALSE     = false,
        TRUE      = true
    };

    class IComponent {
      public:
        virtual ~IComponent() = default;

        virtual void          simulate(std::size_t tick)                                        = 0;
        virtual nts::Tristate compute(std::size_t pin)                                          = 0;
        virtual void          setLink(std::size_t pin, IComponent& other, std::size_t otherPin) = 0;
    };
}
