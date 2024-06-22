#pragma once

#include "LinkedList.h"
#include "Padding.h"
#include "Rect.h"

class Arduino_GFX;

class UiComponent
{
public:
    UiComponent(UiComponent *parent = nullptr);
    virtual ~UiComponent();

    void render(Arduino_GFX *gfx);

    UiComponent *parent();
    void setParent(UiComponent *parent);

    LinkedList<UiComponent *> *children();
    void addChild(UiComponent *child);
    void removeChild(UiComponent *child);

    void setPosition(int x, int y);
    void setSize(int width, int height);

    Padding *padding();
    void setPadding(int padding);
    void setPadding(int paddingTop, int paddingRight, int paddingBottom, int paddingLeft);

    bool isVisible();
    void setVisible(bool visible);

    bool isEnabled();
    void setEnabled(bool enabled);

    Rect *rect();
    Rect containerRect();

    virtual void draw(Arduino_GFX *gfx) = 0;

private:
    UiComponent *m_parent;
    LinkedList<UiComponent *> m_children;
    Rect m_rect;
    Padding m_padding;
    Property<bool> m_visible;
    Property<bool> m_enabled;
};
