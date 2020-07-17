#pragma once

/// This is Position class
///
/// This class is about position of any piece on the board field.
/// Through this class piece can change position and have position
class Position
{
public:
	Position();
	Position(int row, int col);
	Position(const Position& other);
	Position& operator=(const Position& other);
	~Position();

public: 
	bool operator==(const Position& rhs);

public:
	void set_row(int& position);
	void set_col(int& position);

	int get_row() const;
	int get_col() const;

	bool is_valid_position();
	//bool is_valid_position(int& row, int& col);
	//bool is_valid_position(const Position& position);

private:
	int row;
	int col;

private:
	void set_position(int row, int col);
};
