#include "Page2.h"

#include "Arduino_GFX_Library.h"

void Page2::draw(Arduino_GFX *gfx)
{
    gfx->fillScreen(BLACK);
    gfx->setCursor(10, 10);
    gfx->setTextColor(RED);
    gfx->println("This is page 2");
}
