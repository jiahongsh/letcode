//给定一个 n x n 的二进制矩阵 image ，先 水平 翻转图像，然后 反转 图像并返回 结果 。
//
//水平翻转图片就是将图片的每一行都进行翻转，即逆序。
//
//例如，水平翻转[1, 1, 0] 的结果是[0, 1, 1]。
//反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。
//
//例如，反转[0, 1, 1] 的结果是[1, 0, 0]。
//
//
//示例 1：
//
//输入：image = [[1, 1, 0], [1, 0, 1], [0, 0, 0]]
//输出： [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
//解释：首先翻转每一行: [[0, 1, 1], [1, 0, 1], [0, 0, 0]] ；
//然后反转图片 : [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
//示例 2：
//
//输入：image = [[1, 1, 0, 0], [1, 0, 0, 1], [0, 1, 1, 1], [1, 0, 1, 0]]
//输出： [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]
//解释：首先翻转每一行 : [[0, 0, 1, 1], [1, 0, 0, 1], [1, 1, 1, 0], [0, 1, 0, 1]] ；
//然后反转图片 : [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]
//
//
//提示：
//
//n == image.length
//n == image[i].length
//1 <= n <= 20
//images[i][j] == 0 或 1.





//力扣第832题
//暴力
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    int n = imageSize;
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int tmp = image[i][left];
            image[i][left] = image[i][right];
            image[i][right] = tmp;
            left++;
            right--;
        }
    }


    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            //  image[i][j]==0 ? image[i][j]==1 : image[i][j]==0 ; 
            image[i][j] ^= 1;
        }
    }
    return image;
}




//观察，总结法
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    int n = imageSize;
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if (image[i][left] == image[i][right]) {
                image[i][left] ^= 1;
                image[i][right] ^= 1;
            }
            left++;
            right--;
        }
        if (n % 2 != 0) {
            image[i][left] ^= 1;
        }
    }



    return image;
}

