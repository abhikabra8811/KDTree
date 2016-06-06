#ifndef _Input_Interpreter_H_
#define _Input_Interpreter_H_

#include <fstream>
#include <string>
#include <sstream>
#include <ios>
#include <utility>
#include "Point.h"

using std::string;
using std::ifstream;
using std::ofstream;
using std::pair;

template <typename T = float>
class Input_Interpreter{
	Input_Interpreter() = default;
public:
	static vector<Point<T>> readInputCSV(const string& fname);
	static void writeToCSV(const string& fname, const vector<pair<int, T>>& result);
};


#include "Input_Interpreter.cpp"

#endif

