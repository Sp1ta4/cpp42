#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "colors.hpp"

struct Data
{
	int		i;
	char	c;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		virtual ~Serializer();
};

#endif