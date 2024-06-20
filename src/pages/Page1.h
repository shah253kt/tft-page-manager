#pragma once

#include "Page.h"

class Arduino_GFX;

class Page1 : public Page
{
public:
    Page1() = default;
    ~Page1() = default;

    void draw(Arduino_GFX *gfx) override;
};
