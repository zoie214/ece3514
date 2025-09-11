
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Converts a word like "SEND" to a number
int toNumber(
    const std::string &word, 
    const std::vector<char> &letters, 
    const std::vector<int> &S);


// Checks if current assignment solves SEND + MORE = MONEY
bool isValid(
    const std::vector<int> &S, 
    const std::vector<char> &letters);


// Recursion
void Solve(
    int k, // how many left to assign
    std::vector<int> &S, //current assignment
    std::vector<int> &U, //unused digits
    const std::vector<char> &letters); // fixed letters


int main() {
    // 8 letters
    const std::vector<char> letters = {'S', 'E', 'N', 'D', 'M', 'O', 'R', 'Y'};
    std::vector<int> S; // blank and solution {9, 5, 6, 7, 1, 0, 8, 2}
    std::vector<int> U{0,1,2,3,4,5,6,7,8,9}; // Unused digits

    // Initial call: need to assign all 8 letters
    Solve(letters.size(), S, U, letters);
}


int toNumber(
    const std::string &word, 
    const std::vector<char> &letters, 
    const std::vector<int> &S) {

    int value = 0;
    for (char ch : word) {
        int index = -1;
        for (int i{0}; i<letters.size(); ++i) {
            if (letters[i] == ch) {
                index = i;
                break;
            }
        }
        value = value * 10 + S[index];
    }
    return value;
}


// Checks if current assignment solves SEND + MORE = MONEY
bool isValid(
    const std::vector<int> &S, 
    const std::vector<char> &letters) {

    // 'S' or 'M' can't be zero
    if (S[0] == 0 || S[4] == 0) return false;

    int send = toNumber("SEND", letters, S);
    int more = toNumber("MORE", letters, S);
    int money = toNumber("MONEY", letters, S);

    return send + more == money;
}


// Recursion
void Solve(
    int k, // how many left to assign
    std::vector<int> &S, //current assignment
    std::vector<int> &U, //unused digits
    const std::vector<char> &letters) { // fixed letters

    if (k == 0) {
        if (isValid(S, letters)) {
            std::cout << "Solution:\n";
            for (int i{0}; i<letters.size(); ++i) {
                std::cout << letters[i] << "=" << S[i] << "\n";
            }
            std::cout << "\n";
        }
    } else {
        // Make a copy as we are modifying U while iterating
        std::vector<int> currentU = U;

        for (int e : currentU) {
            S.push_back(e);     // Add e to end of S
            U.erase(find(U.begin(), U.end(), e));// Remove e from U

            Solve(k-1, S, U, letters); // Recursive call

            S.pop_back(); // Remove e from S
            U.push_back(e); // Add e back to U
        }
    }
}

/*
Solution:
S=9
E=5
N=6
D=7
M=1
O=0
R=8
Y=2
*/