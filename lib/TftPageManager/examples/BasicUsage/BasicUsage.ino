#include "Arduino_GFX_Library.h"
#include "TftPageManager.h"
#include "pages/Page1.h"
#include "pages/Page2.h"

constexpr auto RS = 38;
constexpr auto CS = 40;
constexpr auto RST = 41;

Arduino_DataBus *bus = new Arduino_HWSPI(RS, CS);
Arduino_GFX *gfx = new Arduino_ILI9486(bus, RST);
TftPageManager pageManager(gfx);
auto page1 = new Page1();
auto page2 = new Page2();

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
        }
    }
}
