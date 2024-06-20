#include "Page.h"

#include "Arduino_GFX_Library.h"

Page::Page(uint32_t updateInterval)
    : m_rendered{false},
      m_updateInterval{updateInterval},
      m_lastRenderAt{0}
{
}

void Page::setUpdateInterval(const uint32_t interval)
{
    m_updateInterval = interval;
}

bool Page::update(Arduino_GFX *gfx, const bool force)
{
    if (!m_rendered || force)
    {
        render(gfx);
        return true;
    }

    if (m_updateInterval == 0 || millis() - m_lastRenderAt < m_updateInterval)
    {
        return false;
    }

    render(gfx);
    return true;
}

void Page::render(Arduino_GFX *gfx)
{
    if (preRender)
    {
        preRender();
    }

    draw(gfx);

    if (postRender)
    {
        postRender();
    }

    m_rendered = true;
    m_lastRenderAt = millis();
}
