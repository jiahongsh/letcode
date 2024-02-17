//给你一个由 X - Y 平面上的点组成的数组 points ，其中 points[i] = [xi, yi] 。
//从其中取任意三个不同的点组成三角形，返回能组成的最大三角形的面积。与真实值误差在 10 - 5 内的答案将会视为正确答案。
//
//
//
//
//
//输入：points = [[0, 0], [0, 1], [1, 0], [0, 2], [2, 0]]
//输出：2.00000
//解释：输入中的 5 个点如上图所示，红色的三角形面积最大。
//示例 2：
//
//输入：points = [[1, 0], [0, 0], [0, 1]]
//输出：0.50000




//力扣第812题
double sm(int x1, int y1, int x2, int y2, int x3, int y3) {
    return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
}


double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    int i = 0;
    double max = 0;
    double num = 0;
    for (i = 0; i < pointsSize; i++) {
        int j = i + 1;
        for (j = i + 1; j < pointsSize; j++) {
            int k = j + 1;
            for (k = j + 1; k < pointsSize; k++) {

                num = sm(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                if (max < num) {
                    double tmp = max;
                    max = num;
                    num = tmp;
                }

            }
        }
    }
    return max;
}