/**
* \file PictureObserver.cpp
*
* \author Alexandria Marone
*
* Class that provides a view windows for actors.
*/


#include "stdafx.h"
#include "PictureObserver.h"
#include "Picture.h"


/** Constructor */
CPictureObserver::CPictureObserver()
{
}


/** Destructor */
CPictureObserver::~CPictureObserver()
{
	if (mPicture != nullptr)
	{
		mPicture->RemoveObserver(this);
	}
}
/** Set the picture for this observer
* \param picture The picture to set */
void CPictureObserver::SetPicture(std::shared_ptr<CPicture> picture)
{
	mPicture = picture;
	mPicture->AddObserver(this);
}