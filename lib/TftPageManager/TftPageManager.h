#pragma once

#include "SimpleStack.h"
#include "Page.h"

class Arduino_GFX;

class TftPageManager
{
public:
    TftPageManager(Arduino_GFX *gfx);
    ~TftPageManager() = default;

    Page* currentPage() const;
    bool goToPage(Page *page);
    bool goToPrevPage();
    void clear();

private:
    Arduino_GFX *m_gfx;
    SimpleStack<Page*> *m_navStack;
};
