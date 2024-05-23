#pragma once
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char>>& board, int x, int y, char player, vector<vector<bool>>& isVisited);
string isGameOver(vector<vector<char>>& boarddiagonal);
string checkWinValidity(const vector<vector<char>>& board, char player);
string isBoardPossible(vector<vector<char>>& board);