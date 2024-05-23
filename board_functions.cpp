#include "board_functions.h"

int getTotalCells(const string& row) {
    int totalCount = 0;
    for (int i = 0; i < row.length(); ++i) {
        if (row[i] == '<') ++totalCount;
    }
    return totalCount;
}

int getBoardSize(const vector<string>& boardHex) {
    int maxRowSize = 0;
    for (int i = 0; i < boardHex.size(); ++i) {
        int rowCellCount = getTotalCells(boardHex[i]);
        if (rowCellCount > maxRowSize) maxRowSize = rowCellCount;
    }
    return maxRowSize;
}

int countTotalPawns(const vector<string>& boardHex) {
    int totalPawns = 0;
    for (int i = 0; i < boardHex.size(); ++i) {
        const string& row = boardHex[i];
        for (int j = 0; j < row.size(); ++j) {
            if (row[j] == 'r' || row[j] == 'b') ++totalPawns;
        }
    }
    return totalPawns;
}
string validateBoardSetup(const vector<string>& boardHex) {
    int redCount = 0, blueCount = 0;
    for (size_t i = 0; i < boardHex.size(); ++i) {
        for (size_t j = 0; j < boardHex[i].size(); ++j) {
            if (boardHex[i][j] == 'r') ++redCount;
            else if (boardHex[i][j] == 'b') ++blueCount;
        }
    }
    // Gracz czerwony zaczyna, wiêc mo¿e mieæ o jeden pion wiêcej lub równ¹ liczbê pionów co gracz niebieski.
    if (redCount == blueCount || redCount == blueCount + 1) return "YES";
    else return "NO";
}

vector<vector<char>> convertToMatrix(const vector<string>& boardHex) {
    int boardSize = boardHex.size();
    vector<vector<char>> board(boardSize, vector<char>(boardSize, '.'));
    for (int i = 0; i < boardSize; ++i) {
        int hexColumn = 0;
        for (int j = 0; j < boardHex[i].length(); ++j) {
            if (boardHex[i][j] == '<') {
                char potentialPawn = boardHex[i][j + 2];
                if (boardHex[i][j + 2] == 'r' || boardHex[i][j + 2] == 'b') {
                    board[i][hexColumn] = potentialPawn;
                }
                hexColumn++;
            }
        }
    }
    return board;
}
vector<vector<char>> convertToDiagonalMatrix(vector<string>& boardHex) {
    vector<vector<char>> board = convertToMatrix(boardHex);
    int boardSize = getBoardSize(boardHex);
    vector<vector<char>> boarddiagonal(boardSize, vector<char>(boardSize, '.'));

    for (int i = 0; i < getBoardSize(boardHex); ++i)
    {
        int columnIndex = 0;
        for (int j = 0; j < boardSize; ++j)
        {
            boarddiagonal[i][j] = board[i + j][j];
            ++columnIndex;
        }
        int row = getBoardSize(boardHex);
        int column = boardSize - 1;
        for (columnIndex; columnIndex < getBoardSize(boardHex); ++columnIndex)
        {
            boarddiagonal[i][columnIndex] = board[row][column];
            ++row;
        }
        --boardSize;
    }

    return boarddiagonal;
}