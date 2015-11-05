#include "stdafx.h"
#include <string>
#include "CppUnitTest.h"
#include "PolyDrawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(PolyDrawableTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(TestActorTestConstruct)
		{
			CPolyDrawable drawable(L"Harold");
		    Assert::AreEqual(std::wstring(L"Harold"), drawable.GetName());

		}
		TEST_METHOD(TestCPolyDrawableColor)
		{
			CPolyDrawable poly(L"Harold");
			Assert::IsTrue(255 == poly.GetColor().GetA());
			Assert::IsTrue(0 == poly.GetColor().GetB());
			Assert::IsTrue(0 == poly.GetColor().GetG());
			Assert::IsTrue(0 == poly.GetColor().GetR());

			poly.SetColor(Gdiplus::Color(0, 5, 5, 5));

			Assert::IsTrue(0 == poly.GetColor().GetA());
			Assert::IsTrue(5 == poly.GetColor().GetR());
			Assert::IsTrue(5 == poly.GetColor().GetG());
			Assert::IsTrue(5 == poly.GetColor().GetB());

		}

	};
}