//给你一个 m x n 的矩阵，最开始的时候，每个单元格中的值都是 0。
//
//另有一个二维索引数组 indices，indices[i] = [ri, ci] 指向矩阵中的某个位置，其中 ri 和 ci 分别表示指定的行和列（从 0 开始编号）。
//
//对 indices[i] 所指向的每个位置，应同时执行下述增量操作：
//
//ri 行上的所有单元格，加 1 。
//ci 列上的所有单元格，加 1 。
//给你 m、n 和 indices 。请你在执行完所有 indices 指定的增量操作后，返回矩阵中 奇数值单元格 的数目。






//力扣第1252题
int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    int i, j;

    int** matrix = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * n);
        memset(matrix[i], 0, sizeof(int) * n);
    }

    for (i = 0; i < indicesSize; i++) {

        for (int k = 0; k < n; k++)
        {
            matrix[indices[i][0]][k]++;
        }


        for (int k = 0; k < m; k++)
        {
            matrix[k][indices[i][1]]++;
        }

    }


    int count = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] & 1) {
                count++;
            }

        }
        free(matrix[i]);
    }
    free(matrix);
    return count;
}