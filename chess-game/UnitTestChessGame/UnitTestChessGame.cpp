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

template<> inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<Type>(const Type& t) 
{
	switch (t)
	{
	case Type::PAWN:
		return L"pawn";

	case Type::ROOK:
		return L"rook";

	case Type::KNIGHT:
		return L"horse";

	case Type::BISHOP:
		return L"bishop";

	case Type::QUEEN:
		return L"queen";

	case Type::KING:
		return L"king";

	default:
		break;
	}
}
template<> inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<Color>(const Color& t)
{
	switch (t)
	{
	case Color::WHITE:
		return L"white";

	case Color::BLACK:
		return L"black";

	case Color::NO_COLOR:
		return L"nocol";

	default:
		break;
	}
}
template<> inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<Position>(const Position& t)
{
	return ToString(t.get_row()) + ToString(t.get_col());
}
template<> inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<Player>(const Player& t)
{
	switch (t)
	{
	case Player::PLAYER_ONE:
		return L"pl1";

	case Player::PLAYER_TWO:
		return L"pl2";

	case Player::NO_PLAYER:
		return L"nopl";

	default:
		break;
	}
}
template<> inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<Figure>(const Figure& t)
{
	return ToString(t.get_type()) + ToString(t.get_color()) + ToString(t.get_position()) + ToString(t.get_owner());
}

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

			bool expected = true;
			bool actual = position.is_valid_position();

			Assert::AreEqual(expected, actual, L"Should be true, position is valid");
		}
	};

	TEST_CLASS(TestFigureClass)
	{
		TEST_METHOD(testFigureDefaulConstructorWithGivenTypeColorPositionOwnerTypeEqualsKing)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;

			Figure figure(type, color, position, owner);

			Type expected = Type::KING;
			Type actual = figure.get_type();

			Assert::AreEqual(expected, actual, L"Type should be King");
		}

		TEST_METHOD(testFigureDefaulConstructorWithGivenTypeColorPositionOwnerColorEqualsWhite)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;

			Figure figure(type, color, position, owner);

			Color expected = Color::WHITE;
			Color actual = figure.get_color();

			Assert::AreEqual(expected, actual, L"Type should be White");
		}

		TEST_METHOD(testFigureDefaulConstructorWithGivenTypeColorPositionOwnerPositionEqualsRowFourColumnThree)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position_figure(4, 3);
			Position position_other(4, 3);
			Player owner = Player::PLAYER_ONE;

			Figure figure(type, color, position_figure, owner);

			Position expected = position_other;
			Position actual = figure.get_position();

			Assert::AreEqual(expected, actual, L"Should be true, positions are the same");
		}

		TEST_METHOD(testFigureDefaulConstructorWithGivenTypeColorPositionOwnerEqualsPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;

			Figure figure(type, color, position, owner);

			Player expected = Player::PLAYER_ONE;
			Player actual = figure.get_owner();

			Assert::AreEqual(expected, actual, L"Should be player one");
		}

		TEST_METHOD(testFigureCopyConstructorGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::PAWN;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure_original(type, color, position, owner);

			Figure figure_copy(figure_original);

			Figure expected(figure_original);
			Figure actual(figure_copy);

			Assert::AreEqual(expected, actual, L"Should be the same figure");
		}

		TEST_METHOD(testFigureSetTypeMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);
			Type type_new = Type::KING;
			
			figure.set_type(type_new);

			Type expected = type_new;
			Type actual = figure.get_type();

			Assert::AreEqual(expected, actual, L"Should be king");
		}

		TEST_METHOD(testFigureGetTypeMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::PAWN;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);

			Type expected = Type::PAWN;
			Type actual = figure.get_type();

			Assert::AreEqual(expected, actual, L"Should be pawn");
		}

		TEST_METHOD(testFigureSetColorMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);
			Color color_new = Color::BLACK;
			
			figure.set_color(color_new);

			Color expected = color_new;
			Color actual = figure.get_color();

			Assert::AreEqual(expected, actual, L"Should be black");
		}

		TEST_METHOD(testFigureGetColorMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);

			Color expected = Color::WHITE;
			Color actual = figure.get_color();

			Assert::AreEqual(expected, actual, L"Should be white");
		}

		TEST_METHOD(testFigureSetPositionMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);
			Position position_new(2, 2);

			figure.set_position(position_new);

			Position expected = position_new;
			Position actual = figure.get_position();

			Assert::AreEqual(expected, actual, L"Should be position (2, 2)");
		}

		TEST_METHOD(testFigureGetPositionMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);

			Position expected = position;
			Position actual = figure.get_position();

			Assert::AreEqual(expected, actual, L"Should be the same position");
		}

		TEST_METHOD(testFigureSetOwnerMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);
			Player owner_new = Player::PLAYER_TWO;

			figure.set_owner(owner_new);

			Player expected = owner_new;
			Player actual = figure.get_owner();

			Assert::AreEqual(expected, actual, L"Should be player two");
		}

		TEST_METHOD(testFigureGetOwnerMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);

			Player expected = owner;
			Player actual = figure.get_owner();

			Assert::AreEqual(expected, actual, L"Should be player one");
		}

		TEST_METHOD(testFigureHasFigureBeenMovedMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);

			bool expected = false;
			bool actual = figure.has_figure_been_moved();

			Assert::AreEqual(expected, actual, L"Should be false");
		}

		TEST_METHOD(testFigureHasMovedMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);

			figure.has_moved();

			bool expected = true;
			bool actual = figure.has_figure_been_moved();

			Assert::AreEqual(expected, actual, L"Should be true");
		}

		TEST_METHOD(testFigureGetSymbolMethodGivenFigurePawnWhitePositionRowFourColumnThreeOwnerPlayerOne)
		{
			Type type = Type::KING;
			Color color = Color::WHITE;
			Position position(4, 3);
			Player owner = Player::PLAYER_ONE;
			Figure figure(type, color, position, owner);

			char expected = 'k';
			char actual = figure.get_symbol();

			Assert::AreEqual(expected, actual, L"should be k symbol for king");
		}
	};
}
