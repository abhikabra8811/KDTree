#ifndef _Point_Node_H_
#define _Point_Node_H_

#include <memory>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "Base_Node.h"
#include "Point.h"

template<typename T = float>
class Point_Node : public Base_Node<T> {
public:
	Point_Node() = default;
	Point_Node(const Point<T>& point);
	~Point_Node() = default;
	bool findPoint(const Point<T>& input_pt)const override;
	//shared_ptr<Base_Node<T>> nearestNeighbor(const Point<T>& input_pt)const override;
	T distance(const shared_ptr<Base_Node<T>>& pt2) override;
	Point<T> getPoint() const override;
	void nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>> & best_neighbor, T& best_dist) override;
	void nearestNeighbor(const Point<T>& input_pt, int & best_neighbor, T& best_dist)const override;
private:
	Point<T> point_;
};

#include "Point_Node.cpp"

#endif // !_Point_Node_H_

