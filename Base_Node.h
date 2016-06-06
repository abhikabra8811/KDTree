#ifndef _Base_Node_h
#define _Base_Node_h

#include <memory>
#include "Point.h"

using std::shared_ptr;

template<typename T>
class Base_Node;

template<typename T = float>
class Base_Node: public std::enable_shared_from_this<Base_Node<T>>
{
public:
	Base_Node() = default;
	virtual ~Base_Node() = default;
	virtual shared_ptr<Base_Node<T>> left() const;
	virtual shared_ptr<Base_Node<T>> right() const;
	virtual int splitDimension() const;
	virtual T spliValue() const;
	virtual bool findPoint(const Point<T>& input_pt) const;
	virtual T distance(const shared_ptr<Base_Node<T>>& pt2);
	virtual Point<T> getPoint() const;
	virtual void nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>> & best_neighbor, T& best_dist);
	virtual void nearestNeighbor(const Point<T>& input_pt, int & index, T & distance) const;

protected:
};

#include "Base_Node.cpp"

#endif // !_Base_Node_h
