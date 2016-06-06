#ifndef _KDTree_cpp
#define _KDTree_cpp

#include "KDTree.h"
#include "Split_Node.h"

template<typename T>
KDTree<T>::KDTree(shared_ptr<Base_Node<T>> root):root_(root) {}

template<typename T>
KDTree<T> KDTree<T>::left(){
	return KDTree<T>(root_->left());
}

template<typename T>
KDTree<T> KDTree<T>::right(){
	return KDTree<T>(root_->right());
}

template<typename T>
bool KDTree<T>::isEmpty() const{
	return (root_ == nullptr);
}

template<typename T>
bool KDTree<T>::findPoint(const Point<T>& input_pt) const{
	if (root_ == nullptr)
		return nullptr;
	return (!root_->findPoint(input_pt));
}

template<typename T>
bool KDTree<T>::nearestNeighbor(const Point<T>& input_pt, int & index, T & distance) const{
	if (root_ == nullptr)
		return false;
	distance = numeric_limits<T>::max();
	//root_->nearestNeighbor(input_pt, index, distance);
	shared_ptr<Base_Node<T>> neighbour = nullptr;
	root_->nearestNeighbor(input_pt, neighbour, distance);
	return true;
}

template<typename T>
KDTree<T> KDTree<T>::makeTree(vector<Point<T>> list_points){
	if (list_points.size() > 0) {
		return KDTree(make_shared<Split_Node<T>>(list_points, 0));
	}
	return KDTree(nullptr);
}

#endif // !_KDTree_cpp
