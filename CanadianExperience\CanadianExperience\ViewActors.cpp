/**
 * \file ViewActors.cpp
 *
 * \author 
 */

#include "stdafx.h"
#include "CanadianExperience.h"
#include "ViewActors.h"

#include "DoubleBufferDC.h"
#include "MainFrm.h"

using namespace std;
using namespace Gdiplus;

/// \cond
IMPLEMENT_DYNCREATE(CViewActors, CScrollView)

BEGIN_MESSAGE_MAP(CViewActors, CScrollView)
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()
/// \endcond

/** Constructor */
CViewActors::CViewActors()
{

}

/** Destructor */
CViewActors::~CViewActors()
{
}


/** Handle the initial update for this window */
void CViewActors::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

    CSize sizeTotal(0, 100);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/** Draw this window
* \param pDC Device context */
void CViewActors::OnDraw(CDC* pDC)
{
    CDoubleBufferDC dbDC(pDC);

    Graphics graphics(dbDC.m_hDC);    // Create GDI+ graphics context


	Pen pen(Color(0, 128, 0), 1);
	graphics.DrawRectangle(&pen, 10, 150, 100, 100);

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush brush(Color(0, 0, 0));
	graphics.DrawString(L"Actors!",  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF(15, 170),   // Where to draw
		&brush);    // The brush to draw the text with

	CString time = CTime::GetCurrentTime().Format("%H:%M:%S");
	graphics.DrawString(time,  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF(15, 200),   // Where to draw
		&brush);    // The brush to draw the text with
    // TODO: Drawing code goes here
}


/** Erase the background
*
* This is disabled to eliminate flicker
* \param pDC Device context
* \return FALSE */
BOOL CViewActors::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}
/** Force an update of this window when the picture changes.
*/
void CViewActors::UpdateObserver()
{
	Invalidate();
}
