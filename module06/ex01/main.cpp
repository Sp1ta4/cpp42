#include "Serializer.hpp"

int main(void)
{
	Data		a;
	Data		*b;
	uintptr_t	tmp;

	a.i = 42;
	a.c = 'a';

	std::cout << "serialize " << &a << std::endl;
	tmp = Serializer::serialize(&a);

	std::cout << "deserialize " << tmp << std::endl;
	b = Serializer::deserialize(tmp);

	std::cout << "i: " << b->i << " c: " << b->c << std::endl;

	if (&a == b)
	{
		std::cout << "before " << &a << std::endl;
		std::cout << "after " << b << std::endl;
		std::cout << "a->i: " << a.i << " a->c: " << a.c << std::endl;
		std::cout << "b->i: " << b->i << " b->c: " << b->c << std::endl;
	}
	else
	{
		std::cout << "failed\n" << std::endl;
	}

	return (0);
}