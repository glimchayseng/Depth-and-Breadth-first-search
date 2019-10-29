//Filename: Graph.h
//Author: Gavin Limchayseng
//Date: 3/7/2019

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <queue>

class Graph
{
public:
	Graph();
	~Graph();
	void load(std::string filename);
	void display();
	void displayDFS(int vertex);
	void displayBFS(int vertex);

private:
	int** arr;
	int vertices;
	bool* visited;
};

