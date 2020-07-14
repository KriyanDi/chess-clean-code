#pragma once

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

private:
	int row;
	int col;

private:
	void set_position(int row, int col);
};
