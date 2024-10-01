#include <iostream>
#include <string>
#include <random>

using namespace std;

void print(string message) {
    cout << message << endl;
}

void printNoNewLine(string message) {
    cout << message;
}

string input(string message) {
    printNoNewLine(message);
    string thisInput;
    getline(cin, thisInput);
    return thisInput;
}

int GenRandomInt(int MIN, int MAX) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(MIN, MAX);
    return dis(gen);
}


int RangeIntInput(int Min, int Max, string message) {
    int thisIntInput;

    while (true) {
        try {
            string thisStringInput = input(message);
            thisIntInput = stoi(thisStringInput);
            if (thisIntInput >= Min && thisIntInput <= Max) {
                return thisIntInput;
            } 
            else {
                print("Please enter a valid number bewteen " + to_string(Min) + " - " + to_string(Max));
            }
        }
        catch (exception e) {
            print("Invalid input. Please enter a valid number.");
        }
    }


}


void printBox(string Box[3][3]) {
    print("Col     1   2   3  ");
    print("Row 1  [" + Box[0][0] + "] [" + Box[0][1] + "] [" + Box[0][2] + "] ");
    print("Row 2  [" + Box[1][0] + "] [" + Box[1][1] + "] [" + Box[1][2] + "] ");
    print("Row 3  [" + Box[2][0] + "] [" + Box[2][1] + "] [" + Box[2][2] + "] ");
}

bool checkForWinner(string Box[3][3], string lastInput) {
    for (int i = 0; i < 2; i++) {
        if (Box[i][0] == lastInput && Box[i][1] == lastInput && Box[i][2] == lastInput) { // this checks if there is a 3 x or o in a row
            return true;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (Box[0][i] == lastInput && Box[1][i] == lastInput && Box[2][i] == lastInput) { // this checks if there is a 3 x or o in a col
            return true;
        }
    }
    if (Box[0][0] == lastInput && Box[1][1] == lastInput && Box[2][2] == lastInput) { 
        return true;
    }


    if (Box[2][0] == lastInput && Box[1][1] == lastInput && Box[0][2] == lastInput) {
        return true;
    }

    return false;
}

static string Box[3][3] = {
    {" ", " ", " "},
    {" ", " ", " "},
    {" ", " ", " "}
};

int main() {
    int round = 0;


 
    print("Welcome to Tic Tac Toe!");

    printBox(Box);

    string lastInput = "o";
    while (round < 8) {
        if (lastInput == "o") {
            lastInput = "x";
        }
        else {
            lastInput = "o";
        }
        print(lastInput + "s turn.");
        int row = RangeIntInput(1, 3, "Row: ");
        row--; // so this can be used as an index
        int col = RangeIntInput(1, 3, "col: ");
        col--;
        if (Box[row][col] == " ") {

            Box[row][col] = lastInput;
            bool threeMatch =  checkForWinner(Box, lastInput);
            if (threeMatch) {
                print(lastInput + " has won!!!!");
                break;
            }
            round++;
        }
        else {
            print("That cell is already being used.");
        }
        printBox(Box);
    }

    return 0;
}