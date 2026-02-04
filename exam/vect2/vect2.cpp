#include "vect2.hpp"

vect2::vect2(): x(0), y(0)
{}


vect2::vect2(int num1, int num2): x(num1), y(num2)
{}

vect2::vect2(const vect2& source) {
	*this = source;
}

vect2& vect2::operator=(const vect2& source) {
	if (this != &source)
	{
		this->x = source.x;
		this->y = source.y;
	}
	return *this;
}

int vect2::operator[](int index) const {
	if(index == 0)
		return(this->x);
	return(this->y);
}

int& vect2::operator[](int index) {
	if(index == 0)
		return(this->x);
	return(this->y);
}


vect2 vect2::operator-() const {
	vect2 res(-(this->x), -(this->y));
	return res;
}

vect2 vect2::operator*(int num) const {
	vect2 res((this->x) * num, (this->y) * num);
	return res;
}


vect2& vect2::operator*=(int num)
{
	this->x *= num;
	this->y *= num;
	return *this;
}

vect2& vect2::operator+=(const vect2& obj) {
	this->x += obj.x;
	this->y += obj.y;
	return *this;
}

vect2& vect2::operator-=(const vect2& obj){
	this->x -= obj.x;
	this->y -= obj.y;
	return *this;

}
vect2& vect2::operator*=(const vect2& obj){
	this->x *= obj.x;
	this->y *= obj.y;
	return *this;
}

vect2 vect2::operator+(const vect2& obj) const {
	vect2 res(*this);

	res.x = this->x + obj.x;
	res.y = this->y + obj.y;
	return res;
}
vect2 vect2::operator-(const vect2& obj) const {
	vect2 res(*this);

	res.x = this->x - obj.x;
	res.y = this->y - obj.y;
	return res;
}
vect2 vect2::operator*(const vect2& obj) const {
	vect2 res(*this);

	res.x = this->x * obj.x;
	res.y = this->y * obj.y;
	return res;
}

vect2& vect2::operator++() {
	this->x += 1;
	this->y += 1;
	return *this;
}

vect2  vect2::operator++(int) {
	vect2 res(*this);
	++(*this);
	return res;
}

vect2& vect2::operator--() {
	this->x -= 1;
	this->y -= 1;
	return *this;
}

vect2  vect2::operator--(int) {
	vect2 res(*this);
	--(*this);
	return res;
}

bool vect2::operator==(const vect2& obj) const {
	return ((this->x == obj.x) && (this->y == obj.y));
}

bool vect2::operator!=(const vect2& obj) const {
	return ((this->x != obj.x) && (this->y != obj.y));
}

vect2 operator*(int num, const vect2& obj) {
	return obj * num;
}

std::ostream& operator<<(std::ostream& os,const vect2& obj) {
    os << "{" << obj[0] << ", " << obj[1] << "}";
	return os;
}
vect2::~vect2() {

}