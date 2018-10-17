#include <sstream>
#include <iostream>
#include <string>

/*int error(int er){
	std::cout << "Error.\n";
	if (er == 1)
		std::cout << "Invalid string.\n";
	else if (er == 2)
		std::cout << "Division by zero.\n";
	else if (er == 3)
		std::cout << "Wrong number of arguments.\n";
	else if (er == 4)
		std::cout << "Wrong number of brackets.\n";
	else if (er == 5)
		std::cout << "Wrong brackets.\n";
	exit(0);
	return (0);
}*/

std::string get_str_after_bracket(std::string s)
{
	int count = 0;
	int size = s.size();
	for (int j = 0; j < size; j++)
	{
		if (s[j] == '(')
			count++;
		if (s[j] == ')' && count > 0)
			count--;
		if (s[j] == ')' && count == 0)
			return s.substr(s.find("(") + 1, j - 1 - s.find("("));
	}
	return "";
}

long double	eval(std::string s)
{
	std::stringstream ss;
	std::string temp;
	long double arg1(0);

	ss << s;
	ss >> temp;
	float num;
	if (std::stringstream(temp) >> num)
		arg1 = num;
	if (temp == (std::string)"(")
	{
		arg1 = eval(get_str_after_bracket(s));
		ss >> temp;
	}
	temp = "";
	ss >> temp;
	if (temp.empty())
		return arg1;
	while (temp == (std::string)")")
	{
		temp = "";
		ss >> temp;
	}
	if (temp == (std::string)"+")
		return arg1 + eval(s.substr(s.find("+") + 1, s.size()));
	else if (temp == (std::string)"-")
		return arg1 - eval(s.substr(s.find("-") + 1, s.size()));
	else if (temp == (std::string)"*")
		return arg1 * eval(s.substr(s.find("*") + 1, s.size()));
	else if (temp == (std::string)"/")
	{
		long double res = eval(s.substr(s.find("/") + 1, s.size()));
		if (res == 0)
			return error(2);
		else
			return arg1 / eval(s.substr(s.find("/") + 1, s.size()));
	}
	if (temp.empty())
		return arg1;
	return error(3);
}

bool	valid(std::string s)
{
	if (s.empty())
		return 0;
	int count = 0;
	int count2 = 0;
	int pos = 0;
	while ((pos = s.find("(", pos)) != (int)std::string::npos)
	{
		s.replace(pos, 1, "_");
		count++;
		pos += 1;
	}
	pos = 0;
	while ((pos = s.find(")", pos)) != (int)std::string::npos)
	{
		s.replace(pos, 1, "_");
		count2++;
		pos += 1;
	}
	if (count != count2)
		return error(4);
	return 1;
}

std::string & insert_spaces(std::string & s)
{
	int s_size = s.size();
	int added = 0;;
	for (int i = 0; i < s_size + added; i++)
	if ((s[i] == '(' || s[i] == ')') && i - 1 > 0 && s[i - 1]!=' ' && i + 1 < s_size && s[ i + 1]!=' ')
	{
		s.insert(i, " ");
		s.insert(i+2, " ");
		added += 2;
	}
	std::cout << "s with spaces: " << s << std::endl;
	return s;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	std::cout << "hello\n";
	for (int i = 1; i < ac; i++)
	{
		long double res;
		std::string s = av[i];
		s = insert_spaces(s);
		res = eval(s);
		std::cout << res << "\n";
	}
	return 0;
}