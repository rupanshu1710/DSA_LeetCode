class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char c = board[boxRow + i][boxCol + j];
                    if (c != '.') {
                        if (seen.count(c)) return false;
                        seen.insert(c);
                    }
                }
            }
        }
    }

    // 2. Check rows
    for (int row = 0; row < 9; row++) {
        unordered_set<char> seen;
        for (int col = 0; col < 9; col++) {
            char c = board[row][col];
            if (c != '.') {
                if (seen.count(c)) return false;
                seen.insert(c);
            }
        }
    }

    // 3. Check columns
    for (int col = 0; col < 9; col++) {
        unordered_set<char> seen;
        for (int row = 0; row < 9; row++) {
            char c = board[row][col];
            if (c != '.') {
                if (seen.count(c)) return false;
                seen.insert(c);
            }
        }
    }

    return true; // Passed all checks
    }
};