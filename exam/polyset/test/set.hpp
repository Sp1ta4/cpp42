#pragma once
#include "searchable_bag.hpp"

class set {
	private:
		searchable_bag& bag;
	public:
		set() = delete;
		set(const set&) = delete;
		set& operator=(const set&) = delete;
		set(searchable_bag&);

		bool has(int) const;
		void print() const;
		void insert(int);
		void insert(int*, int);
		void clear();

		const searchable_bag& get_bag();

		~set();
};
