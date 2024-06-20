#include "TftPageManager.h"

#include "Arduino_GFX_Library.h"

namespace
{
    constexpr auto DEFAULT_NAV_STACK_SIZE = 5;
}

TftPageManager::TftPageManager(Arduino_GFX *gfx)
    : m_gfx{gfx},
      m_navStack{new SimpleStack<Page *>(DEFAULT_NAV_STACK_SIZE)}
{
    m_gfx->begin();
}

Page *TftPageManager::currentPage() const
{
    Page *page;

    if (m_navStack->peek(&page))
    {
        return page;
    }

    return nullptr;
}

bool TftPageManager::goToPage(Page *page)
{
    page->render(m_gfx);

    if (currentPage() == page)
    {
        return true;
    }

    return m_navStack->push(page);
}

bool TftPageManager::goToPrevPage()
{
    Page *page;

    if (!m_navStack->pop(&page))
    {
        return false;
    }

    if (!m_navStack->peek(&page))
    {
        return false;
    }

    page->render(m_gfx);
    return true;
}

void TftPageManager::clear()
{
    m_navStack->empty();
}
