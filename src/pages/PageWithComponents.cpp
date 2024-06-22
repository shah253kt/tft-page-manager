#include "PageWithComponents.h"

#include "components/layouts/VBoxLayout.h"
#include "components/label/Label.h"

#include "Arduino_GFX_Library.h"

void PageWithComponents::draw(Arduino_GFX *gfx)
{
    VBoxLayout layout;
    layout.addComponent(new Label("My label 1"));
    layout.addComponent(new Label("My label 2"));
}
