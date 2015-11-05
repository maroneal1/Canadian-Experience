/**
* \file PictureFactory.cpp
*
* \author Alexandria Marone
*/

#include "stdafx.h"
#include <memory>
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "Picture.h"
#include "ImageDrawable.h"
#include "QuinnFactory.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}
/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
	shared_ptr<CPicture> picture = make_shared<CPicture>();
	
	// Create the background and add it
	auto background = make_shared<CActor>(L"Background");
	background->SetClickable(false);
	background->SetPosition(Point(-100, 0));
	auto backgroundI =
		make_shared<CImageDrawable>(L"Background", L"images/Background.png");
	background->AddDrawable(backgroundI);
	background->SetRoot(backgroundI);
	picture->AddActor(background);


	// Create and add Harold
	CHaroldFactory factory;
	auto harold = factory.Create();

	CQuinnFactory factory1;
	auto quinn = factory1.Create();

	// This is where Harold will start out.
	harold->SetPosition(Point(400, 500));

	quinn->SetPosition(Point(600, 500));


	picture->AddActor(harold);

	picture->AddActor(quinn);

	return picture;
}