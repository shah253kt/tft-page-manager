#pragma once

#include "Page.h"

class Arduino_GFX;

class Page2 : public Page
{
public:
    Page2() = default;
    ~Page2() = default;

    void draw(Arduino_GFX *gfx) override;
};
