#include "KDTree.h"
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char * argv[]) {

	if (argc != 4) {
		cerr << "Invalid arguement" << endl;
		cout << "Arguements requried" << endl;
		cout << "1. Input points csv file path" << endl;
		cout << "2. Query points csv file path" << endl;
		cout << "3. Result csv file path" << endl;
	}
	else{
		KDTree<float> tree = KDTree<float>::build_kdtree(argv[1]);
		KDTree<float>::query_kdtree(tree,argv[2],argv[3]);
	}

	return 0;
}
