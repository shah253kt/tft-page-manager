#include <Arduino.h>

#include "PinsAssignment.h"

#include "Arduino_GFX_Library.h"
#include "TftPageManager.h"
#include "pages/Page1.h"
#include "pages/Page2.h"
#include "pages/PageWithComponents.h"

#define DISPLAY_ROTATION 1 // 0 = 0°, 1 = 90°, 2 = 180°, 3 = 270°

Arduino_DataBus *bus = new Arduino_HWSPI(TftDisplay::RS, TftDisplay::CS);
Arduino_GFX *gfx = new Arduino_ILI9486(bus, TftDisplay::RST, DISPLAY_ROTATION);
TftPageManager pageManager(gfx);
auto page1 = new Page1();
auto page2 = new Page2();
auto pageWithComponents = new PageWithComponents();

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if (Serial.available())
    {
        switch (Serial.read())
        {
        case '1':
        {
            pageManager.goToPage(page1);
            break;
        }
        case '2':
        {
            pageManager.goToPage(page2);
            break;
        }
        case '3':
        {
            pageManager.goToPage(pageWithComponents);
            break;
        }
        }
    }
}
