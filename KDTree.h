#ifndef _KDTree_H
#define _KDTree_H

#include <memory>
#include <algorithm>
#include <iterator>
#include <limits>
#include <utility>
#include "Point.h"
#include "Base_Node.h"

using std::shared_ptr;
using std::make_shared;
using std::numeric_limits;

template<typename T = float>
class KDTree {
public:
	//factory method to create tree
	static KDTree<T> makeTree(vector<Point<T>> list_points);

	//Constructors
	KDTree() = default;
	KDTree(shared_ptr<Base_Node<T> > root);
	
	//destructor
	~KDTree() = default;
	KDTree<T> left();
	KDTree<T> right();

	bool isEmpty() const;

	bool findPoint(const Point<T>& input_pt) const;
	bool nearestNeighbor(const Point<T>& input_pt, int & index, T& distance) const;

private:
	shared_ptr<Base_Node<T>> root_;
};

#include "KDTree.cpp"

#endif // !_KDTree_H

