#pragma once

#include <array>

namespace Input
{
    const int Space = 0;
    const int D = 1;
    const int R = 2;
    const int L = 3;
    const int S = 4;

    extern std::array<bool, 5> PressedKeys;
}
