/**
* \file Actor.h
*
* \author Alexandria Marone
*
* Class for actors in our drawings
*/

#pragma once
#include <string>
#include <memory>
#include <vector>

#include "Drawable.h"

using namespace Gdiplus; 

class CPicture;
/**
* Class for actors in our drawings.
*
* An actor is some graphical object that consists of
* one or more parts. Actors can be animated.
*/
class CActor
{
public:
	CActor(const std::wstring &name);

	/** Default constructor disabled */
	CActor() = delete;
	/** Copy constructor disabled */
	CActor(const CActor &) = delete;
	/** Assignment operator disabled */
	void operator=(const CActor &) = delete;
	/**Destructor*/
	virtual ~CActor();
	/** set root
	
	* \param root to set */
	void SetRoot(std::shared_ptr<CDrawable> root);
	/** Draw
	
	* \param graphics to draw on */
	void Draw(Gdiplus::Graphics *graphics);
	/** Hittest
	* \returns drawable object
	* \param pos position */
	std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);
	/** add drawable
	
	* \param drawable to draw */
	void AddDrawable(std::shared_ptr<CDrawable> drawable);

	/** Get the actor name
	* \returns Actor name */
	std::wstring GetName() const { return mName; }

	/** The actor position
	* \returns The actor position as a point */
	Gdiplus::Point GetPosition() const { return mPosition; }
	/** set pic
	
	* \param pic to picrue*/
	void SetPicture(CPicture * pic){ mPicture = pic; }
	/** Gets picture
	* \returns picture
	*/
	CPicture * GetPicture(){ return mPicture; }
	/** The actor position
	* \param pos The new actor position */
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }


	/** Actor is enabled
	* \returns enabled status */
	bool IsEnabled() const { return mEnabled; }

	/** Set Actor Enabled
	* \param enabled New enabled status */
	void SetEnabled(bool enabled) { mEnabled = enabled; }

	/** Actor is clickable
	* \returns true if actor is clickable */
	bool IsClickable() const { return mClickable; }
	
	/** Actor clickable
	* \param clickable New clickable status */
	void SetClickable(bool clickable) { mClickable = clickable; }

private:
	/// picture
	CPicture *  mPicture=nullptr;
	/// m var name
	std::wstring mName;
	/// bool true
	bool mEnabled = true;
	/// Positoon 
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	///clickable
	bool mClickable = true;
	/// The root drawable
	std::shared_ptr<CDrawable> mRoot;
	/// The drawables in drawing order
	std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;
};