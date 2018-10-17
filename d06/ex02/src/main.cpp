#include <iostream>

class Base
{
public:
	virtual ~Base() {}
};

class A : public Base {
public: 	std::string name() const {return "A";}
};
class B : public Base {
public: 	std::string name() const {return "B";}
};
class C : public Base {
public: std::string name() const {return "C";}
};

Base * generate(void)
{
	Base *res;
	int r = rand() % 3;
	switch(r)
	{
		case 0:
			res = new A;
			break;
		case 1:
			res = new B;
			break;
		case 2:
			res = new C;
			break;
	}
	return res;
}

void identify_from_pointer( Base * p )
{
	A *a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << a->name() << std::endl;
		return ;
	}

	B *b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << b->name() << std::endl;
		return ;
	}

	C *c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << c->name() << std::endl;
		return ;
	}
}

void identify_from_reference( Base & p )
{
	try
	{
		A& a = dynamic_cast<A &>(p);
		std::cout << a.name() << std::endl;
	}
	catch (const std::bad_cast& e)
	{
		try
		{
			B& b = dynamic_cast<B &>(p);
			std::cout << b.name() << std::endl;
		}
		catch (const std::bad_cast& e)
		{
			try
			{
				C& c = dynamic_cast<C &>(p);
				std::cout << c.name() << std::endl;
			}
			catch (const std::bad_cast& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
}

int main()
{
	srand(time(0));
	Base *ptr = generate();
	identify_from_pointer(ptr);

	identify_from_reference(*ptr);

	return 0;
}