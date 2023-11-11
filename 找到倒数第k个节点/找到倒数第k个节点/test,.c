//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
//
//注意：本题相对原题稍作改动
//
//示例：
//
//输入： 1->2->3->4->5 和 k = 2
//输出： 4
//说明：
//
//给定的 k 保证是有效的。


//力扣面试题02.02
struct ListNode {
    int val;
    struct ListNode* next;
};



int kthToLast(struct ListNode* head, int k) {
    struct ListNode* fast, * slow;
    fast = head;
    slow = head;
    while (k--) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->val;
}
