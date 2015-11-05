/**
* \file PictureObserver.h
*
* \author Alexandria Marone
*
* Class that provides a view windows for actors.
*/

#pragma once
#include <memory>
#include "Picture.h"
class CPicture; 
/**
* Observer base class for a picture.
*
* This class implements the base class functionality for
* an observer in the observer pattern.
*/

class CPictureObserver
{
public:
	//! Copy Constructor (Disabled)
	CPictureObserver(const CPictureObserver &) = delete;
	//! Assignment Operator (Disabled)
	CPictureObserver &operator=(const CPictureObserver &) = delete;
	/// This function is called to update any observers
	virtual void UpdateObserver() = 0;
	/// DEstructor
	virtual ~CPictureObserver();
	/** Get picture
	* \returns picture member vairable
	*/
	std::shared_ptr<CPicture> GetPicture(){ return mPicture;  }
	/** Set picture
	* \param picture member vairable
	*/
	void SetPicture(std::shared_ptr<CPicture> picture);

protected:
	/** Constructor
	*/
		CPictureObserver();
private:
	/// boolean to show if updated
	bool mUpdated = false;
	/// Picture we are observing
	std::shared_ptr<CPicture> mPicture;
	
	
};

