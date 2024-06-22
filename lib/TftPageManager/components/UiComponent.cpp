#include "UiComponent.h"

#include "Arduino.h"

UiComponent::UiComponent(UiComponent *parent)
    : m_children{},
      m_visible{true},
      m_enabled{true}
{
    setParent(parent);
}

UiComponent::~UiComponent()
{
    while (m_children.size() > 0)
    {
        auto child = m_children.pop();
        delete child;
    }
}

void UiComponent::render(Arduino_GFX *gfx)
{
    if (!isVisible())
    {
        return;
    }

    draw(gfx);
}

UiComponent *UiComponent::parent()
{
    return m_parent;
}

void UiComponent::setParent(UiComponent *parent)
{
    if (m_parent != nullptr)
    {
        m_parent->removeChild(this);
    }

    m_parent = parent;
    
    if (m_parent != nullptr)
    {
        m_parent->addChild(this);
    }
}

LinkedList<UiComponent *> *UiComponent::children()
{
    return &m_children;
}

void UiComponent::addChild(UiComponent *child)
{
    m_children.add(child);
}

void UiComponent::removeChild(UiComponent *child)
{
    for (auto i = 0; i < m_children.size(); i++)
    {
        if (m_children.get(i) == this)
        {
            m_children.remove(i);
            return;
        }
    }
}

void UiComponent::setPosition(const int x, const int y)
{
    m_rect.x = x;
    m_rect.y = y;
}

void UiComponent::setSize(const int width, const int height)
{
    m_rect.width = width;
    m_rect.height = height;
}

Padding *UiComponent::padding()
{
    return &m_padding;
}

void UiComponent::setPadding(const int padding)
{
    m_padding.top = padding;
    m_padding.right = padding;
    m_padding.bottom = padding;
    m_padding.left = padding;
}

void UiComponent::setPadding(const int paddingTop, const int paddingRight, const int paddingBottom, const int paddingLeft)
{
    m_padding.top = paddingTop;
    m_padding.right = paddingRight;
    m_padding.bottom = paddingBottom;
    m_padding.left = paddingLeft;
}

bool UiComponent::isVisible()
{
    return m_visible.get();
}

void UiComponent::setVisible(const bool visible)
{
    m_visible = visible;
}

bool UiComponent::isEnabled()
{
    return m_enabled.get();
}

void UiComponent::setEnabled(const bool enabled)
{
    m_enabled = enabled;
}

Rect *UiComponent::rect()
{
    return &m_rect;
}

Rect UiComponent::containerRect()
{
    Rect rect;
    rect.x = max(0, m_rect.x.get() + m_padding.left.get());
    rect.y = max(0, m_rect.y.get() + m_padding.top.get());
    rect.width = max(0, m_rect.width.get() - m_padding.left.get() - m_padding.right.get());
    rect.height = max(0, m_rect.height.get() - m_padding.top.get() - m_padding.bottom.get());
    return rect;
}
