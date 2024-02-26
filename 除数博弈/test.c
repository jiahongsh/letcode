#include<stdbool.h>

//爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
//
//最初，黑板上有一个数字 n 。在每个玩家的回合，玩家需要执行以下操作：
//
//选出任一 x，满足 0 < x < n 且 n % x == 0 。
//    用 n - x 替换黑板上的数字 n 。
//    如果玩家无法执行这些操作，就会输掉游戏。
//
//    只有在爱丽丝在游戏中取得胜利时才返回 true 。假设两个玩家都以最佳状态参与游戏。



//博弈类的问题常常让我们摸不着头脑。当我们没有解题思路的时候，不妨试着写几项试试：
//
//n = 1n = 1n = 1 的时候，区间(0, 1)(0, 1)(0, 1) 中没有整数是 nnn 的因数，所以此时 Alice\text{ Alice }Alice 败。
//n = 2n = 2n = 2 的时候，Alice\text{ Alice }Alice 只能拿 111，nnn 变成 111，Bob\text{ Bob }Bob 无法继续操作，故 Alice\text{ Alice }Alice 胜。
//n = 3n = 3n = 3 的时候，Alice\text{ Alice }Alice 只能拿 111，nnn 变成 222，根据 n = 2n = 2n = 2 的结论，我们知道此时 Bob\text{ Bob }Bob 会获胜，Alice\text{ Alice }Alice 败。
//n = 4n = 4n = 4 的时候，Alice\text{ Alice }Alice 能拿 111 或 222，如果 Alice\text{ Alice }Alice 拿 111，根据 n = 3n = 3n = 3 的结论，Bob\text{ Bob }Bob 会失败，Alice\text{ Alice }Alice 会获胜。
//n = 5n = 5n = 5 的时候，Alice\text{ Alice }Alice 只能拿 111，根据 n = 4n = 4n = 4 的结论，Alice\text{ Alice }Alice 会失败。
//......
//写到这里，也许你有了一些猜想。没关系，请大胆地猜想，在这种情况下大胆地猜想是 AC 的第一步。也许你会发现这样一个现象：nnn 为奇数的时候 Alice\text{ Alice }Alice（先手）必败，nnn 为偶数的时候 Alice\text{ Alice }Alice 必胜。
//  这个猜想是否正确呢？下面我们来想办法证明它。


bool divisorGame(int n) {
    if (n % 2 == 0) {
        return true;
    }
    return false;
}