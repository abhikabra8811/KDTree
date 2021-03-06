#ifndef  _Input_Interpreter_cpp
#define _Input_Interpreter_cpp

#include "Input_Interpreter.h"

template <typename T>
vector<Point<T>> Input_Interpreter<T>::readInputCSV(const string& fname) {
	ifstream input_file(fname);
	vector<Point<T>> input_points;
	if (input_file.good()) { //if file is not good return empty list
		string line;
		vector<T> input_point;
		int i = 0;
		while (!input_file.eof()) {
			std::getline(input_file, line);
			if (line.empty())
				continue;
			std::istringstream line_stream(line);
			string token;
			while (std::getline(line_stream, token, ',')){
				input_point.push_back(std::stof(token)); //std::stof call depends on typename T, default T = float
			}
			input_points.emplace_back(input_point, i);
			++i;
			input_point.clear();
		}
	}
	return input_points;
}

template<typename T>
void Input_Interpreter<T>::writeToCSV(const string & fname, const vector<pair<int, T>>& result){
	ofstream output_csv(fname.c_str(), std::ios::trunc);
	for (auto& pt : result) {
		output_csv << pt.first << "," << pt.second << "\n";
	}
}

#endif // ! 
