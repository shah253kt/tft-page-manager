#pragma once

#include "../UiComponent.h"

class Arduino_GFX;

class VBoxLayout : public UiComponent
{
public:
    VBoxLayout(UiComponent *parent = nullptr);
    ~VBoxLayout() = default;

    void addComponent(UiComponent *component);

    void draw(Arduino_GFX *gfx) override;
private:
};
