#include "TftPageManager.h"

#include "Arduino_GFX_Library.h"

TftPageManager::TftPageManager(Arduino_GFX *gfx)
    : m_gfx{gfx},
      m_navStack{new LinkedList<Page *>()}
{
    m_gfx->begin();
}

Page *TftPageManager::currentPage() const
{
    if (m_navStack->size() == 0)
    {
        return nullptr;
    }

    return m_navStack->get(m_navStack->size() - 1);
}

void TftPageManager::goToPage(Page *page)
{
    page->render(m_gfx);

    if (currentPage() == page)
    {
        return;
    }

    m_navStack->add(page);
}

void TftPageManager::goToPrevPage()
{
    if (m_navStack->size() <= 1)
    {
        return;
    }

    m_navStack->pop();
    auto page = m_navStack->get(m_navStack->size() - 1);
    page->render(m_gfx);
}

void TftPageManager::goToFirstPage()
{
    while (m_navStack->size() > 1)
    {
        m_navStack->pop();
    }

    auto page = m_navStack->get(0);
    page->render(m_gfx);
}
