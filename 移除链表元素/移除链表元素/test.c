//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//
//
//示例 1：
//
//
//输入：head = [1, 2, 6, 3, 4, 5, 6], val = 6
//输出：[1, 2, 3, 4, 5]
//示例 2：
//
//输入：head = [], val = 1
//输出：[]
//示例 3：
//
//输入：head = [7, 7, 7, 7], val = 7
//输出：[]
//
//
//提示：
//
//列表中的节点数目在范围[0, 104] 内
//1 <= Node.val <= 50
//0 <= val <= 50
#include<stdio.h>

//题号203
struct ListNode {
    int val;
    struct ListNode* next;
    
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    while (cur) {
        if (cur->val != val) {
            //没找到
            pre = cur;
            cur = cur->next;
        }
        else if (cur->val == val) {
            //找到了
            if (cur == head) {
                head = cur->next;
                free(cur);
                cur = head;
            }
            else {
                pre->next = cur->next;
                free(cur);
                cur = pre->next;
            }


        }
    }
    return head;
}


