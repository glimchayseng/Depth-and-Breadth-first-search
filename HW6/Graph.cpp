//Filename: Graph.cpp
//Author: Gavin Limchayseng
//Date: 3/7/2019

#include "Graph.h"

using namespace std;

Graph::Graph() {
}

Graph::~Graph() {
	delete[] arr;
}

void Graph::load(string filename) {
	
	//opening file
	ifstream myFile;
	myFile.open(filename);

	//Setting size of 2D Array
	myFile >> vertices;
	arr = new int*[vertices];

	//Filling empty 2D Array
	for (int i = 0; i < vertices; i++){
		arr[i] = new int[vertices];
		for (int j = 0; j < vertices; j++){
			arr[i][j] = 0;
		}
	}

	//Adding Connections
	int origin;
	int end;
	int count = 0;
	for (int i = 0; i < (vertices *(vertices - 1)); i++) {
		myFile >> origin;
		myFile >> end;
		arr[origin][end] = 1;
		arr[end][origin] = 1;
	}
	myFile.close();

	//Creating and Zero'ing the boolean array
	visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
		visited[i] = 0;
}

//Simple Display function
void Graph::display(){
	for (int i = 0; i < vertices; i++){
		for (int j = 0; j < vertices; j++)
			cout << arr[i][j] << "  ";
		cout << endl;
	}
}

//Recursive Depth First Search Fuction
void Graph::displayDFS(int vertex) {
	cout << vertex << " ";
	visited[vertex] = 1;
	for (int i = 0; i < vertices; i++) {
		if (!visited[i] && arr[vertex][i] == 1)
			displayDFS(i);
	}
}

//Queue based Breadth First Search Function
void Graph::displayBFS(int vertex){
	for (int i = 0; i < vertices; i++)
		visited[i] = 0;

	queue<int> Q;
	visited[vertex] = true;
	Q.push(vertex);

	while (!Q.empty())
	{
		vertex = Q.front(); 
		cout << vertex << " ";
		Q.pop();
		 
		for(int i = 0; i < vertices; i++){
			if (arr[vertex][i] != 0 && (!visited[i])){
				visited[i] = true;
				Q.push(i);
			}
		}
	}

	//clearing for future proof
	for (int i = 0; i < vertices; i++)
		visited[i] = 0;
}