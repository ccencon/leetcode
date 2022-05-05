/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    struct Param
    {
        int i;
        int j;
        int size;
        bool operator()(const Param& lhs, const Param& rhs) const{
            return lhs.size > rhs.size;
        }
    };
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> sets(81, {'1','2','3','4','5','6','7','8','9'});
        priority_queue<Param> queue;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c == '.'){
                    
                }
                else{
                    sets[i * 9 + j].clear();
                    for(int idx = 0; idx < 9; idx++){
                        sets[i * 9 + idx].erase(c);
                        sets[idx * 9 + j].erase(c);
                    }
                    for(int _i = i / 3; _i < i / 3 + 3; _i++)
                        for(int _j = j / 3; _j < j / 3 + 3; _j++)
                            sets[_i * 9 + _j].erase(c);
                }
            }
    }
};

struct Param
{
	int i;
	int j;
	int size;
	Param(int _i, int _j, int _size) :i(_i), j(_j), size(_size){}
	bool operator<(const Param& rhs) const{
		return size > rhs.size;
	}
};
int main(int argc, char const *argv[])
{
	
	priority_queue<Param, vector<Param>, Param()> queue;

	Param p(1, 2, 3);
	queue.push(p);

	p = queue.top();
	cout << p.size << endl;

	getchar();

	return 0;
}
// @lc code=end

