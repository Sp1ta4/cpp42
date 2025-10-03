#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <math.h>

class Fixed {
	private:
		int _value;
		static const int _bite = 8;

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};
	
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
	
#endif