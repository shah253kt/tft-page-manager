#pragma once

#include "Arduino.h"

class Arduino_GFX;

typedef void (*FunctionPointer)(void);

class Page
{
public:
    FunctionPointer preRender;
    FunctionPointer postRender;

    Page(uint32_t updateInterval = 0);
    ~Page() = default;

    void setUpdateInterval(uint32_t interval);
    bool update(Arduino_GFX *gfx, bool force = false);
    void render(Arduino_GFX *gfx);

    virtual void draw(Arduino_GFX *gfx) = 0;

private:
    bool m_rendered;
    uint32_t m_updateInterval;
    uint32_t m_lastRenderAt;
};
