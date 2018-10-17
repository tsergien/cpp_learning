#include <iostream>

struct Data 
{
	std::string	s1;
	int			n;
	std::string	s2;
};
/*
void * serialize( void )
{
	srand(time(0));
	char ar1[8];
	char ar2[8];
	int r = rand();

	std::string letters_numbers = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int size = letters_numbers.size();
	for (int i = 0; i < 8;i++)
	{
		ar1[i] = letters_numbers[(rand() + i) % size];
		ar2[i] = letters_numbers[(rand() + i + 2) % size];
		// ar1[i] = 'a';
		// ar2[i] = 'b';
	}
	char * array = new char[20];
	memcpy(array, ar1, 8);
	memcpy(array + 8, &r, 4);
	memcpy(array + 12, ar2, 8);
	return static_cast<void *>(array);
}

Data * deserialize(void * raw)
{
	Data *data = new Data;
	char *craw = static_cast<char *>(raw);
	for (int i = 0; i < 8; i++)
	{
		data->s1.append(1, craw[i]);
		data->s2.append(1, craw[12 + i]);//8 byte first array + 4 byte for int
	}
	memcpy(static_cast<void *>(&data->n), static_cast<void *>(&craw[8]), 4);
	delete [] craw;
	return data;
}*/

void * serialize( void )
{
	srand(time(0));
	int r = rand();
	// r = 9600;
	std::string letters_numbers = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int size = letters_numbers.size();
	char * array = new char[20];
	for (int i = 0; i < 8; i++)
	{
		array[i] = letters_numbers[(rand() + i) % size];
		array[12 + i] = letters_numbers[(rand() + i + 2) % size];
		// array[i] = 'a';
		// array[12 + i] /= 'b';
	}
	*(reinterpret_cast<int *>(array + 8)) = r;
	return static_cast<void *>(array);
}

Data * deserialize(void * raw)
{
	Data *data = new Data;
	char *craw = static_cast<char *>(raw);
	for (int i = 0; i < 8; i++)
	{
		data->s1 += craw[i];
		data->s2 += craw[12 + i];
	}
	data->n = *(reinterpret_cast<int *>(craw + 8));
	delete [] craw;
	return data;
}

int main()
{
	Data *data;
	data = deserialize(serialize());
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
	return 0;
}