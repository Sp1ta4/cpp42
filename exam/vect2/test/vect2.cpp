#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::~vect2() {}

vect2::vect2(int a, int b) : x(a), y(b) {}

vect2::vect2(const vect2& src) {
	*this = src;
}

vect2& vect2::operator=(const vect2 &src) {
	if (this != &src)
	{
		this->x = src.x;
		this->y = src.y;
	}
	return *this;
}

int vect2::operator[](int i) const {
	if (i == 0)
		return this->x;
	return this->y;
}

int& vect2::operator[](int i) {
	if (i == 0)
		return this->x;
	return this->y;
}

vect2 vect2::operator*(int n) const {
	vect2 res(*this);

	res.x *= n;
	res.y *= n;
	return res;
}

vect2& vect2::operator*=(int n) {
	this->x *= n;
	this->y *= n;
	return *this;
}

vect2 vect2::operator*(const vect2& n) const {
	vect2 res(this->x * n.x, this->y * n.y);
	return res;
}

vect2& vect2::operator*=(const vect2& n) {
	this->x *= n.x;
	this->y *= n.y;
	return *this;
}

vect2 vect2::operator+(const vect2& n) const {
	vect2 res(this->x + n.x, this->y + n.y);
	return res;
}

bool vect2::operator==(const vect2& n) const{
	return ((this->x == n.x) && (this->y == n.y));
}

bool vect2::operator!=(const vect2& n) const {
	return !(*this == n);
}

vect2 vect2::operator-(const vect2& n) const {
	vect2 res(this->x - n.x, this->y - n.y);
	return res;
}

vect2& vect2::operator+=(const vect2& n) {
	this->x += n.x;
	this->y += n.y;
	return *this;
}

vect2& vect2::operator-=(const vect2& n) {
	this->x -= n.x;
	this->y -= n.y;
	return *this;
}

vect2& vect2::operator++() {
	this->x += 1;
	this->y += 1;
	return *this;
}

vect2& vect2::operator--() {
	this->x -= 1;
	this->y -= 1;
	return *this;
}

vect2 vect2::operator++(int) {
	return ++(*this);
}

vect2 vect2::operator--(int) {
	return --(*this);
}

vect2 vect2::operator-() const {
	vect2 res(-(this->x), -(this->y));
	return res;
}

std::ostream& operator<<(std::ostream &ss, const vect2& v) {
	ss << "{" << v[0] << ", " << v[1] << "}";
	return ss;
}

vect2 operator*(int n, const vect2& v){
	return v * n;
}
