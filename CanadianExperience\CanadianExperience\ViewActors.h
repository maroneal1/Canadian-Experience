/**
 * \file ViewActors.h
 *
 * \author Alexandria Marone
 *
 * Class that provides a view windows for actors.
 */

#pragma once
#include "PictureObserver.h"
class CMainFrame;
/** Class that provides a view windows for actors. */
class CViewActors : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewActors)
public:
    static const int Width = 150;  ///< Width we want for this window 

protected:
	CViewActors();           // protected constructor used by dynamic creation
	virtual ~CViewActors();
	virtual void UpdateObserver() override;

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	/** Set the mainFrame pointer
	* \param mainFrame Pointer to the CMainFrame window */
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }
private:
	/// The main frame window that uses this view
	CMainFrame  *mMainFrame = nullptr;
};


