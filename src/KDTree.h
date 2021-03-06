/*
1. Implments interface like for KDTree class
2. Acts as bridge to Tree impmentation
3. 
*/
#ifndef _KDTree_H
#define _KDTree_H

#include <memory>
#include <algorithm>
#include <iterator>
#include <limits>
#include <utility>
#include <string>
#include "Point.h"
#include "Base_Node.h"
#include "Input_Interpreter.h"

using std::shared_ptr;
using std::make_shared;
using std::numeric_limits;
using std::string;

template<typename T = float>
class KDTree {
public:
	//factory method to create tree
	static KDTree<T> makeTree(vector<Point<T>> list_points);

	//Reads the input from CSV file and calls makeTree
	static KDTree<T> build_kdtree(const string& fname);

	//Reads query data csv and query each points in csv
	//writes result to csv file
	static void query_kdtree(const KDTree& tree, const string& fname, const string & output_file);

	//Constructors
	KDTree() = default;
	KDTree(shared_ptr<Base_Node<T> > root);
	
	//destructor
	~KDTree() = default;
	
	KDTree<T> left() const;
	KDTree<T> right() const;

	//Returns true if tree does not contain any node
	bool isEmpty() const;
	
	//Searches for points in tree and true if points is found	
	bool findPoint(const Point<T>& input_pt) const;

	//returns true if search is valid Note: This method can be extended to kNN
	bool nearestNeighbor(const Point<T>& input_pt, int & index, T& dist) const;
	
	//searches nearest neighbour to input points and return shared_ptr to nearest neighbor and distance	
	bool nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>> & neighbor, T& dist) const;

private:
	shared_ptr<Base_Node<T>> root_;
};

#include "KDTree.cpp"

#endif // !_KDTree_H

