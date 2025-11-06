#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
	private:
	    T		*_data;
	    size_t	_size;
	
	public:
	    Array();
	    Array(size_t n);
	    Array(const Array& other);
	    ~Array();
	
	    Array& operator=(const Array& other);
	
	    size_t size() const;
	    T& operator[](size_t i);
	    const T& operator[](size_t i) const;
};

#include "Array.tpp"

#endif
