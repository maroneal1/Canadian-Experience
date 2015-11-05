#include "stdafx.h"
#include <string>
#include <memory>
#include "HeadTop.h"

using namespace Gdiplus; 
using namespace std;

CHeadTop::CHeadTop(const std::wstring &name, const std::wstring &filename) : CImageDrawable (name, filename){
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


CHeadTop::~CHeadTop()
{
}

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/**
* Draw the image drawable
* \param graphics Graphics context to draw on
*/

void CHeadTop::Draw(Gdiplus::Graphics *graphics)
{
	/// THIS SECTION IS TO STILL DRAW HEAD
	auto state = graphics->Save();
    graphics->TranslateTransform((float)mPlacedPosition.X, (float)mPlacedPosition.Y);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->DrawImage(mImage.get(), -GetCenter().X, -GetCenter().Y,
		mImage->GetWidth(), mImage->GetHeight());
	graphics->Restore(state);
	//DRAW HEAD END


	SolidBrush brush(Color(0,0,0));
	//Gdiplus::Pen pen(Color(0, 0, 0));

	Gdiplus::Point p1 = TransformPoint(Gdiplus::Point(15, 55));
	Gdiplus::Point p2 = TransformPoint(Gdiplus::Point(40, 55)); //ONE EYE BROW

	Gdiplus::Point p3 = TransformPoint(Gdiplus::Point(65, 55));
	Gdiplus::Point p4 = TransformPoint(Gdiplus::Point(90, 55)); //TWO EYE BROW

	Pen eyebrowPen(Color::Black, 2);
	graphics->DrawLine(&eyebrowPen, p1, p2);
	graphics->DrawLine(&eyebrowPen, p3, p4);  
// ------------------DONE WITH EYEBROWS ----------------------

	
	state = graphics->Save();
	Gdiplus::Point p5 = TransformPoint(Gdiplus::Point(25, 70)); // was 18 60
	
	Pen eyePen(Color::Black, 2);
	Gdiplus::Size s(15,20);
	Gdiplus::Rect rec(p5, s);
	


	/*
	graphics->DrawEllipse(&eyePen, rec);
	
	
	graphics->FillEllipse(&brush, rec);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->Restore(state);
	*/
	
	float wid = 15.0f;
	float hit = 20.0f;


	//THIS WORKS!!!!!!!!!! 
	 state = graphics->Save();
	graphics->TranslateTransform(p5.X , p5.Y);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	//graphics->FillEllipse(&brush, rec);
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state);

	

	state = graphics->Save();
	graphics->TranslateTransform(p5.X , p5.Y);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	//graphics->FillEllipse(&brush, rec);
	graphics->FillEllipse(&brush, (-wid / 2 ) +50, -hit / 2, wid, hit);
	graphics->Restore(state);





}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}