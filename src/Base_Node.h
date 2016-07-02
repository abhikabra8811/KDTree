/* This is a base class for types of node in tree
Methods in this class are declared virtual (not pure virtual) so that
derived need implement it if not needed
Needs proper error handling
*/

#ifndef _Base_Node_h
#define _Base_Node_h

#include <memory>
#include "Point.h"

using std::shared_ptr;
using std::enable_shared_from_this;

template<typename T = float>
class Base_Node: public enable_shared_from_this<Base_Node<T>>
{

public:
	//Default constructor for the Base Node
	Base_Node() = default;
	//Virtual destructor so that proper destructor gets called
	virtual ~Base_Node() = default;
	
	//return shared_ptr to left child of node, implmented in derived classes
	virtual shared_ptr<Base_Node<T>> left() const;

	//return shared_ptr to right child of node, implmented in derived classes
	virtual shared_ptr<Base_Node<T>> right() const;

	//Return true of query point is found in tree
	virtual bool findPoint(const Point<T>& input_pt) const;

	//Returns points stored at leaf node
	//Implemented in Point_Node class (leaf node)
	virtual Point<T> getPoint() const;

	//Find the nearest neighbor of input point and returns shared pointer to leaf node in tree as pointer to Base_Node
	virtual void nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>> & best_neighbor, T& best_dist);

	//Find the nearest neighor of input point and returns index of point in list points
	//used while creating KDTree and distance to the nearest neighbour
	virtual void nearestNeighbor(const Point<T>& input_pt, int & index, T & distance);

protected:
	//return dimesions across which split happens
	virtual int splitDimension() const;

	virtual T spliValue() const;
	
	//Distance between two points in tree
	//Implemented in Point_Node class (leaf node)
	virtual T distance(const shared_ptr<Base_Node<T>>& pt2);
};

#include "Base_Node.cpp"

#endif // !_Base_Node_h
