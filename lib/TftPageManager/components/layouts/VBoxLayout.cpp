#include "VBoxLayout.h"

#include "Arduino_GFX_Library.h"

VBoxLayout::VBoxLayout(UiComponent *parent)
    : UiComponent(parent)
{
}

void VBoxLayout::addComponent(UiComponent *component)
{
    addChild(component);
}

void VBoxLayout::draw(Arduino_GFX *gfx)
{
    if (parent() == nullptr)
    {
        setSize(gfx->width(), gfx->height());
        setPosition(0, 0);
    }
    else
    {
        const auto rect = parent()->containerRect();
        setSize(rect.width.get(), rect.height.get());
        setPosition(rect.width.get(), rect.height.get());
    }

    const auto rect = containerRect();
    auto containerHeight = 0;

    for (auto i = 0; i < children()->size(); i++)
    {
        auto child = children()->get(i);
        child->setSize(rect.width.get(), child->rect()->height.get());
        child->setPosition(rect.x.get(), rect.y.get() + containerHeight);
        containerHeight += child->rect()->height.get();

        child->draw(gfx);
    }
}
