#include "Game.h"
#include <iostream>

Game::Game()
{
	set_board_field();
	set_player_on_turn();
}

Game::~Game()
{
	clear();
}

void Game::move(Position& from, Position& to)
{
	move_figure(from, to);
}

void Game::start_game()
{
	print_board_field();
	read_command();
}

void Game::print_board_field()
{
	//system("CLS");
	this->board_field->print_board_field_view();
}

Board* Game::get_board_field()
{
	return this->board_field;
}

void Game::clear()
{
	delete this->board_field;
}

void Game::set_board_field()
{
	this->board_field = new Board;
	if (!board_field)
	{
		std::cout << "Problem allocating memory for board field!\n";
	}
}

void Game::read_command()
{
	while (true)
	{
		std::cout << std::endl;
		print_command_line();
		char* command = new char[MAX_COMMAND_LENGHT];
		std::cin.getline(command, MAX_COMMAND_LENGHT, '\n');
		execute_command(command);
		delete[] command;
	}
}

void Game::print_command_line()
{
	if (get_player_on_turn() == Player::PLAYER_ONE)
	{
		std::cout << "player one> ";
	}
	else
	{
		std::cout << "player two> ";
	}
}

void Game::execute_command(const char* command)
{
	if (is_print_command(command))
	{
		this->print_board_field();
	}
	else if (is_move_command(command))
	{
		Position from(command[5] - '0', command[7] - '0');
		Position to(command[9] - '0', command[11] - '0');

		if (is_valid_move_command(from, to))
		{
			move(from, to);
		}
		else
		{
			std::cout << "Invalid move command!\n";
		}

		this->print_board_field();
	}
	else
	{
		std::cout << "Invalid command! \n";
	}
}

char* Game::extract_command(const char* command) const
{
	char exctracted_command[10];
	if (!exctracted_command)
	{
		std::cout << "Problem allocating memory for Exctracted word!\n";
	}


	for (int i = 0; i < strlen(command); i++)
	{
		if (command[i] == ' ')
		{
			exctracted_command[i] = '\0';
			break;
		}
		
		exctracted_command[i] = command[i];
	}

	return exctracted_command;
}

bool Game::is_print_command(const char* command) const
{
	if (strcmp(extract_command(command), "print") == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::is_move_command(const char* command) const
{
	if (strcmp(extract_command(command), "move") == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::is_valid_move_command(Position& from, Position& to)
{
	if (is_position_valid(from) && is_position_valid(to) &&
		is_position_occupied(from) && is_selected_figure_player_on_turns_figure(from))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::is_position_valid(Position& position) const
{
	if (position.is_valid_position())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::is_position_occupied(Position& position) const
{
	if (board_field->get_figure(position))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::is_selected_figure_player_on_turns_figure(Position& position)
{
	if (this->get_player_on_turn() == this->board_field->get_figure(position)->get_color())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::set_player_on_turn()
{
	this->player_on_turn = Player::PLAYER_ONE;
}

void Game::change_player_on_turn()
{
	if (is_player_one_on_turn())
	{
		player_on_turn = Player::PLAYER_TWO;
	}
	else
	{
		player_on_turn = Player::PLAYER_ONE;
	}
}

Player Game::get_player_on_turn() const
{
	if (is_player_one_on_turn())
	{
		return Player::PLAYER_ONE;
	}
	else
	{
		return Player::PLAYER_TWO;
	}
}

bool Game::is_player_one_on_turn() const
{
	if (this->player_on_turn == Player::PLAYER_ONE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::move_figure(Position& from, Position& to)
{
	if (can_figure_change_current_position(from, to))
	{
		change_figure_position(from, to);
		change_player_on_turn();
	}
	else if (is_king_under_attack())
	{
		std::cout << "Your King is under attack!\n";
	}
	else
	{
		std::cout << "You can not move your figure there!\n";
	}
}

void Game::change_figure_position(Position& from, Position& to)
{
	this->board_field->remove_figure(to);
	this->board_field->set_figure(to, this->board_field->get_figure(from));
	this->board_field->remove_figure(from);
	this->board_field->get_figure(to)->has_moved();
}

bool Game::can_figure_change_current_position(Position& from, Position& to)
{
	std::vector<Position> all_posible_moves;
	set_all_possible_moves_for_figure(all_posible_moves, from);
	for (std::vector<Position>::iterator it = all_posible_moves.begin(); it != all_posible_moves.end(); it++)
	{
		if ((*it) == to)
		{
			return true;
		}
	}

	return false;
}

void Game::set_all_possible_moves_for_figure(std::vector<Position>& all_possible_moves, Position& position)
{
	all_possible_moves = this->board_field->get_figure(position)->get_all_possible_moves(this);
}

bool Game::is_king_under_attack() const
{
	return false;
}


