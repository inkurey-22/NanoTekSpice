/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** TristateLogic
*/

#pragma once

#include "../Interfaces/IComponent.hpp"

namespace nts {
    inline Tristate andGate(Tristate lhs, Tristate rhs) {
        if (lhs == FALSE || rhs == FALSE) {
            return FALSE;
        }
        if (lhs == TRUE && rhs == TRUE) {
            return TRUE;
        }
        return UNDEFINED;
    }

    inline Tristate orGate(Tristate lhs, Tristate rhs) {
        if (lhs == TRUE || rhs == TRUE) {
            return TRUE;
        }
        if (lhs == FALSE && rhs == FALSE) {
            return FALSE;
        }
        return UNDEFINED;
    }

    inline Tristate xorGate(Tristate lhs, Tristate rhs) {
        if (lhs == UNDEFINED || rhs == UNDEFINED) {
            return UNDEFINED;
        }
        return (lhs != rhs) ? TRUE : FALSE;
    }

    inline Tristate notGate(Tristate value) {
        if (value == UNDEFINED) {
            return UNDEFINED;
        }
        return (value == TRUE) ? FALSE : TRUE;
    }
}
