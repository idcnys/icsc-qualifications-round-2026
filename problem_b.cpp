#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/**
 * Generates a geometric pattern on an n x n grid.
 *
 * Args:
 *     n:     Grid size (n x n, always odd for diamond)
 *     shape: Either "checkerboard" or "diamond"
 *
 * Returns:
 *     A 2D vector of integers (0 or 1).
 */


std::vector<std::vector<int>> generate_shape(int n, const std::string& shape) {
  std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));

  // WRITE YOUR CODE HERE
  if (shape == "checkerboard") {
    bool flip = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans[i][j] = flip ? 1 : 0;
        flip = !flip;
      }

      if (n % 2 == 0) {
        flip = !flip;
      }
    }

  } else {
    int mid = n / 2;
    int row = 0;

    // Upper half + middle row
    for (int i = 0; i <= mid; i++) {
      int col = 0;

      // Leading zeros
      for (int j = 0; j < mid - i; j++) {
        ans[row][col] = 0;
        col++;
      }
      // Diamond filled with 1s
      for (int j = 0; j < 2 * i + 1; j++) {
        ans[row][col] = 1;
        col++;
      }
      // Trailing zeros
      for (int j = 0; j < mid - i; j++) {
        ans[row][col] = 0;
        col++;
      }

      row++;
    }

    // Lower half
    for (int i = mid - 1; i >= 0; i--) {
      int col = 0;

      // Leading zeros
      for (int j = 0; j < mid - i; j++) {
        ans[row][col] = 0;
        col++;
      }
      // Diamond filled with 1s
      for (int j = 0; j < 2 * i + 1; j++) {
        ans[row][col] = 1;
        col++;
      }
      // Trailing zeros
      for (int j = 0; j < mid - i; j++) {
        ans[row][col] = 0;
        col++;
      }

      row++;
    }
  }

  return ans;
}



// --- Main execution block. DO NOT MODIFY ---
int main() {
    try {
        std::string line;
        std::getline(std::cin, line);
        int n = std::stoi(line);

        std::string shape;
        std::getline(std::cin, shape);

        auto result = generate_shape(n, shape);
        for (int i = 0; i < (int)result.size(); i++) {
            for (int j = 0; j < (int)result[i].size(); j++) {
                if (j > 0) std::cout << " ";
                std::cout << result[i][j];
            }
            std::cout << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
