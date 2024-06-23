#include "Button.h"

namespace
{
    constexpr auto DEFAULT_VERTICAL_PADDING_PX = 2;
    constexpr auto DEFAULT_HORIZONTAL_PADDING_PX = 5;
}

Button::Button(const char *text, uint16_t fgColor, uint16_t bgColor, bool filled, GFXfont *font, UiComponent *parent)
    : UiComponent(parent),
      m_text{text},
      m_fgColor{fgColor},
      m_bgColor{bgColor},
      m_filled{filled},
      m_font{font},
      m_u8g2Font{NULL},
      m_useU8g2Font{false}
{
    setPadding(DEFAULT_VERTICAL_PADDING_PX, DEFAULT_HORIZONTAL_PADDING_PX, DEFAULT_VERTICAL_PADDING_PX, DEFAULT_HORIZONTAL_PADDING_PX);
}

#if defined(U8G2_FONT_SUPPORT)
Button::Button(const char *text, uint16_t fgColor, uint16_t bgColor, bool filled, const uint8_t *font, UiComponent *parent)
    : UiComponent(parent),
      m_text{text},
      m_fgColor{fgColor},
      m_bgColor{bgColor},
      m_filled{filled},
      m_font{NULL},
      m_u8g2Font{font},
      m_useU8g2Font{true}
{
    setPadding(DEFAULT_VERTICAL_PADDING_PX, DEFAULT_HORIZONTAL_PADDING_PX, DEFAULT_VERTICAL_PADDING_PX, DEFAULT_HORIZONTAL_PADDING_PX);
}
#endif

Button::~Button()
{
    delete m_text;
}

void Button::draw(Arduino_GFX *gfx)
{
    setFont(gfx);
    int16_t x1, x2;
    uint16_t width, height;
    gfx->setCursor(rect()->x.get() + padding()->left.get(), rect()->y.get() + padding()->top.get());
    gfx->getTextBounds(m_text, gfx->getCursorX(), gfx->getCursorY(), &x1, &x2, &width, &height);
    setSize(width + padding()->left.get() + padding()->right.get(), height + padding()->top.get() + padding()->bottom.get());

    if (m_filled)
    {
        gfx->fillRect(rect()->x.get(), rect()->y.get(), rect()->width.get(), rect()->height.get(), m_bgColor);
    }
    else
    {
        gfx->drawRect(rect()->x.get(), rect()->y.get(), rect()->width.get(), rect()->height.get(), m_bgColor);
    }

    gfx->setTextColor(m_fgColor);
    gfx->print(m_text);
}

void Button::setFont(Arduino_GFX *gfx)
{
    if (!m_useU8g2Font)
    {
        gfx->setFont(m_font);
    }
    else
    {
#if defined(U8G2_FONT_SUPPORT)
        gfx->setFont(m_u8g2Font);
#endif
    }
}