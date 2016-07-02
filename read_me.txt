This file describes:
1. Directory structure of program
2. Pre-requisites
3. How to run

1. Director structure:
	data/
	--sample_data.csv
	--query_data.csv
	--result.csv
	(these locations can be specified from commandline while running application)
	Obj/
	--all object files
	src/
	--*.cpp, *.h
	KDTREE.o
	make

2. Pre-requisites:	
	- OS version:
		Distributor ID:	Ubuntu
		Description:	Ubuntu 14.04.4 LTS
		Release:	14.04
		Codename:	trusty
	- compiler version: Program uses features of C++11/14.
		g++ (Ubuntu 5.3.0-3ubuntu1~14.04) 5.3.0 20151204

3. How to run:
	- download project data from 
	- change current directory to project directory (e.g.  cd Uber/KDTree/)
	- run make file (e.g. abhishek@abhishek-linux:~/Uber/KDTree$ make)
	- KDTREE.o file is created after running make
	- run KDTREE.o with following input
		1. Input data points csv file path (e.g. data/sample_data.csv)
		2. Query data points csv file path (e.g. data/query_data.csv)
		3. Location of result csv file path (e.g. data/result.csv)
	- command to run to KDTREE.o
		./KDTREE.o <input data csv> <query data csv> <result csv>
		(e.g.: ./KDTREE.o data/sample_data.csv data/query_data.csv data/result.csv)



