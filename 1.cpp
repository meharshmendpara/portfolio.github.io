#include <iostream>
#include <vector>

using namespace std;

bool isSolutionFound = false;

bool isSelfDescriptive(const vector<int>& number) {
    int length = number.size();

    for (int i = 0; i < length; i++) {
        int count = 0;

        for (int j = 0; j < length; j++) {
            if (number[j] == i) {
                count++;
            }
        }

        if (number[i] != count) {
            return false;
        }
    }

    return true;
}

void backtrack(vector<int>& number, vector<bool>& used, int position, int length) {
    if (position == length) {
        if (isSelfDescriptive(number)) {
            // Solution found
            isSolutionFound = true;
            return;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (!used[i]) {
            used[i] = true;
            number[position] = i;

            backtrack(number, used, position + 1, length);

            used[i] = false;

            if (isSolutionFound) {
                return;
            }
        }
    }
}

int main() {
    int length;
    cout << "Enter the length of the self-descriptive number: ";
    cin >> length;

    vector<int> number(length, -1);
    vector<bool> used(10, false);

    backtrack(number, used, 0, length);

    if (isSolutionFound) {
        cout << "Self-descriptive number found: ";
        for (int i = 0; i < length; i++) {
            cout << number[i];
        }
        cout << endl;
    } else {
        cout << "No self-descriptive number found." << endl;
    }

    return 0;
}