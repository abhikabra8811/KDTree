#ifndef _KDTree_cpp
#define _KDTree_cpp

#include "KDTree.h"
#include "Split_Node.h"

template<typename T>
KDTree<T>::KDTree(shared_ptr<Base_Node<T>> root):root_(root) {}

template<typename T>
KDTree<T> KDTree<T>::left() const{
	return KDTree<T>(root_->left());
}

template<typename T>
KDTree<T> KDTree<T>::right() const{
	return KDTree<T>(root_->right());
}

template<typename T>
bool KDTree<T>::isEmpty() const{
	return (root_ == nullptr);
}

template<typename T>
bool KDTree<T>::findPoint(const Point<T>& input_pt) const{
	if (root_ == nullptr)
		return nullptr;
	return (!root_->findPoint(input_pt));
}

template<typename T>
bool KDTree<T>::nearestNeighbor(const Point<T>& input_pt, int & index, T & dist) const{
	if (root_ == nullptr)
		return false;
	dist = numeric_limits<T>::max();
	root_->nearestNeighbor(input_pt, index, dist);
	return true;
}

template<typename T>
bool KDTree<T>::nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>> & neighbor, T& dist) const{
	if (root_ == nullptr)
		return false;
	dist = numeric_limits<T>::max(); //initialize distance to max
	shared_ptr<Base_Node<T>> neighbour = nullptr;
	root_->nearestNeighbor(input_pt, neighbour, dist);
	if(!neighbour)
		return false;
	return true;
}

template<typename T>
KDTree<T> KDTree<T>::makeTree(vector<Point<T>> list_points){
	if (list_points.size() > 0) {
		return KDTree(make_shared<Split_Node<T>>(list_points));
	}
	return KDTree(nullptr);
}

template<typename T>
KDTree<T> KDTree<T>::build_kdtree(const string & fname){
	auto input_pts = Input_Interpreter<float>::readInputCSV(fname);
	return KDTree<float>::makeTree(input_pts);
}

template<typename T>
void KDTree<T>::query_kdtree(const KDTree& tree, const string & query_file, const string & output_file){
	auto query_pts = Input_Interpreter<float>::readInputCSV(query_file);
	vector<pair<int, float>> vec_result;
	//vec_result.reserve(input_pts.size());
	int index;
	float min_dist = 0.0;
	for (const auto& pt : query_pts) {
		tree.nearestNeighbor(pt, index, min_dist);
		vec_result.emplace_back(pair<int, float>(index, min_dist));
	}

	Input_Interpreter<float>::writeToCSV(output_file, vec_result);
}

#endif // !_KDTree_cpp
