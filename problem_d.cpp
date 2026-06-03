#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/**
 * @param events Vector of {player, frame, attack_value}
 * @param H      Starting HP for both players
 * @return vector {hp1, hp2} each clamped to min 0
 */

bool comparator(const vector<int>& a, const vector<int>& b) {
  return a[1] < b[1];
}
vector<int> processGame(vector<vector<int>> events, int H) {
  int hp1 = H, hp2 = H;
  // To preserve relative order
  stable_sort(events.begin(), events.end(), comparator);

  int i = 0, n = events.size();

  // process events frame by frame as there maybe multiple attacks in he same frame
  while (i < n) {
    int current_frame = events[i][1], j = i;
    // Applying damages
    while (j < n && events[j][1] == current_frame) {
      int who = events[j][0], attack = events[j][2];
      who == 1 ? hp2 -= attack : hp1 -= attack;
      j++;
    }
    // Next unique frame
    i = j;
    if (hp1 <= 0 || hp2 <= 0) break;  // Someone dead
  }

  return {max(hp1, 0), max(hp2, 0)};  // clamping
}

// --- Main execution block. DO NOT MODIFY ---
int main() {
    try {
        int H, n;
        cin >> H >> n;
        vector<vector<int>> events(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> events[i][0] >> events[i][1] >> events[i][2];
        }

        vector<int> result = processGame(events, H);
        cout << result[0] << " " << result[1] << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
