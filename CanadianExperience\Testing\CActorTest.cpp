#include "stdafx.h"
#include <string>
#include <memory>
#include "CppUnitTest.h"
#include "Actor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;
using namespace std;
namespace Testing
{
	TEST_CLASS(ActorTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(TestActorTestConstruct)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), actor.GetName());
			
		}
		TEST_METHOD(EnabledDefaultVal)
		{
			CActor actor(L"Harold");

			Assert::IsTrue(true == actor.IsEnabled()); //checks default
			
			actor.SetEnabled(false); //checking set. 

			Assert::IsFalse(actor.IsEnabled());//checks getter

		}
		TEST_METHOD(ClickableDefaultVal)
		{
			CActor actor(L"Harold");

			Assert::IsTrue(true == actor.IsClickable()); //checks default

			actor.SetClickable(false); //checking set. 

			Assert::IsFalse (actor.IsClickable());//checks getter

		}
		TEST_METHOD(PositionDefaultVal)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(0, actor.GetPosition().X); //checking default
			Assert::AreEqual(0, actor.GetPosition().Y);
			

			actor.SetPosition(Gdiplus::Point(5, 4)); //checking set. 

			Assert::AreEqual(5, actor.GetPosition().X);
			Assert::AreEqual(4, actor.GetPosition().Y);//checks getter

		}


	};
}