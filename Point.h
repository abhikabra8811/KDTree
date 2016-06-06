#ifndef _Point_H_
#define _Point_H_
#include <vector>
#include <initializer_list>	
#include <algorithm>
#include <numeric>

using std::vector;
using std::initializer_list;
using std::transform;
using std::begin;
using std::end;
using std::accumulate;

template <typename T = float>
class Point{
	vector<T> features_;
	int index_;
public:
	//default constructor
	Point() = default;
	
	//constructor with initializer_list	
	Point(const initializer_list<T>& input_list);

	Point(const vector<T>& vec,int index = 0);

	~Point() = default;	

	T& operator[](const size_t index);
	const T& operator[](const size_t index) const;
	vector<T> getFeautureVector() const;
	size_t getSize() const;
	size_t getIndex() const;
	T distance(const Point<T>& other) const;
};

#include "Point.cpp"

#endif
