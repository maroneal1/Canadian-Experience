/**
* \file HeadTop.h
*
* \author A marone
*
* Head top class. 
*/


#pragma once
#include <string>
#include "ImageDrawable.h"
/**
* the head
*
* head drawable
*/

class CHeadTop :
	public CImageDrawable
{
public:
	
	/** \brief Default constructor disabled */
	CHeadTop() = delete;
	/** \brief Copy constructor disabled */
	CHeadTop(const CHeadTop &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CHeadTop &) = delete;
	/** \brief constructor
	* \param name is name
	* \param filename for opening 
	*/
	CHeadTop(const std::wstring &name, const std::wstring &filename);
	/** \brief Drawing
	* \param graphics for drawing
	*/
	void Draw(Gdiplus::Graphics *graphics);
	/** \brief transform
	* \param p is the point to transform 

	*/
	Gdiplus::Point TransformPoint(Gdiplus::Point p);
	/** \brief destructor
	*/
	virtual ~CHeadTop();
	/** \brief Moveable override 
	* \returns true always 
	*/
	bool IsMovable() override { return true; }


};

