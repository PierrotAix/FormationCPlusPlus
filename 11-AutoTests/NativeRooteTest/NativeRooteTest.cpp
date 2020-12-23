#include "pch.h"
#include "CppUnitTest.h"
#include "..\RootFinder\RootFinder.h"
#include <stdexcept>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std; 

namespace NativeRooterTest
{
	TEST_CLASS(NativeRooterTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(BasicTest) 
		{
			CRootFinder rooter;
			Assert::AreEqual(
				// Expected value:
				0.0,
				// Actual value:
				rooter.SquareRoot(0.0),
				// Tolerance
				0.01,
				// Message:
				L"Basic test failed",
				// Line number - used in there is no PDB files:
				LINE_INFO()
			);
		}

		TEST_METHOD(RangeTest)
		{
			CRootFinder rooter;
			for (double v = 1e-6; v < 1e6; v = v * 3.2)
			{
				double actual = rooter.SquareRoot(v * v);
				Assert::AreEqual(v, actual, v / 1000);
			}
		}

		/// <summary>
		/// Verify that negative throw an exception
		/// </summary>
		TEST_METHOD(NegativeRangeTest)
		{
			wchar_t message[200];
			CRootFinder rooter;
			for (double v = -0.1; v > -3.0; v = v - 0.5)
			{
				try
				{
					// should raise an exception:
					double result = rooter.SquareRoot(v);

					_swprintf(message, L"No exception for input %g",v);
					Assert::Fail(message, LINE_INFO());
				}
				catch (std::out_of_range ex)
				{
					continue; // Correct exception.
				}
				catch (...)
				{
					_swprintf(message, L"Incorrect exception for input %g", v);
					Assert::Fail(message, LINE_INFO());
				}
			}
		}

		TEST_METHOD(Test_AdditionWithDoubles_GetCorrectSum)
		{
			// Arrange
			CRootFinder lRooter;
			double lExpected = 5.0;

			// Act
			double lActual = lRooter.Addition(3.0, 2.0);

			// Assert
			Assert::AreEqual(lExpected, lActual);
		}

		TEST_METHOD(Test_GetLine_WithSimpleExeFile_GetCorrectLine)
		{
			// Arrange
			CRootFinder lRooter;
			string lHeading{ "TMI"s };
			string lKeyword{ "BU2"s };
			string lRoot{ "..\\..\\..\\TestFiles\\"s };
			string lRelativeFilePath{ "Line_haspdinst.exe"s };
			string lExpectedResultLine{ "TMI;BU2;1;Line_haspdinst.exe;;(Ox39=-\u009bÒ\u0087Å\\\u0094IMEH5BU2\"#ç¢Ìñ\u0096\u0094.\\Ê-);VRAI;FAUX;"s };
			lExpectedResultLine = "Resultat" ;

			// Act
			string lResultLine = lRooter.GetLine(lHeading, lKeyword, lRoot, lRelativeFilePath, "");
			//cout << lResultLine << " : " << lExpectedResultLine << endl; 
			// Assert
			Assert::AreEqual(lExpectedResultLine, lResultLine);
		}

		TEST_METHOD(Test_GetNumberOfCharactersOfFile_WithSimpleFile_GetCorrectLine)
		{
			// Arrange
			CRootFinder lRooter;
			string lRelativeFilePath{ "C:\\Dev\\C++\\Github\\FormationCPlusPlus\\11-AutoTests\\RootFinder\\valeurs.txt"s };
			int lExpectedResultLine;
			lExpectedResultLine = 37;

			// Act
			int lResultLine = lRooter.GetNumberOfCharactersOfFile(lRelativeFilePath);
			// Assert
			Assert::AreEqual(lExpectedResultLine, lResultLine);
		}
	};
}
