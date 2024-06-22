#pragma once

#include "../UiComponent.h"

#include "Arduino_GFX_Library.h"

#include "Arduino.h"

class Arduino_GFX;

class Label : public UiComponent
{
public:
    Label(const char *text, GFXfont *font = NULL, UiComponent *parent = nullptr);
    Label(const char *text, const uint8_t *font, UiComponent *parent = nullptr);
    ~Label();

    void draw(Arduino_GFX *gfx) override;

private:
    const char *m_text;
    GFXfont *m_font;
    const uint8_t *m_u8g2Font;
    bool m_useU8g2Font;

    void setFont(Arduino_GFX *gfx);
};
