//Question: https://leetcode.com/problems/word-search

// Word Search

// Backtracking

class Solution {
public:
    bool help(vector<vector<char>> board, string word, int row, int col, int wordInd) {
        if (wordInd == word.length()) return true;
        if (row >= board.size() || col >= board[0].size() || row < 0 || col < 0) return false;
        if (board[row][col] != word[wordInd]) return false;
        char t = board[row][col];
        board[row][col] = '0';
        bool ans =  help(board, word, row+1, col, wordInd+1) ||
                    help(board, word, row-1, col, wordInd+1) ||
                    help(board, word, row, col-1, wordInd+1) ||
                    help(board, word, row, col+1, wordInd+1);
        board[row][col] = t;
        return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (board[i][j] == word[0] && help(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
