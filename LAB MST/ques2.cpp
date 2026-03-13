#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());

    int i = 0;
    int j = tokens.size() - 1;
    int score = 0;
    int maxScore = 0;

    while (i <= j) {
        if (power >= tokens[i]) {
            power -= tokens[i];
            score++;
            i++;
            maxScore = max(maxScore, score);
        }
        else if (score > 0) {
            power += tokens[j];
            score--;
            j--;
        }
        else {
            break;
        }
    }

    return maxScore;
}

int main() {
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;

    cout << "Maximum Score: " << bagOfTokensScore(tokens, power);

    return 0;
}