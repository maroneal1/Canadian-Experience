/**
* \file ImageDrawable.h
*
* \author A marone
*
* Abstract base class for images
*/


#pragma once

#include <memory>
#include "Drawable.h"


using namespace Gdiplus;
/**
* the image drawable
*
* Inherited from drawable
*/
class CImageDrawable :
	public CDrawable
{
public:
	/** \brief Default constructor disabled */
	CImageDrawable() = delete;
	/** \brief Copy constructor disabled */
	CImageDrawable(const CImageDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CImageDrawable &) = delete;
	/** center
	* \returns mCenter
	*/
	Gdiplus::Point GetCenter(){ return mCenter; }
	/** Sets center
	* \param center is m variable
	*/
	void SetCenter(Gdiplus::Point center){ mCenter = center; }
	/** Deconstructor */
	virtual ~CImageDrawable();
	/** cons
	* \param name is name
	* \param filename for constructor
	*/
	CImageDrawable(const std::wstring &name, const std::wstring &filename); 
	/** Draw
	* \param graphics object for drawing. 
	*/
	void Draw(Gdiplus::Graphics *graphics);
	/** cons
	* \param pos position
	*/
	bool HitTest(Gdiplus::Point pos);

protected:
	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;
private: 
	/// The position of this drawable relative to center
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);



	


};

