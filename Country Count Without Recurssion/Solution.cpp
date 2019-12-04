// Non-Recursize_Assessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

void markAsVisited(int row, int col, map<string, bool> &visited) {
	string coordsString = to_string(row) + to_string(col);
	visited[coordsString] = true;
}

void checkLeft(int row, int col, vector<vector<int>> matrix, map<string, bool> &visited) {
	int cellValue = matrix[row][col];
	int left = col - 1;
	if (left > -1) {
		if (cellValue == matrix[row][left]) {
			markAsVisited(row, left, visited);
		}
	}
}

void checkNeighbors(int row, int col, vector<vector<int>> matrix, map<string, bool> &visited) {
	int right = col + 1;
	int down = row + 1;
	int cellValue = matrix[row][col];

	if (right < matrix[row].size()) {
		if (matrix[row][right] == cellValue) {
			// In this country
			markAsVisited(row, right, visited);
		}
	}
	if (down < matrix.size()) {
		if (matrix[down][col] == cellValue) {
			// In this country
			markAsVisited(down, col, visited);
			checkLeft(down, col, matrix, visited); // Catches some edge cases that get missed without this check
		}
	}
}

int findCountries(int row, int col, vector<vector<int>> matrix, map<string, bool> & visited) {
	string coordsString = to_string(row) + to_string(col);
	int countryCount = 0;
	if (visited[coordsString]) {
		// Just check neighbors
		checkNeighbors(row, col, matrix, visited);
	}
	else {
		// Count the new country, mark it as visited, and then check neighbors
		countryCount++;
		markAsVisited(row, col, visited);
		checkNeighbors(row, col, matrix, visited);
	}
	return countryCount;
}


int main()
{
	map<string, bool> visited;
	vector<vector<int>> matrix;
	int countryCount = 0;

	vector<int> a = { 1,1,1,1 };
	vector<int> b = { 1,2,1,1 }; 
	vector<int> c = { 1,2,2,1 }; 
	vector<int> d = { 1,1,1,1 }; 
	//vector<int> e = { 1,1,2,4 }; 
	//vector<int> f = { 1,2,3,4 };

	matrix.push_back(a);
	matrix.push_back(b);
	matrix.push_back(c);
	matrix.push_back(d);
	//matrix.push_back(e);
	//matrix.push_back(f);

	

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			countryCount += findCountries(i, j, matrix, visited);
		}
	}

	cout << countryCount << endl;
	// Wait to see result
	int n;
	cin >> n;
	return 0;

}