#include <iostream>

#include "board_functions.h"
#include "logic.h"
using namespace std;

int main() {
    string line;
    vector<string> boardHex;
    while (getline(cin, line)) {
        if (line.empty() || line.find("---") != string::npos) {
            continue;
        }
        if (line.find('<') != string::npos) {
            boardHex.push_back(line);
            continue;
        }

        size_t pos = 0;
        string command;
        while (pos != string::npos) {
            pos = line.find(' ');
            command = line.substr(0, pos);
            line.erase(0, pos + 1);
            if (command == "BOARD_SIZE") {
                cout << getBoardSize(boardHex) << endl;
            }
            else if (command == "PAWNS_NUMBER") {
                cout << countTotalPawns(boardHex) << endl;
            }
            else if (command == "IS_BOARD_CORRECT") {
                cout << validateBoardSetup(boardHex) << endl;
            }
            else if (command == "IS_GAME_OVER") {
                vector<vector<char>> boarddiagonal = convertToDiagonalMatrix(boardHex);
                if (validateBoardSetup(boardHex) == "YES")
                {
                    cout << isGameOver(boarddiagonal) << endl;
                }
                else cout << "NO" << endl;
                
            }
            else if (command == "IS_BOARD_POSSIBLE") {
                if (validateBoardSetup(boardHex) == "YES")
                {
                    vector<vector<char>> boarddiagonal = convertToDiagonalMatrix(boardHex);
                    cout << isBoardPossible(boarddiagonal) << endl;
                }
                else cout << "NO" << endl;
                
                
            }

        }
        boardHex.clear();
    }
    return 0;
}
