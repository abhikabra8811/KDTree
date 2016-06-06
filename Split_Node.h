#ifndef _Split_Node_H
#define _Split_Node_H

#include <memory>
#include <iterator>
#include <limits>
#include "Base_Node.h"
#include "Point.h"
#include "Point_Node.h"

using std::shared_ptr;
using std::make_shared;

template<typename T = float>
class Split_Node : public Base_Node<T>
{
public:
	Split_Node() = default;
	Split_Node(vector<Point<T>>& list_points, int depth);
	~Split_Node() = default;
	
	shared_ptr<Base_Node> left() const override;
	shared_ptr<Base_Node> right() const override;
	bool findPoint(const Point<T>& input_pt) const override;
	void nearestNeighbor(const Point<T>& input_pt, int & index, T & distance) const override;
	void nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>> & best_neighbor, T& best_dist) override;

private:
	int getAndUpdateSplitDim(const vector<Point<T>>& list_points);
	int split_dimension_ = -1;
	T split_value_;
	shared_ptr<Base_Node> left_;
	shared_ptr<Base_Node> right_;
};

#include "Split_Node.cpp"

#endif // !_Split_Node_H

