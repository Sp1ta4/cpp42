#include "set.hpp"

set::set(searchable_bag& src) : bag(src) { }

set::~set(){}

const searchable_bag& set::get_bag() {
	return this->bag;
}

bool set::has(int n) const {
	return bag.has(n);
}

void set::print() const {
	bag.print();
}

void set::clear() {
	bag.clear();
}

void set::insert(int n) {
	if (!(this->has(n)))
		bag.insert(n);
}

void set::insert(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		this->insert(arr[i]);	
	}
}
