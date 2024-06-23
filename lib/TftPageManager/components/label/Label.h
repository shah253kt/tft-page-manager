#pragma once

#include "../UiComponent.h"

#include "Arduino_GFX_Library.h"

#include "Arduino.h"

class Arduino_GFX;

class Label : public UiComponent
{
public:
    Label(const char *text, uint16_t color, GFXfont *font = NULL, UiComponent *parent = nullptr);
#if defined(U8G2_FONT_SUPPORT)
    Label(const char *text, uint16_t color, const uint8_t *font = NULL, UiComponent *parent = nullptr);
#endif
    ~Label();

    void draw(Arduino_GFX *gfx) override;

private:
    const char *m_text;
    uint16_t m_color;
    GFXfont *m_font;
    const uint8_t *m_u8g2Font;
    bool m_useU8g2Font;

    void setFont(Arduino_GFX *gfx);
};
