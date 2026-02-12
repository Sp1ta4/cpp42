#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& src): tree_bag(src){}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& src) {
	if (this != &src)
		tree_bag::operator=(src);
	return *this;
}

bool searchable_tree_bag::has(int n) const {
	node *tree = this->tree;

	while (tree)
	{
		if (tree->value == n)
			return true;
		if (n > tree->value)
			tree = tree->r;
		else
			tree = tree->l;
	}
	return false;
}
