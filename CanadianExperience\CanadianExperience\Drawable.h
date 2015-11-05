/**
* \file Drawable.h
*
* \author A marone
*
* Abstract base class for drawable elements of our picture
*/

#pragma once

#include <memory>
#include <vector>
#include <string>

class CActor;


/**
* Abstract base class for drawable elements of our picture
*/
class CDrawable
{
public:
	/** destructor 
	*/
	virtual ~CDrawable();

	/** Default constructor disabled */
	CDrawable() = delete;
	/** Copy constructor disabled */
	CDrawable(const CDrawable &) = delete;
	/** Assignment operator disabled */
	void operator=(const CDrawable &) = delete;
	/**Set Actor
	* \param actor actor that we are setting
	*/
	void SetActor(CActor *actor);
	/**Draw
	* \param graphics graphics we are drawing
	*/
	virtual void Draw(Gdiplus::Graphics *graphics) = 0;
	/**Place
	* \param offset amount offset is moved by 
	* \param rotate amount we are rotating. 
	*/
	void Place(Gdiplus::Point offset, double rotate);
	/** Add child
	* \param  child thing we are adding.
	*/
	
	void AddChild(std::shared_ptr<CDrawable> child);
	/** Hit test
	* \param pos position
	*/
	virtual bool HitTest(Gdiplus::Point pos) = 0;
	/** IsMoveable
	* \returns false 
	*/
	virtual bool IsMovable() { return false; }
	/** Move
	* \param delta is a point
	*/
	void Move(Gdiplus::Point delta);

	/** Set the drawable position
	* \param pos The new drawable position*/
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** Get the drawable position
	* \returns The drawable position*/
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** Set the rotation angle in radians
	* \param r The new rotation angle in radians*/
	void SetRotation(double r) { mRotation = r; }

	/** Get the rotation angle in radians
	* \returns The rotation angle in radians*/
	double GetRotation() const { return mRotation; }

	/** Get the drawable name
	* \returns The drawable name */
	std::wstring GetName() const { return mName; }
	/** Setter for a variable
	* \param parent to change to  */
	void SetParent(CDrawable *parent){ mParent = parent; }
	/** Getter for a variable
	* \returns parent for getting */
	CDrawable * GetParent() const{ return mParent; }
protected:
	/** Constructor
	* \param name is name to draw */
	CDrawable(const std::wstring &name);
	/**  Rotate Point
	* \param point is the point  
	* \param angle is angle of rotate
	*/
	Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);


	/// The actual postion in the drawing
	Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

	/// The actual rotation in the drawing
	double mPlacedR = 0;

private:
	/// The drawable name
	std::wstring mName;
	/// vector of children
	std::vector<std::shared_ptr<CDrawable>> mChildren;
	///tells parent
	CDrawable *mParent = nullptr;

	/// The position of this drawable relative to its parent
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// The rotation of this drawable relative to its parent
	double mRotation = 0;
	/// The actor using this drawable
	CActor *mActor = nullptr;
};

