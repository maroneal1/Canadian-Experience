

#pragma once
#include "Picture.h"
/**
* A factory class that builds our picture.
*/
class CPictureFactory
{
public:
	CPictureFactory();
	virtual ~CPictureFactory();

	std::shared_ptr<CPicture> Create();
};

