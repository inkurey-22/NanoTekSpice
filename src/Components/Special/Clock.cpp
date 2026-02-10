/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Clock
*/

#include "Clock.hpp"
#include "../../ElementaryGates/TristateLogic.hpp"

namespace nts {
    Clock::Clock() : AComponent(1), _value(UNDEFINED), _lastTick(0) {}

    void Clock::simulate(std::size_t tick) {
        if (tick == _lastTick) {
            return;
        }
        _lastTick = tick;
        if (_value == UNDEFINED) {
            return;
        }
        _value = notGate(_value);
    }

    Tristate Clock::compute(std::size_t pin) {
        if (pin == 1) {
            return _value;
        }
        return UNDEFINED;
    }

    void Clock::setValue(Tristate value) {
        _value = value;
    }

    Tristate Clock::getValue() const {
        return _value;
    }
}
