#pragma once
#include <vector>

#include "Board.h"

//const
const int MAX_COMMAND_LENGHT = 15;

class Game
{
public:
	Game();
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	~Game();

public:
	void move(Position from, Position to);
	void start_game();
	void print_board_field();

private:
	Board* board_field;
	Player player_on_turn;

private:
	void clear();

	void set_board_field();

	void read_command();
	void execute_command(const char* command);
	bool is_print_command(const char* command) const;
	bool is_move_command(const char* command) const;
	bool is_valid_move_command(Position from, Position to);
	bool is_position_valid(Position position) const;
	bool is_position_occupied(Position position) const;
	bool is_selected_figure_player_on_turns_figure(Position position);

	void set_player_on_turn();
	Player get_player_on_turn() const;
	bool is_player_one_on_turn() const;

	void move_figure(Position from, Position to);
	void change_figure_position(Position from, Position to);
	bool can_figure_change_current_position(Position from, Position to);
	void set_all_possible_moves_for_figure(std::vector<Position>& all_possible_moves, Position position);

	bool is_king_under_attack() const;
};
