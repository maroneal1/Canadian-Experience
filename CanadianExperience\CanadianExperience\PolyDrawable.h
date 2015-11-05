/**
* \file PolyDrawable.h
*
* \author A marone
*
* Abstract base class for drawable elements of our picture
*/

#pragma once
#include <vector>
#include "Drawable.h"


/**
* A drawable based on polygon images.
*
* This class has a list of points and draws a polygon
* drawable based on those points.
*/
class CPolyDrawable : public CDrawable
{
public:
	/** \brief Default constructor disabled */
	CPolyDrawable() = delete;
	/** \brief Copy constructor disabled */
	CPolyDrawable(const CPolyDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CPolyDrawable &) = delete;
	CPolyDrawable(const std::wstring &name);
	

	virtual ~CPolyDrawable();
	/** \brief Get colors
	* \returns member var color
	*/
	Gdiplus::Color GetColor(){ return mColor; }
	/** \brief set colors
	* \param incolor sets member var color
	*/
	void SetColor(Gdiplus::Color incolor){ mColor = incolor; }
	/** \brief adds a point
	* \param point to add
	*/
	void AddPoint(Gdiplus::Point point){ mPoints.push_back(point); }
	/** \brief draws
	* \param graphics to draw
	*/
	void Draw(Gdiplus::Graphics *graphics);
	/** hit test
	* \param pos position
	*/
	bool HitTest(Gdiplus::Point pos);
private:
	/// The polygon color
	Gdiplus::Color mColor = Gdiplus::Color::Black;
	/// The array of point objects
	std::vector<Gdiplus::Point> mPoints;
};

