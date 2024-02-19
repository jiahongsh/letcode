//在 n x n 的网格 grid 中，我们放置了一些与 x，y，z 三轴对齐的 1 x 1 x 1 立方体。
//
//每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格(i, j) 上。
//
//现在，我们查看这些立方体在 xy 、yz 和 zx 平面上的投影。
//
//投影 就像影子，将 三维 形体映射到一个 二维 平面上。从顶部、前面和侧面看立方体时，我们会看到“影子”。
//
//返回 所有三个投影的总面积 。
//
//
//
//示例 1：
//
//
//
//输入： [[1, 2], [3, 4]]
//输出：17
//解释：这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。
//示例 2:
//
//输入：grid = [[2]]
//    输出：5
//        示例 3：
//
//        输入： [[1, 0], [0, 2]]
//        输出：8




//力扣第883题
int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int i = 0;
    int xy = 0;
    int totalxz = 0;
    int totalyz = 0;
    int totalxy = 0;
    for (i = 0; i < gridSize; i++) {
        int j = 0;
        int xz = 0;
        int yz = 0;
        for (j = 0; j < gridSize; j++) {
            totalxy += grid[i][j] > 0 ? 1 : 0;
            xz = xz > grid[i][j] ? xz : grid[i][j];
            yz = yz > grid[j][i] ? yz : grid[j][i];
        }
        totalxz += xz;
        totalyz += yz;
    }
    int totalnum = totalxz + totalyz + totalxy;
    return totalnum;
}