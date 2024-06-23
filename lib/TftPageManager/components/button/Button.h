#pragma once

#include "../UiComponent.h"

#include "Arduino_GFX_Library.h"

#include "Arduino.h"

class Arduino_GFX;

class Button : public UiComponent
{
public:
    Button(const char *text, uint16_t fgColor, uint16_t bgColor, bool filled = false, GFXfont *font = NULL, UiComponent *parent = nullptr);
#if defined(U8G2_FONT_SUPPORT)
    Button(const char *text, uint16_t fgColor, uint16_t bgColor, bool filled = false, const uint8_t *font = NULL, UiComponent *parent = nullptr);
#endif
    ~Button();

    void draw(Arduino_GFX *gfx) override;

private:
    const char *m_text;
    uint16_t m_fgColor;
    uint16_t m_bgColor;
    bool m_filled;
    GFXfont *m_font;
    const uint8_t *m_u8g2Font;
    bool m_useU8g2Font;

    void setFont(Arduino_GFX *gfx);
};
