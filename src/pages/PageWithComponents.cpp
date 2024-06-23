#include "PageWithComponents.h"

#include "components/layouts/VBoxLayout.h"
#include "components/button/Button.h"
#include "components/label/Label.h"

#include "Arduino_GFX_Library.h"

void PageWithComponents::draw(Arduino_GFX *gfx)
{
    gfx->fillScreen(BLACK);

    VBoxLayout layout;
    layout.addComponent(new Label("My label 1", WHITE));
    layout.addComponent(new Label("My label 2", WHITE));
    layout.addComponent(new Button("My button", WHITE, GREENYELLOW));

    layout.draw(gfx);
}
