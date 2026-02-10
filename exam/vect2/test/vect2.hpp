#pragma once 

#include <iostream>

class vect2 {

	private:
		int x;
		int y;
	public:
	vect2();
	vect2(int, int);
	vect2(const vect2 &src);
	vect2& operator=(const vect2& src);
	~vect2();

	int  operator[](int) const;
	int& operator[](int);

	vect2 operator-() const;
	vect2 operator*(int) const;

	vect2& operator*=(int);
	
	vect2& operator*=(const vect2&);
	vect2& operator+=(const vect2&);
	vect2& operator-=(const vect2&);

	vect2 operator+(const vect2&) const;
	vect2 operator-(const vect2&) const;
	vect2 operator*(const vect2&) const;
	

	vect2& operator++();
	vect2 operator++(int);
	vect2& operator--();
	vect2 operator--(int);

	bool operator==(const vect2&) const;

	bool operator!=(const vect2&) const;
};

std::ostream& operator<<(std::ostream& ss, const vect2& v);
vect2 operator*(int, const vect2&);
