#ifndef _Point_Node_cpp
#define _Point_Node_cpp

#include "Point_Node.h"

using std::begin;
using std::end;
using std::transform;

template<typename T>
Point_Node<T>::Point_Node(const Point<T>& point):point_(point) {
}


template<typename T>
bool Point_Node<T>::findPoint(const Point<T>& input_pt) const
{
	if (input_pt.getFeautureVector() == point_.getFeautureVector()) {
		return true;
	}
	return false;
}
/*
template<typename T>
shared_ptr<Base_Node<T>> Point_Node<T>::nearestNeighbor(const Point<T>& input_pt)
{
	return shared_from_this();
}*/

template<typename T>
T Point_Node<T>::distance(const shared_ptr<Base_Node<T>>& pt2){
	vector<T> pt1Feature = point_.getFeautureVector();
	vector<T> pt2Feature = pt2->getPoint().getFeautureVector();
	transform(begin(pt1Feature), end(pt1Feature), begin(pt2Feature), begin(pt1Feature), []
									(auto v1, auto v2) {
									return (v1 - v2) * (v1 - v2);
									});
	
	T dist = sqrtf(std::accumulate(begin(pt1Feature), end(pt1Feature), 0));
	return dist;
}
template<typename T>
Point<T> Point_Node<T>::getPoint() const{
	return point_;
}

template<typename T>
void Point_Node<T>::nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>>& best_neighbor, T& best_dist){
	T current_dist = this->point_.distance(input_pt);
	if (current_dist < best_dist) {
		best_dist = current_dist;
		best_neighbor = shared_from_this();
	}
}


template<typename T>
void Point_Node<T>::nearestNeighbor(const Point<T>& input_pt, int& best_neighbor, T& best_dist)const {
	T current_dist = point_.distance(input_pt);
	if (current_dist < best_dist) {
		best_dist = current_dist;
		best_neighbor = point_.getIndex();
	}
}
#endif // !_Point_Node_cpp
