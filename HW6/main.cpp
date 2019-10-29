//Filename: main.cpp
//Author: Gavin Limchayseng
//Date: 3/7/2019

#include <iostream>
#include "Graph.h"
#include <string>


using namespace std;

int main() {

	string input;
	cout << "Please input a file name: ";
	cin >> input;
	cout << endl;

	//Starting Vertex
	int vertex = 0;

	//function calls
	Graph test;
	test.load(input);
	test.display();
	cout << endl << "Depth First Search: ";
	test.displayDFS(vertex);
	cout << endl << "Breadth First Search: ";
	test.displayBFS(vertex);

	return 0;
}