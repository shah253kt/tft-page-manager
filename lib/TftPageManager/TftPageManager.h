#pragma once

#include "LinkedList.h"
#include "Page.h"

class Arduino_GFX;

class TftPageManager
{
public:
    TftPageManager(Arduino_GFX *gfx);
    ~TftPageManager() = default;

    Page* currentPage() const;
    void goToPage(Page *page);
    void goToPrevPage();
    void goToFirstPage();

private:
    Arduino_GFX *m_gfx;
    LinkedList<Page*> *m_navStack;
};
