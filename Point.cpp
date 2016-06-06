#ifndef _Point_cpp_
#define _Point_cpp_

#include "Point.h"

template <typename T>
Point<T>::Point(const initializer_list<T>& input_list): features_(input_list){
}

template <typename T>
Point<T>::Point(const vector<T>& input_vec, int index):features_(input_vec), index_(index){
}

template <typename T>
T& Point<T>::operator[](const size_t index){
	return features_[index];
}

template <typename T>
const T& Point<T>::operator[](const size_t index) const{
	return features_[index];
}

template <typename T>
vector<T> Point<T>::getFeautureVector() const{
	return features_;
}

template <typename T>
size_t Point<T>::getSize() const{
	return features_.size();
}

template<typename T>
size_t Point<T>::getIndex() const{
	return index_;
}

template<typename T>
T Point<T>::distance(const Point<T>& other) const{
	vector<T> pt1Feature = features_;
	vector<T> pt2Feature = other.getFeautureVector();
	transform(begin(pt1Feature), end(pt1Feature), begin(pt2Feature), begin(pt1Feature), []
		(auto v1, auto v2) {
		return (v1 - v2) * (v1 - v2);
	});

	T dist = sqrtf(accumulate(begin(pt1Feature), end(pt1Feature), 0.0));
	return dist;
}

#endif // _Point_cpp_