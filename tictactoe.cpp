#include <iostream>
#include <string>
#include <vector>

using namespace std;



class TicTacToe {
public:
    
    void createBoard(char icon, int row, int col) {
        table[row][col] = icon;
        string line, nonline, middleline;
        line = "+";
        nonline = "|";
        for (int i = 0; i < 3; ++i) {
            line +=    "--------------+";
            nonline += "              |";
        }
        for (int i = 0; i < 3; ++i) {
            middleline.clear();
            middleline = "|";
            for (int j = 0; j < 3; ++j) {
                middleline += "       ";
                middleline += table[i][j];
                middleline += "      |";
            }
            cout << line << endl;
            cout << nonline << endl;
            cout << middleline << endl;
            cout << nonline << endl;
        }
        cout << line << endl;
        
    }
    bool checkWinner(char icon) {
        for (size_t i = 0; i < table.size(); ++i) {
            for (size_t j = 0; j < table[i].size(); ++j) {
                if (i == 0 && j == 0) {
                    for (int k = 0; k < 3; ++k) {
                        if (table[k][k] != icon) {
                            break;
                        }
                        if (k == 2) {
                            return true;
                        }
                    }
                }
                if (i == 0) {
                    for (int k = 0; k < 3; ++k) {
                        if (table[k][j] != icon) {
                            break;
                        }
                        if (k == 2) {
                            return true;
                        }
                    }
                }
                if (j == 0) {
                    for (int k = 0; k < 3; ++k) {
                        if (table[i][k] != icon) {
                            break;
                        }
                        if (k == 2) {
                            return true;
                        }
                    }
                }
                if (i == 2 && j == 0) {
                    for (int k = 0; k < 3; ++k) {
                        if (table[i - k][k] != icon) {
                            break;
                        }
                        if (k == 2) {
                            return true;
                        }
                    }
                }// if
            }// inner loop
        }// outer loop
        return false;
    }
    void playGame() {
        Player p1, p2;
        int counter = 0;
        int row = 0, col = 0;
        cout << "Player 1 choose your character: ";
        cin >> p1.icon;
        cout << "Player 2 choose your character: ";
        cin >> p2.icon;
        table.resize(3, vector<char>(3));
        createBoard(' ', 0, 0); //Create an intial blank board
        while (counter < 9) {
            if (counter % 2 == 0) {
                cout << "Player 1's turn (row [SPACE] col, 0 indexed)" << endl;
                cin >> row >> col;
                if (row > 2 || col > 2) {
                    cout << "Invalid spot, please try again" << endl;
                    continue;
                }
                else if (table[row][col] == p1.icon|| table[row][col] == p2.icon) {
                    cout << "Invalid spot, please try again" << endl;
                    continue;
                }
                createBoard(p1.icon, row, col);
                p1.count++;
            }
            else {
                cout << "Player 2's turn (row [SPACE] col, 0 indexed)" << endl;
                cin >> row >> col;
                if (row > 2 || col > 2) {
                    cout << "Invalid spot, please try again" << endl;
                    continue;
                }
                else if (table[row][col] == p1.icon || table[row][col] == p2.icon) {
                    cout << "Invalid spot, please try again" << endl;
                    continue;
                }
                createBoard(p2.icon, row, col);
                p2.count++;
            }
            if (p1.count >= 3) {
                if (checkWinner(p1.icon)) {
                    cout << "Player 1 wins!" << endl;
                    break;
                }
            }
            if (p2.count >= 3) {
                if (checkWinner(p2.icon)) {
                    cout << "Player 2 wins!" << endl;
                    break;
                }
            }
            counter++;
        }
        if (counter == 9) {
            cout << "It's a draw!" << endl;
        }
        string again;
        cout << "Would you like to play again? (Y/N)" << endl;
        cin >> again;
        if (again == "Y") {
            table.clear();
            playGame();
        }
        else {
            cout << "Thanks for playing!" << endl;
        }
    }
private:
    vector<vector<char> > table;
    struct Player {
        int count = 0;
        char icon;
    };
};

int main() {
    TicTacToe test;
    test.playGame();
    return 0;
}