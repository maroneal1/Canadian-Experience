/**
 * \file ViewTop.cpp
 *
 * \author Charles B. Owen
 */


#include "stdafx.h"
#include "CanadianExperience.h"
#include "ViewTop.h"

#include "ViewActors.h"
#include "ViewEdit.h"
#include "ViewTimeline.h"

IMPLEMENT_DYNCREATE(CViewTop, CView)

BEGIN_MESSAGE_MAP(CViewTop, CView)
    ON_WM_CREATE()
    ON_WM_SIZE()
END_MESSAGE_MAP()

/** Constructor */
CViewTop::CViewTop()
{

}

/** Destructor */
CViewTop::~CViewTop()
{
}

/** Drawing for this view 
 * \param pDC The device context */
void CViewTop::OnDraw(CDC* pDC)
{
}


/** Handle a CREATE message for this window 
 * \param lpCreateStruct The creation parameter structure 
 * \return 0 if successful */
int CViewTop::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    if (!mWndSplitter.CreateStatic(this, 1, 2, WS_CHILD | WS_VISIBLE, AFX_IDW_PANE_FIRST + 8))
    {
        TRACE("Failed to create splitter window");
        return -1;
    }

    CCreateContext context;

    CRect rect;

    GetClientRect(&rect);
    context.m_pNewViewClass = RUNTIME_CLASS(CViewActors);
    BOOL ret = mWndSplitter.CreateView(0, 0, RUNTIME_CLASS(CViewActors), CSize(0, 0), &context);
    context.m_pNewViewClass = RUNTIME_CLASS(CViewEdit);
    ret = mWndSplitter.CreateView(0, 1, RUNTIME_CLASS(CViewEdit), CSize(0, 0), &context);

    return 0;
}

/**
 * Handle a new size message
 * \param nType Type of size message
 * \param cx New width
 * \param cy New height
 */
void CViewTop::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);
    mWndSplitter.MoveWindow(0, 0, cx, cy);

    mWndSplitter.SetColumnInfo(0, CViewActors::Width, 0);
    mWndSplitter.SetColumnInfo(1, 500, 0);
    mWndSplitter.RecalcLayout();
}
