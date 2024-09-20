#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> calculate_final_position(const vector<pair<char, int>>& moves) {
    int x = 0, y = 0;
    for (const auto& move : moves) {
        char direction = move.first;
        int distance = move.second;
        switch (direction) {
            case 'W': x -= distance; break;
            case 'E': x += distance; break;
            case 'N': y += distance; break;
            case 'S': y -= distance; break;
        }
    }
    return make_pair(x, y);
}

int main() {
    int N;
    cin >> N;

    vector<pair<char, int>> moves(N);
    for (int i = 0; i < N; ++i) {
        char direction;
        int distance;
        cin >> direction >> distance;
        moves[i] = make_pair(direction, distance);
    }

    pair<int, int> final_position = calculate_final_position(moves);
    cout << final_position.first<<" " << final_position.second << endl;

    return 0;
}