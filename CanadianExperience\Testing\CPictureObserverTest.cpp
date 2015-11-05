
#include "stdafx.h"
#include <memory>
#include "CppUnitTest.h"
#include "PictureObserver.h"
#include "Picture.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace Testing
{
	class CPictureObserverMock : public CPictureObserver
	{
	public:
		CPictureObserverMock() : CPictureObserver() {}
		//virtual void UpdateObserver() override {}
		bool mUpdated = false;
		virtual void UpdateObserver() override { mUpdated = true; }



	};
	TEST_CLASS(CPictureObserverTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(TestCPictureObserverConstruct)
		{
			CPictureObserverMock observer;
		}
		TEST_METHOD(TestCPictureObserverOneObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);

			picture->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);

		}
		TEST_METHOD(TestCPictureGetPicture)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);
			
			CPictureObserverMock observer2;

			// And set it for the observer:
			observer2.SetPicture(picture);

			auto a = observer.GetPicture();
			auto b = observer.GetPicture();
			Assert::IsTrue(a == b);

			
			
			

		}
		TEST_METHOD(TestCPictureObserverTwoObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);

			CPictureObserverMock observer2;

			// And set it for the observer:
			observer2.SetPicture(picture);

			picture->UpdateObservers();

			
			Assert::IsTrue(observer2.mUpdated);
			Assert::IsTrue(observer.mUpdated);

		}
		TEST_METHOD(TestCPictureObserverDeletedObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);
			picture->UpdateObservers();
			{

				CPictureObserverMock observer2;

				// And set it for the observer:
				observer2.SetPicture(picture);
			}

			picture->UpdateObservers();		
			Assert::IsTrue(observer.mUpdated);

		}
		

	};
}