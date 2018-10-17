#ifndef BACKGROUND_HPP
# define BACKGROUND_HPP

#include <iostream>
#include "Character.hpp"
#include "Squad.hpp"

class Background {

private:

	int		_row;
	int		_col;
	char	**_window;

public:


	Background(void);
	Background(int row, int col, Character  & character);
	Background(Background const & background);
	~Background(void);

	void	feel_background(void);
	void	feel_with_playership(Character & character);
	void	feel_with_enemies(Squad & squad);
	char 	**getWindow(void);
	int		getRow(void) const;
	int		getCol(void) const;
	void	swap(int a);
};

#endif