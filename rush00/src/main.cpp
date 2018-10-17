#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "../includes/Background.hpp"

//up - 259
//down - 258
//right - 261
//left -260
//space - 32
//escape - 27

 int		main() {
 	int			row;
 	int			col;
 	int			ch;
 	char		**window;
 	Background	*back;
 	Character	*ship;
 	Squad		squad;

	initscr();
	keypad(stdscr, true);
	getmaxyx(stdscr, row, col);
	nodelay(stdscr, true);
	curs_set(0);
	noecho();
 	//  squad.init_push(col, row);
 	ship = new Character(col, row);
 	back = new Background(row, col, *ship);
	 start_color();
	 init_pair(1, COLOR_BLACK, COLOR_RED);
	 init_pair(2, COLOR_CYAN, COLOR_BLACK);
	 init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	 init_pair(4, COLOR_GREEN, COLOR_BLACK);
 	ch = 0;

 	bool end_game = true;
	int	a = 0;

	while (end_game == true) {
		ch = getch();
		if (ch == 27)
			end_game = false;
		if (ch == 32)
			ship->shoot();
		else if (ch == KEY_UP)
			ship->move(2);
		else if (ch == KEY_DOWN)
			ship->move(1);
		back->feel_background();
		a++;
 		if (a == col)
 			a = 1;
		back->swap(a);
		back->feel_with_playership(*ship);
		back->feel_with_enemies(squad);
		window = (*back).getWindow();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (window[i][j] == '*' || window[i][j] == '\\' || window[i][j] == '/' || window[i][j] == '>') {
					attron(COLOR_PAIR(4));
					addch(window[i][j] | A_BOLD);
					attroff(COLOR_PAIR(4));
				}
				else if (window[i][j] == '<' || window[i][j] == 'o') {
					attron(COLOR_PAIR(1));
					addch(window[i][j] | A_BOLD | A_STANDOUT);
					attroff(COLOR_PAIR(1));
				}
				else if (window[i][j] == 'X') {
					attron(COLOR_PAIR(2));
					addch('.');
					attroff(COLOR_PAIR(2));
				}
				else
					addch(window[i][j]);
			}
		}
		if (ship->collision(squad))
			end_game = false;
		ship->move_all_bullets(squad);
		squad.move_all_enemies();
		if (ship->getKilled() >= 30)
			end_game = false;
		if (squad.getCount() < 5)
			squad.push(Enemy::random(col - 1, rand() % row));
		wmove(stdscr, 0, 0);
		usleep(70000);
	}
	getch();
	endwin();

 	return 0;
}
