//有 n 个筹码。第 i 个筹码的位置是 position[i] 。
//
//我们需要把所有筹码移到同一个位置。在一步中，我们可以将第 i 个筹码的位置从 position[i] 改变为:
//
//position[i] + 2 或 position[i] - 2 ，此时 cost = 0
//position[i] + 1 或 position[i] - 1 ，此时 cost = 1
//返回将所有筹码移动到同一位置上所需要的 最小代价 。




//力扣第1217题
int minCostToMoveChips(int* position, int positionSize) {
    int countadd = 0;
    int counteven = 0;
    for (int i = 0; i < positionSize; i++) {
        if (position[i] & 1) {
            counteven++;
        }
        else {
            countadd++;
        }
    }
    return countadd < counteven ? countadd : counteven;
}