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
	//constructors
	Point_Node() = default;
	Point_Node(const Point<T>& point);
	
	~Point_Node() = default;
	
	//checks if input point is same as point_	
	bool findPoint(const Point<T>& input_pt)const override;
	
	//calcualtes distance between two points
	T distance(const shared_ptr<Base_Node<T>>& pt2) override;
	
	//return point_
	Point<T> getPoint() const override;
	
	//checks if point_ is new nearest point, if yes then update best_neighbor and best_dist
	void nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>> & best_neighbor, T& best_dist)override;

	//checks if point_ is new nearest point, if yes then update best_neighbor index and best_dist
	void nearestNeighbor(const Point<T>& input_pt, int & best_neighbor, T& best_dist)override;

private:
	Point<T> point_;
};

#include "Point_Node.cpp"

#endif // !_Point_Node_H_

