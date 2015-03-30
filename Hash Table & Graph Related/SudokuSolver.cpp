#include "stdafx.h"
#include <vector>
#include <unordered_set>

using namespace std;

class SudokuSolver {
public:
    static void solveSudoku(vector<vector<char> > &board) {
		vector<unordered_set<char>> row(9, unordered_set<char>());
		vector<unordered_set<char>> column(9, unordered_set<char>());
		vector<vector<unordered_set<char>>> block(3, vector<unordered_set<char>>(3, unordered_set<char>()));
		vector <pair<int, int>> blank;

		pair<int , int> startPos(0, 0);


		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] != '.'){
					row[i].insert(board[i][j]);
					column[j].insert(board[i][j]);
					block[i/3][j/3].insert(board[i][j]);
				}
				else{
					blank.push_back(pair<int, int>(i, j));
				}
			}
		}

		searchHelper(board, row, column, block, blank, 0);
    }

	static void searchHelper(vector<vector<char> > &board, vector<unordered_set<char>> &row, 
		vector<unordered_set<char>> &column, vector<vector<unordered_set<char>>> &block,
		vector <pair<int, int>> &blank, int currentPos){

		if(currentPos == blank.size()){
			return;
		}

		int i = blank[currentPos].first;
		int j = blank[currentPos].second;

		for(char k = '1'; k <= '9'; k++){
			if(row[i].find(k) == row[i].end() &&
				column[j].find(k) == column[j].end() &&
				block[i/3][j/3].find(k) == block[i/3][j/3].end()){
					row[i].insert(k);
					column[j].insert(k);
					block[i/3][j/3].insert(k);
					board[i][j] = k;
					searchHelper(board, row, column, block, blank, currentPos + 1);
					if(board[blank[blank.size() - 1].first][blank[blank.size() - 1].second] != '.'){
						return;
					}
					row[i].erase(k);
					column[j].erase(k);
					block[i/3][j/3].erase(k);
					board[i][j] = '.';
			}
		}
	}

	static vector<vector<char> > SodukuGen(){
		vector<vector<char> > board(9, vector<char>(9 , 0));
		string arr[] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};

		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				board[i][j] = arr[i][j];
			}
		}

		return board;
	}
};