#include "TextMode.hpp"
#include "OsInfoModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"
#include "HostnameModule.hpp"
#include "RAMModule.hpp"
#include "DiskModule.hpp"
#include "NetworkModule.hpp"
#include <curses.h>

TextMode::TextMode(){}
TextMode::TextMode(TextMode const &other){*this = other;}
TextMode::~TextMode(){}
TextMode  & TextMode::operator=(TextMode const &other)
{
	_str = other._str;
	return *this;
}

void 		TextMode::initialize()
{
	initscr();
	curs_set(FALSE);
	cbreak();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	noecho();

	int nlines = 7;
	int ncols = 50;
	int x = 10;
	int y = 5;

	WINDOW * winstart = newwin(3, ncols, 2, x);
	WINDOW * winH = newwin(nlines - 2, ncols, y, x);
	WINDOW * winOs = newwin(nlines - 2, ncols, y-2 + nlines, x);
	WINDOW * winD = newwin(nlines - 2, ncols, y-4 + 2 * nlines, x);
	WINDOW * winC = newwin(nlines + 2, ncols, y-6 + 3 * nlines, x);
	WINDOW * winR = newwin(nlines + 2, ncols, y-4 + 4 * nlines, x);
	WINDOW * winN = newwin(nlines - 2, ncols, y - 2+ 5 * nlines, x);
	WINDOW * winDi = newwin(nlines + 2, ncols, y - 4 + 6 * nlines, x);

	HostnameModule	hostname;
	OsInfoModule os;
	DateTimeModule date;
	CPUModule cpu;
	RAMModule ram;
	DiskModule disk;
	NetworkModule net;

	hostname.set_data();
	os.set_data();
	date.set_data();
	disk.set_data();

	while(1)
	{
		box(winstart, 0, 0);
		mvwprintw(winstart, 1, 14, "*** FT_GKRELLM ***");
		wrefresh(winstart);


		box(winH, 0, 0);
		attron(A_BOLD);
		mvwprintw(winH, 2, 2, "Username:");
		attroff(A_BOLD);
		mvwprintw(winH, 2, 23, "%s", hostname.get_user());
		mvwprintw(winH, 3, 2, "Hostname:");
		mvwprintw(winH, 3, 23, "%s", hostname.get_host());
		wrefresh(winH);

		box(winOs, 0, 0);
		attron(A_BOLD);
		mvwprintw(winOs, 1, 20, "OS info");
		attroff(A_BOLD);
		mvwprintw(winOs, 2, 2, "System version: ");
		mvwprintw(winOs, 2, 23, "%s", os.get_system_version());
		mvwprintw(winOs, 3, 2, "Kernel version: ");
		mvwprintw(winOs, 3, 23, "%s", os.get_kernel_version());
		wrefresh(winOs);

		box(winD, 0, 0);
		date.set_data();
		attron(A_BOLD);
		mvwprintw(winD, 1, 20, "Date/Time");
		attroff(A_BOLD);
		mvwprintw(winD, 2, 2, "Date:");
		mvwprintw(winD, 2, 23, "%s", date.get_date());
		mvwprintw(winD, 3, 2, "Time:");
		mvwprintw(winD, 3, 23, "%s", date.get_time());
		wrefresh(winD);

		box(winC, 0, 0);
		cpu.set_data();
		attron(A_BOLD);
		mvwprintw(winC, 1, 20, "CPU");
		attroff(A_BOLD);
		mvwprintw(winC, 2, 2, "ModelCPU: ");
		mvwprintw(winC, 2, 23, "%s", cpu.get_modelCPU());
		mvwprintw(winC, 3, 2, "Clock speed: ");
		mvwprintw(winC, 3, 23, "%s", cpu.get_clockSpeed());
		mvwprintw(winC, 4, 2, "Cores: ");
		mvwprintw(winC, 4, 23, "%s", cpu.get_cores());
		mvwprintw(winC, 5, 2, "User activity: ");
		mvwprintw(winC, 5, 23, "%s", cpu.get_userActivity());
		mvwprintw(winC, 6, 2, "System activity: ");
		mvwprintw(winC, 6, 23, "%s", cpu.get_sysActivity());
		mvwprintw(winC, 7, 2, "Idle activity: ");
		mvwprintw(winC, 7, 23, "%s", cpu.get_idleActivity());
		wrefresh(winC);

		box(winR, 0, 0);
		ram.set_data();
		attron(A_BOLD);
		mvwprintw(winR, 1, 20, "RAM");
		attroff(A_BOLD);
		mvwprintw(winR, 2, 2, "Size: ");
		mvwprintw(winR, 2, 23, "%s", ram.get_size());
		mvwprintw(winR, 3, 2, "Type: ");
		mvwprintw(winR, 3, 23, "%s", ram.get_type());
		mvwprintw(winR, 4, 2, "Speed: ");
		mvwprintw(winR, 4, 23, "%s", ram.get_speed());
		mvwprintw(winR, 5, 2, "Used: ");
		mvwprintw(winR, 5, 23, "%s", ram.get_used());
		mvwprintw(winR, 6, 2, "Wired: ");
		mvwprintw(winR, 6, 23, "%s", ram.get_wired());
		mvwprintw(winR, 7, 2, "Unused: ");
		mvwprintw(winR, 7, 23, "%s", ram.get_unused());
		wrefresh(winR);
		
		box(winN, 0, 0);
		net.set_data();
		attron(A_BOLD);
		mvwprintw(winN, 1, 20, "Network");
		attroff(A_BOLD);
		mvwprintw(winN, 2, 2, "Packets in: ");
		mvwprintw(winN, 2, 23, "%s", net.get_in());
		mvwprintw(winN, 3, 2, "Packets out: ");
		mvwprintw(winN, 3, 23, "%s", net.get_out());
		wrefresh(winN);

		box(winDi, 0, 0);
		disk.set_data();
		mvwprintw(winDi, 1, 20, "Disk");
		mvwprintw(winDi, 2, 2, "Disk: ");
		mvwprintw(winDi, 2, 15, "Size: ");
		mvwprintw(winDi, 2, 23, "Used: ");
		mvwprintw(winDi, 2, 30, "Avail: ");
		mvwprintw(winDi, 2, 38, "Capacity: ");
		for (unsigned i = 0; i < disk.get_n(); i++)
		{
			mvwprintw(winDi, 3 + i, 2, "%s", disk.get_name(i));
			mvwprintw(winDi, 3 + i, 15, "%s", disk.get_size(i));
			mvwprintw(winDi, 3 + i, 23, "%s", disk.get_used(i));
			mvwprintw(winDi, 3 + i, 30, "%s", disk.get_available(i));
			mvwprintw(winDi, 3 + i, 40, "%s", disk.get_capacity(i));
		}
		wrefresh(winDi);

		usleep(DELAY);
	}

}