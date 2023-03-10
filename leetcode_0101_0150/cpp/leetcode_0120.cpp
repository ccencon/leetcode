/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
struct Point {
    int line;
    int pos;
    int weight;
    Point(int _l, int _p, int _w) : line(_l), pos(_p), weight(_w) {}
    bool operator < (const Point& rhs) const { return rhs.weight < weight; }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        priority_queue<Point> que; que.emplace(0, 0, triangle[0][0]);
        vector<vector<int>> tW;
        for(int i = 1; i <= triangle.size(); i++)
            tW.emplace_back(i, __INT_MAX__);
        int ans = __INT_MAX__;
        while(!que.empty()){
            Point p = que.top(); que.pop();
            if(p.line + 1 == triangle.size())
                ans = min(ans, p.weight);
            else{
                Point v(p.line + 1, p.pos, p.weight + triangle[p.line + 1][p.pos]);
                if(tW[v.line][v.pos] > v.weight){
                    que.emplace(v);
                    tW[v.line][v.pos] = v.weight;
                }
                v = Point(p.line + 1, p.pos + 1, p.weight + triangle[p.line + 1][p.pos + 1]);
                if(tW[v.line][v.pos] > v.weight){
                    que.emplace(v);
                    tW[v.line][v.pos] = v.weight;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

