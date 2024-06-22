#pragma once

#include "Property.h"

struct Padding
{
    Property<int> top{0};
    Property<int> right{0};
    Property<int> bottom{0};
    Property<int> left{0};
};
