//题目链接 https://leetcode-cn.com/problems/island-perimeter/
//题目信息：
/*
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
网格中的格子水平和垂直方向相连（对角线方向不相连）。
整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
示例 :
输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
输出: 16
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    int islandPerimeter(vector<vector<int>>& grid)
    {
        for (int sr = 0; sr < grid.size(); ++sr)
        {
            for (int sc = 0; sc < grid[0].size(); ++sc)
            {
                if (grid[sr][sc] == 1)
                {
                    return dfs(grid, sr, sc);
                }
            }
        }
    }
    int dfs(vector<vector<int>>& grid, int sr, int sc)
    {
        if (sr < 0 || sr >= grid.size() || sc < 0 || sr >= grid[0].size())
        {
            return 1;
        }
        if (grid[sr][sc] == 0)
        {
            return 1;
        }
        if (grid[sr][sc] != 1)
        {
            return 0;
        }
        grid[sr][sc] = 2;//标记已访问过
        return dfs(grid, sr, sc + 1)//右边
            + dfs(grid, sr + 1, sc)//下边
            + dfs(grid, sr, sc - 1)//左边
            + dfs(grid, sr - 1, sc);//上边
    }
};
