#include "stdafx.h"
#include <string>
#include <memory>
#include "CppUnitTest.h"
#include "Drawable.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;
using namespace std;
namespace Testing
{
	class CDrawableMock : public CDrawable
	{
	public:
		CDrawableMock(const std::wstring &name) : CDrawable(name) {}

		virtual void Draw(Gdiplus::Graphics *graphics) override {}
		virtual bool HitTest(Gdiplus::Point pos) override { return false; }

	};
	TEST_CLASS(CDrawableTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(ConsNameGetter)
		{
			CDrawableMock drawable(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), drawable.GetName());
			
		}
		TEST_METHOD(PosNameGetter)
		{
			CDrawableMock drawable(L"Harold");
			Assert::AreEqual(0, drawable.GetPosition().X); //checking default
			Assert::AreEqual(0, drawable.GetPosition().Y);


			drawable.SetPosition(Gdiplus::Point(5, 4)); //checking set. 

			Assert::AreEqual(5, drawable.GetPosition().X);
			Assert::AreEqual(4, drawable.GetPosition().Y);//checks getter

		}
		TEST_METHOD(RotationGetter)
		{
			CDrawableMock drawable(L"Harold");
			Assert::IsTrue(0 == drawable.GetRotation()); //checking default



			drawable.SetRotation(5); //checking set. 

			
			Assert::IsTrue(5 == drawable.GetRotation());//checks getter

		}
		TEST_METHOD(TestCDrawableAssociation)
		{
			CDrawableMock body(L"Body");
			auto arm = std::make_shared<CDrawableMock>(L"Arm");
			auto leg = std::make_shared<CDrawableMock>(L"Leg");

			body.AddChild(arm);
			body.AddChild(leg);

			Assert::IsTrue(arm->GetParent() == &body);
			Assert::IsTrue(leg->GetParent() == &body);
		}

	};
}