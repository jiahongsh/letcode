//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//
//
//示例 1：
//
//
//输入：l1 = [2, 4, 3], l2 = [5, 6, 4]
//输出：[7, 0, 8]
//解释：342 + 465 = 807.
//示例 2：
//
//输入：l1 = [0], l2 = [0]
//输出：[0]
//示例 3：
//
//输入：l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
//输出：[8, 9, 9, 9, 0, 0, 0, 1]
//
//
//提示：
//
//每个链表中的节点数在范围[1, 100] 内
//0 <= Node.val <= 9
//题目数据保证列表表示的数字不含前导零


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//力扣第2题
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // 创造一个头结点，让头指针dummy指向它
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    // 创造一个指针，让cur指向最后
    struct ListNode* cur = dummy;

    // 创造一个进位判断值
    int t = 0;

    // 循环（l1指向非空 或 l2指向非空 或 进位值非空）就执行
    while (l1 || l2 || t) {
        // 如果l1指向非空，则将l1的值加到t上，l1指向l1的下一个结点
        if (l1) t += l1->val, l1 = l1->next;
        // 如果l2指向非空，则将l2的值加到t上，l2指向l2的下一个结点
        if (l2) t += l2->val, l2 = l2->next;
        // 创造一个结点，赋值。本来没想给新结点的next赋值，可是报错啊，百度了一下，不赋值就是野指针，C语言不允许
        cur->next = malloc(sizeof(struct ListNode));
        cur->next->val = t % 10;
        cur->next->next = NULL;
        // cur指向下一个，也就是cur指向了新结点。
        cur = cur->next;

        t /= 10;
    }

    // 返回头指针指向的下一个结点
    return dummy->next;



}