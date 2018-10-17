#include "../includes/Starfighter.hpp"
#include "../includes/Squad.hpp"
#include "../includes/Character.hpp"
#include "../includes/Droid.hpp"
#include <cstdlib>
#define COLS 10
#define ROWS 10

int main()
{
	Squad s;
	Enemy* e1;
	e1 = new Enemy(0, 0, 100, "random");
	Enemy* e2;
	e2 = new Enemy(0, 0, 100, "random");
	Enemy* e3;
	e3 = new Enemy(0, 0, 100, "random");
	Character player(COLS, ROWS);

	std::cout << "Player at "<< player.getX() << ", "<< player.getY()<< "\n";
	player.setX(5);
	player.setY(0);
	std::cout << "Player at "<< player.getX() << ", "<< player.getY()<< "\n";
	s.init_push(COLS, ROWS);
	s.push(e1);
	s.push(e2);
	s.push(e3);
	std::cout << "members: " << s.getCount() << "\n";
	for (int i = 0; i < s.getCount(); i++)
		std::cout << "enemy[" << i<<"]: type: "<< s.getUnit(i)->getType()<<" -coords: " << s.getUnit(i)->getX() << " , "<< s.getUnit(i)->getY()<< "\n";
	std::cout << "members: " << s.getCount() << "\n";


	while (s.getCount() > 0)
	{
		player.move(rand() % 2);
		player.shoot();
		s.move_all_enemies();
		player.move_all_bullets(s);
		if (player.collision(s))
		{
			std::cout << "GAME OVER\n";
			break;
		}
			std::cout << "members: " << s.getCount() << "\n";
		for (int i = 0; i < s.getCount(); i++)
			std::cout << "enemy[" << i<<"]: type: "<< s.getUnit(i)->getType()<<" -coords: " << s.getUnit(i)->getX() << " , "<< s.getUnit(i)->getY()<< "\n";
		std::cout << "members: " << s.getCount() << "\n";
	}


	s.delete_all();
	system("leaks -q ft_retro");
	return 0;
}
