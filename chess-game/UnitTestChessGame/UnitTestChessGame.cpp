#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <string>
using namespace std;

#include "../chess-game/Square.h"
#include "../chess-game/Board.cpp"
#include "../chess-game/Square.cpp"
#include "../chess-game/Position.cpp"

#include "../chess-game/Figure.cpp"
#include "../chess-game/Pawn.cpp"
#include "../chess-game/Rook.cpp"
#include "../chess-game/Horse.cpp"
#include "../chess-game/Bishop.cpp"
#include "../chess-game/Queen.cpp"
#include "../chess-game/King.cpp"

#include "../chess-game/Game.cpp"

#include "../chess-game/AllDirectionsOneStepMovement.cpp"
#include "../chess-game/DiagonalMovement.cpp"
#include "../chess-game/ExtendedDiagonalMovement.cpp"
#include "../chess-game/ForwardMovement.cpp"
#include "../chess-game/HorizontalMovement.cpp"
#include "../chess-game/VerticalMovement.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestChessGame
{
	TEST_CLASS(TestPositionClass)
	{
	public:

		TEST_METHOD(testPositionDefaultConstructorRowEqualsZero)
		{
			Position position;
			int expected = 0;
			int actual = position.get_row();

			Assert::AreEqual(expected, actual, L"Row should equals to zero");
		}

		TEST_METHOD(testPositionDefaultConstructorColumnEqualsZero)
		{
			Position position;
			int expected = 0;
			int actual = position.get_col();

			Assert::AreEqual(expected, actual, L"Column should equals to zero");
		}

		TEST_METHOD(testPositionConstructorByGivenValueFrowRowAndColulmnRowEqualFive)
		{
			int row = 5, col = 6;

			Position position(row, col);
			int expected = 5;
			int actual = position.get_row();

			Assert::AreEqual(expected, actual, L"Row should equals to five");
		}

		TEST_METHOD(testPositionConstructorByGivenValueFrowRowAndColulmnColEqualFive)
		{
			int row = 6, col = 5;

			Position position(row, col);
			int expected = 5;
			int actual = position.get_col();

			Assert::AreEqual(expected, actual, L"Column should equals to five");
		}

		TEST_METHOD(testPositionCopyConstructorByGivenPositionWithRowFiveColumnSixRowShouldEqualsFive)
		{
			Position position_original(5, 6);

			Position position_copy(position_original);
			int expected = 5;
			int actual = position_copy.get_row();

			Assert::AreEqual(expected, actual, L"Row should equals to five");
		}

		TEST_METHOD(testPositionCopyConstructorByGivenPositionWithRowSicColumnFiveColumnShouldEqualsFive)
		{
			Position position_original(6, 5);

			Position position_copy(position_original);
			int expected = 5;
			int actual = position_copy.get_col();

			Assert::AreEqual(expected, actual, L"Column should equals to five");
		}

		TEST_METHOD(testPositionOperatorEqualByGivenPositionWithRowFiveColumnSixRowShouldEqualsFive)
		{
			Position position_first(9, 9);
			Position position_second(5, 6);
			position_first = position_second;

			int expected = 5;
			int actual = position_first.get_row();

			Assert::AreEqual(expected, actual, L"Row should equals to five");

		}

		TEST_METHOD(testPositionOperatorEqualByGivenPositionWithRowsixColumnFiveColumnShouldEqualsFive)
		{
			Position position_first(9, 9);
			Position position_second(6, 5);
			position_first = position_second;

			int expected = 5;
			int actual = position_first.get_col();

			Assert::AreEqual(expected, actual, L"Column should equals to five");
		}

		TEST_METHOD(testPositionOperatorEqualEqualByGivenTwoDifferentPositions)
		{
			Position position_first(1, 2);
			Position position_second(3, 4);

			bool expected = false;
			bool actual = (position_first == position_second);

			Assert::AreEqual(expected, actual, L"Should be false");
		}

		TEST_METHOD(testPositionOperatorEqualEqualByGivenTwoSamePositions)
		{
			Position position_first(3, 4);
			Position position_second(3, 4);

			bool expected = true;
			bool actual = (position_first == position_second);

			Assert::AreEqual(expected, actual, L"Should be true");
		}

		TEST_METHOD(testPositionSetRowGivenPositionRowFiveColumnFiveRowEqualsTwo)
		{
			Position position(5, 5);
			int new_row = 2;

			position.set_row(new_row);

			int expected = 2;
			int actual = position.get_row();

			Assert::AreEqual(expected, actual, L"Row should be equals to two");
		}

		TEST_METHOD(testPositionSetColGivenPositionRowFiveColumnFiveColumnEqualsTwo)
		{
			Position position(5, 5);
			int new_col = 2;

			position.set_col(new_col);

			int expected = 2;
			int actual = position.get_col();

			Assert::AreEqual(expected, actual, L"Column should be equals to two");
		}

		TEST_METHOD(testPositionGetRowGivenPositionRowFiveColumnFiveRowEqualsFive)
		{
			Position position(5, 5);

			int exprected = 5;
			int actual = position.get_row();

			Assert::AreEqual(exprected, actual, L"Row should be five");
		}

		TEST_METHOD(testPositionGetColGivenPositionRowFiveColumnFiveColumnEqualsFive)
		{
			Position position(5, 5);

			int exprected = 5;
			int actual = position.get_col();

			Assert::AreEqual(exprected, actual, L"Column should be five");
		}

		TEST_METHOD(testPositionIsValidPositionGivenInvalidPosition)
		{
			Position position(10, 10);

			bool expected = false;
			bool actual = position.is_valid_position();

			Assert::AreEqual(expected, actual, L"Should be false, position is invalid");
		}

		TEST_METHOD(testPositionIsValidPositionGivenValidPosition)
		{
			Position position(5, 3);

			bool expected = false;
			bool actual = position.is_valid_position();

			Assert::AreEqual(expected, actual, L"Should be true, position is valid");
		}
	};
}
