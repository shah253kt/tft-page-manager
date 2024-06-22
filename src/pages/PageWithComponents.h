#pragma once

#include "Page.h"

class Arduino_GFX;

class PageWithComponents : public Page
{
public:
    PageWithComponents() = default;
    ~PageWithComponents() = default;

    void draw(Arduino_GFX *gfx) override;
};
