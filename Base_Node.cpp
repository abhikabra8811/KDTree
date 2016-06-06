#ifndef _Base_Node_cpp
#define _Base_Node_cpp

#include "Base_Node.h"
template<typename T>
shared_ptr<Base_Node<T>> Base_Node<T>::left() const{
	return nullptr;
}

template<typename T>
shared_ptr<Base_Node<T>> Base_Node<T>::right() const{
	return nullptr;
}

template<typename T>
int Base_Node<T>::splitDimension() const{
	return -1;
}

template<typename T>
T Base_Node<T>::spliValue() const{
	return -1;
}

template<typename T>
bool Base_Node<T>::findPoint(const Point<T>& input_pt) const{
	return false;
}

template<typename T>
T Base_Node<T>::distance(const shared_ptr<Base_Node<T>>& pt2){
	return T();
}

template<typename T>
Point<T> Base_Node<T>::getPoint() const{
	return Point<T>();
}

template<typename T>
void Base_Node<T>::nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>>& best_neighbor, T& best_dist){
	return;
}

template<typename T>
void Base_Node<T>::nearestNeighbor(const Point<T>& input_pt, int & index, T & distance) const {
	return;
}

#endif // !_Base_Node_cpp

