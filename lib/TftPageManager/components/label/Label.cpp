#include "Label.h"

namespace
{
    constexpr auto DEFAULT_PADDING_PX = 2;
}

Label::Label(const char *text, uint16_t color, GFXfont *font, UiComponent *parent)
    : UiComponent(parent),
      m_text{text},
      m_color{color},
      m_font{font},
      m_u8g2Font{NULL},
      m_useU8g2Font{false}
{
    setPadding(DEFAULT_PADDING_PX);
}

#if defined(U8G2_FONT_SUPPORT)
Label::Label(const char *text, uint16_t color, const uint8_t *font, UiComponent *parent)
    : UiComponent(parent),
      m_text{text},
      m_color{color},
      m_font{NULL},
      m_u8g2Font{font},
      m_useU8g2Font{true}
{
    setPadding(DEFAULT_PADDING_PX);
}
#endif

Label::~Label()
{
    delete m_text;
}

void Label::draw(Arduino_GFX *gfx)
{
    setFont(gfx);
    int16_t x1, x2;
    uint16_t width, height;
    gfx->setCursor(rect()->x.get() + padding()->left.get(), rect()->y.get() + padding()->top.get());
    gfx->getTextBounds(m_text, gfx->getCursorX(), gfx->getCursorY(), &x1, &x2, &width, &height);
    gfx->setTextColor(m_color);
    gfx->print(m_text);
    setSize(width + padding()->left.get() + padding()->right.get(), height + padding()->top.get() + padding()->bottom.get());
}

void Label::setFont(Arduino_GFX *gfx)
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