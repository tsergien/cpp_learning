#include <iostream>
#include "../includes/Background.hpp"
#include <ncurses.h>

Background::Background() {
	_row = 0;
	_col = 0;
};

Background::Background(int row, int col, Character & character) {
	_window = new char*[row + 1];

	_row = row;
	_col = col;
	for (int i = 0; i < row; i++)
		_window[i] = new char[col + 1];
	feel_background();
	feel_with_playership(character);
}

Background::Background(Background const &background) :_row(background._row),
	_col(background._col), _window(background._window){};

Background::~Background() {
	delete [] _window;
}

void Background::feel_background() {
	int	turn = 0;
	int	lineforclouds = 1;
	int	cl = 0;

	for (int i = 0; i < _row; i++) {
		if (turn == 0) {
			cl = 0;
			if (i == lineforclouds + 2)
				cl = 1;
		}
		if (turn == 1) {
			cl = 5;
			if (i == lineforclouds + 2)
				cl = 6;
		}
		if (turn == 2) {
			cl = 9;
			if (i == lineforclouds + 2)
				cl = 10;
		}
		for (int j = 0; j < _col; j++) {
			if (i == lineforclouds && j >= cl && j <= cl + 3) {
				_window[i][j] = 'X';
				if (j == cl + 3)
					cl += 15;
			}
			else if (i == lineforclouds + 1 && j >= cl && j <= cl + 4) {
				_window[i][j] = 'X';
				if (j == cl + 4)
					cl += 15;
			}
			else if (i == lineforclouds + 2 && j >= cl && j <= cl + 2) {
				_window[i][j] = 'X';
				if (j == cl + 2)
					cl += 15;
			}
			else
				_window[i][j] = ' ';
			if (i == lineforclouds + 2 && j == _col - 1) {
				lineforclouds += 8;
				if (turn == 2)
					turn = 0;
				else
					turn++;
			}
		}
		_window[i][_col] = '\0';
	}
}

char	**Background::getWindow() {
	return _window;
}

void Background::feel_with_playership(Character &character) {
	int	x = character.getX();
	int	y = character.getY();

	_window[y][x] = 'o';
	_window[y][x + 1] = '>';
	_window[y + 1][x] = '/';
	_window[y - 1][x] = '\\';

	bull	*pos = character.getPos_bull();

	for (int i = 0; i < _col; i++)
		if (pos[i].x >= 0 && pos[i].y >= 0)
			_window[pos[i].y][pos[i].x] = '*';
}

int		Background::getRow(void) const {
	return _row;
}

int		Background::getCol(void) const {
	return _col;
}

void Background::feel_with_enemies(Squad &squad) {
	int		num = squad.getCount();
	int		x;
	int		y;
	Enemy	*enemy;

	for (int i = 0; i < num; i++) {
		enemy = squad.getUnit(i);
		x = enemy->getX();
		y = enemy->getY();
		char symb = enemy->getType();
		if (x >= getCol() || y >= getRow())
			return;
		_window[y][x] = symb;
		_window[y][x + 1] = symb;
		_window[y + 1][x] = symb;
		_window[y + 1][x + 1] = symb;
	}
}

void Background::swap(int a) {
	char	temp[a];
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _col; j++) {
			if (j == 0)
				for (int k = 0; k < a; k++)
					temp[k] = _window[i][j + k];
			if (j == _col - a)
				for (int k = 0; k < a; k++)
					_window[i][j++] = temp[k];
			else
				_window[i][j] = _window[i][j + a];
		}
	}
}

