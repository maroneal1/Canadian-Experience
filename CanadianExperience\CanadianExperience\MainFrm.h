/**
 * \file MainFrm.h
 *
 * \author Alexandria Maarone
 *
 * The program main frame.
 */

#pragma once
#include <memory>
#include "ViewEdit.h"
#include "ViewTimeline.h"
#include "ViewActors.h"





class CPicture;

/** Program main frame */
class CMainFrame : public CFrameWndEx
{
	
public:
	CMainFrame();

    /** Enumerations for the possible manipulation modes */
    enum MotionModes { Move, Rotate };

    /** The selected manipulation mode 
     * \return Currently selected manipulation mode */
    MotionModes GetMode() const { return mMode; }


protected: 
	DECLARE_DYNAMIC(CMainFrame)

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CMFCToolBar     m_wndToolBar; ///toolbar
	CMFCStatusBar   m_wndStatusBar; ///status bad
	CSplitterWnd    mWndSplitter; ///just window var
	/// The picture object we are viewing/editing
	std::shared_ptr<CPicture> mPicture;

private:
    void Initialize();

    /// The timeline window
    CViewTimeline  *mViewTimeline;

    /// The editing window
    CViewEdit      *mViewEdit;

    /// The actors window
    CViewActors    *mViewActors;

    /// The current manipulation mode
    MotionModes mMode = Move;

// Generated message map functions
protected:
	/**create
	* \param lpCreateStruct is old
	*/
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	/**set focus
	* \param pOldWnd is old

	*/
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()
	/** Oncreate client
	* \param lpcs  is good
	* \param pContext is context
	*/
    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnEditMove();
    afx_msg void OnUpdateEditMove(CCmdUI *pCmdUI);
    afx_msg void OnEditRotate();
    afx_msg void OnUpdateEditRotate(CCmdUI *pCmdUI);
};


