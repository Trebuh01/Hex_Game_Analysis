#pragma once
#include <vector>
#include <string>
using namespace std;

int getTotalCells(const string& row);
int getBoardSize(const vector<string>& boardHex);
int countTotalPawns(const vector<string>& boardHex);
string validateBoardSetup(const vector<string>& boardHex);
vector<vector<char>> convertToMatrix(const vector<string>& boardHex);
vector<vector<char>> convertToDiagonalMatrix(vector<string>& boardHex);