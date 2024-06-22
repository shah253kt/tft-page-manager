#pragma once

#include "Property.h"

struct Rect
{
    Property<int> x{0};
    Property<int> y{0};
    Property<int> width{0};
    Property<int> height{0};
};