#pragma once

#include <iostream>

void Assert(bool condition, const char *error)
{
    if (condition == false)
    {
        std::cerr << "\033[" << 31 << "m"
                  << error
                  << "\033[" << 39 << "m"
                  << std::endl;

        exit(1);
    }
}
