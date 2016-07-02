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
	
	//Takes list of input points
	//takes a copy of vector used in nth_elelements which is a mutating algorithm 
	Split_Node(vector<Point<T>> list_points);
	
	~Split_Node() = default;
	
	shared_ptr<Base_Node<T>> left() const override;
	shared_ptr<Base_Node<T>> right() const override;
	
	//returns true if point is found	
	bool findPoint(const Point<T>& input_pt) const override;
	
	//recursively searches for nearest neighbor in tree
	void nearestNeighbor(const Point<T>& input_pt, int & index, T & distance)override;
	void nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>> & best_neighbor, T& best_dist)override;

private:
	
	//Determins splitting dimesion based on dimension with largest range
	int getAndUpdateSplitDim(const vector<Point<T>>& list_points);
	int split_dimension_ = -1;
	T split_value_ = T();
	shared_ptr<Base_Node<T>> left_;
	shared_ptr<Base_Node<T>> right_;
};

#include "Split_Node.cpp"

#endif // !_Split_Node_H

