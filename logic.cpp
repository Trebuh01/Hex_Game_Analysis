#include "logic.h"

bool dfs(vector<vector<char>>& board, int x, int y, char player, vector<vector<bool>>& isVisited) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board.size() || isVisited[y][x] || board[y][x] != player) {
        return false;
    }
    isVisited[y][x] = true;
    if ((player == 'b' && y == board.size() - 1) || (player == 'r' && x == board.size() - 1)) {
        return true;
    }

    static const int dx[] = { -1, 0, 1, 1, 0, -1 };
    static const int dy[] = { -1, -1, 0, 1, 1, 0 };
    for (int i = 0; i < 6; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (dfs(board, newX, newY, player, isVisited)) {
            return true;
        }
    }
    return false;
}

string isGameOver(vector<vector<char>>& boarddiagonal) {

    int boardSize = boarddiagonal.size();
    vector<vector<bool>> visited(boardSize, vector<bool>(boardSize, false));
    // dla gracza niebieskiego
    for (int x = 0; x < boardSize; ++x) {
        if (boarddiagonal[0][x] == 'b' && dfs(boarddiagonal, x, 0, 'b', visited)) {
            return "YES BLUE";
        }
    }

    // dla gracza czerwonego
    vector<vector<bool>> visited2(boardSize, vector<bool>(boardSize, false));
    for (int y = 0; y < boardSize; ++y) {
        if (boarddiagonal[y][0] == 'r' && dfs(boarddiagonal, 0, y, 'r', visited2)) {
            return "YES RED";
        }
    }
    return "NO";


}
string checkWinValidity(const vector<vector<char>>& board, char player) {
    int redCount = 0, blueCount = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 'r') ++redCount;
            else if (board[i][j] == 'b') ++blueCount;
        }
    }

    if (player == 'b' && redCount != blueCount) return "NO";

    if (player == 'r' && redCount != blueCount + 1)return "NO";
    return "";

}
string isBoardPossible(vector<vector<char>>& board) {
    int boardSize = board.size();
    vector<vector<bool>> visited(boardSize, vector<bool>(boardSize, false));
    bool foundPath = false;
    bool dwiepotencjalne = false;


    for (int x = 0; x < boardSize; ++x) {
        if (board[0][x] == 'b' && dfs(board, x, 0, 'b', visited)) {


            if (checkWinValidity(board, 'b') == "NO")return "NO";

            if (foundPath) {
                dwiepotencjalne = true;
                break;
            }
            foundPath = true;
            fill(visited.begin(), visited.end(), vector<bool>(boardSize, false));

        }
    }
    fill(visited.begin(), visited.end(), vector<bool>(boardSize, false));
    if (dwiepotencjalne)
    {
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                if (board[i][j] == 'b') {
                    char temp = board[i][j];
                    board[i][j] = '.';

                    string wygrywajacy = isGameOver(board);
                    board[i][j] = temp;

                    if (wygrywajacy == "NO")
                    {
                        dwiepotencjalne = false;
                    }

                }
            }
        }
        if (dwiepotencjalne)return "NO";
        else return "YES";

    }
    dwiepotencjalne = false;
    foundPath = false;
    fill(visited.begin(), visited.end(), vector<bool>(boardSize, false));

    for (int y = 0; y < boardSize; ++y) {
        if (board[y][0] == 'r') {
            if (dfs(board, 0, y, 'r', visited)) {
                if (checkWinValidity(board, 'r') == "NO")return "NO";
                if (foundPath)
                {
                    dwiepotencjalne = true;
                    break;
                }
                foundPath = true;
                fill(visited.begin(), visited.end(), vector<bool>(boardSize, false));
            }
        }
    }
    fill(visited.begin(), visited.end(), vector<bool>(boardSize, false));
    if (dwiepotencjalne)
    {
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                if (board[i][j] == 'r') {
                    char temp = board[i][j];
                    board[i][j] = '.';

                    string wygrywajacy = isGameOver(board);
                    board[i][j] = temp;

                    if (wygrywajacy == "NO")
                    {
                        dwiepotencjalne = false;
                    }

                }
            }
        }
        if (dwiepotencjalne)return "NO";
        else return "YES";

    }
    return "YES";
}