#include "Input_Interpreter.h"
#include "Point.h"
#include "KDTree.h"
#include <utility> //std::pair

using std::pair;

int main() {
	
	auto input_pts = Input_Interpreter<float>::readInputCSV(string("sample_data.csv"));
	auto kdTree = KDTree<float>::makeTree(input_pts);
	
	auto query_pts = Input_Interpreter<float>::readInputCSV(string("query_data.csv"));

	vector<pair<int, float>> vec_result;
	vec_result.reserve(input_pts.size());
	int index;
	float min_dist = 0.0;
	for (const auto& pt : query_pts){
		kdTree.nearestNeighbor(pt, index, min_dist);
		vec_result.emplace_back(pair<int, float>(index, min_dist));
	}
	
	Input_Interpreter<float>::writeToCSV("query_result.csv", vec_result);

	return 0;
}