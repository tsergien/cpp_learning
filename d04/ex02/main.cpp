#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;


	ISpaceMarine* j = new AssaultTerminator;
	ISpaceMarine* t = j;
	t->battleCry();
	j->battleCry();


	ISpaceMarine* a = new AssaultTerminator;
	ISpaceMarine* b (a);
	b->battleCry();

	system("leaks -q suicide");
	return 0;
}