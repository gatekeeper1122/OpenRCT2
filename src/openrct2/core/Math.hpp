#pragma region Copyright (c) 2014-2017 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#pragma once

#include <algorithm>

/**
 * Common mathematical functions.
 */
namespace Math
{
    template<typename T>
    static T Min(T a, T b)
    {
        return (std::min)(a, b);
    }
    // vita has 16bit int, fucks up templates using sint32 for /some/ of
    // the args, we'll just keep adding these until we find them all.pp
    // nicer solution than fixing the code itself
#ifdef __vita__
    static long int Min(int a, long int b)
    {
        return (std::min)((long int)a, b);
    }

    static long int Min(long int a, int b)
    {
        return (std::min)(a, (long int)b);
    }
#endif

    template<typename T>
    static T Max(T a, T b)
    {
        return (std::max)(a, b);
    }
#ifdef __vita__
    static long int Max(int a, long int b)
    {
        return (std::max)((long int)a, b);
    }

    static long int Max(long int a, int b)
    {
        return (std::max)(a, (long int)b);
    }
#endif

    template<typename T>
    static T Clamp(T low, T x, T high)
    {
        return (std::min)((std::max)(low, x), high);
    }

#ifdef __vita__
    static long int Clamp(int low, long int x, int high)
    {
        return (std::min)((std::max)((long int)low, x), (long int)high);
    }

    static long int Clamp(long int low, int x, int high)
    {
        return (std::min)((std::max)(low, (long int)x), (long int)high);
    }

    static long int Clamp(long int low, long int x, int high)
    {
        return (std::min)((std::max)(low, x), (long int)high);
    }
#endif

    template<typename T>
    static T Sign(T x)
    {
        if (x < 0) return -1;
        if (x > 0) return 1;
        return 0;
    }
}
