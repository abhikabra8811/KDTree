#ifndef Split_Node_cpp
#define Split_Node_cpp

#include "Split_Node.h"
#include <algorithm>
#include <iterator>
#include <stdexcept>

template<typename T>
Split_Node<T>::Split_Node(vector<Point<T>> list_points) {
	
	if (list_points.size() > 1) {
		
		//selects split dimesion as dimension with largest range		
		int k = getAndUpdateSplitDim(list_points);
		if (k < 0) {
			throw std::invalid_argument("Number of dimensions are less than 0");
		}

		//get the median
		std::nth_element(begin(list_points), begin(list_points) + list_points.size() / 2, end(list_points),
										[k](const auto& left, const auto& right) {
										return left[k] < right[k];
			}
		);

		//use median point as split point
		auto split_pt = list_points[list_points.size() / 2];
		split_value_ = split_pt[split_dimension_];

		auto left_points = vector<Point<T>>(begin(list_points), begin(list_points) + list_points.size() / 2);
		auto right_points = vector<Point<T>>(begin(list_points) + list_points.size() / 2, end(list_points));
		
		//recursively build the tree
		//if number of points on left are greater than 1 then create a split
		if (left.size() > 1) {
			left_ = make_shared<Split_Node<T>>(left_points);
		}
		else {//only 1 point create a leaf node to store the point
			left_ = make_shared<Point_Node<T>>(left_points[0]);
		}

		//if number of points on right are greater than 1 then create a split
		if (right.size() > 1){
			right_ = make_shared<Split_Node<T>>(right_points);
		}
		else {
			right_ = make_shared<Point_Node<T>>(right_points[0]);
		}
	}
	
}
template<typename T>
shared_ptr<Base_Node<T>> Split_Node<T>::left() const{
	return left_;
}

template<typename T>
shared_ptr<Base_Node<T>> Split_Node<T>::right() const {
	return right_;
}

template<typename T>
bool Split_Node<T>::findPoint(const Point<T>& input_pt) const{
	if (input_pt[split_dimension_] < split_value_){
		return (this->left_->findPoint(input_pt) != nullptr);
	}
	else{
		return (this->right_->findPoint(input_pt) != nullptr);
	}
}

template<typename T>
void Split_Node<T>::nearestNeighbor(const Point<T>& input_pt, int & index, T & best_dist){
	shared_ptr<Base_Node<T>> best_neighbor = nullptr;
	nearestNeighbor(input_pt, best_neighbor, best_dist);
	index = best_neighbor->getPoint().getIndex();
}

template<typename T>
void Split_Node<T>::nearestNeighbor(const Point<T>& input_pt, shared_ptr<Base_Node<T>>& best_neighbor, T& best_dist){
	shared_ptr<Base_Node<T>> other_branch = nullptr;
	if (input_pt[split_dimension_] < split_value_) {
		this->left_->nearestNeighbor(input_pt, best_neighbor, best_dist);
		other_branch = right_;
	}
	else {
		this->right_->nearestNeighbor(input_pt, best_neighbor, best_dist);
		other_branch = left_;
	}

	if (fabs(input_pt[split_dimension_] - split_value_) < best_dist) {
		other_branch->nearestNeighbor(input_pt, best_neighbor, best_dist);
	}
}


template<typename T>
int Split_Node<T>::getAndUpdateSplitDim(const vector<Point<T>> & list_points){
	if (list_points.size() > 1) {
		//get number of dimensions -- assumes all the features has same dimensions
		int N = list_points[0].getFeautureVector().size();
		double currentMax = std::numeric_limits<T>::min();
		for (int i = 0; i < N; ++i) {
			auto min_max_result = std::minmax_element(begin(list_points), end(list_points),
				[i](const auto& left, const auto& right) {
				return left[i] < right[i];  }
			);
			if (currentMax < (*min_max_result.second)[i] - (*min_max_result.first)[i]) {
				currentMax = (*min_max_result.second)[i] - (*min_max_result.first)[i];
				split_dimension_ = i;
			}
		}
	}
	return split_dimension_;
}

#endif // !Split_Node_cpp
