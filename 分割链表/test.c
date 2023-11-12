//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//
//你不需要 保留 每个分区中各节点的初始相对位置。
//
//
//
//示例 1：
//
//
//输入：head = [1, 4, 3, 2, 5, 2], x = 3
//输出：[1, 2, 2, 4, 3, 5]
//示例 2：
//
//输入：head = [2, 1], x = 2
//输出：[1, 2]
//
//
//提示：
//
//链表中节点的数目在范围[0, 200] 内
//- 100 <= Node.val <= 100
//- 200 <= x <= 200




//力扣面试题02.04
  struct ListNode {
     int val;
     struct ListNode *next;
 };
 


struct ListNode* partition(struct ListNode* head, int x) {
    //开辟哨兵位
    struct ListNode* lowhead, * lowtail, * greaterhead, * greatertail;
    lowhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    lowhead->next = NULL;
    greaterhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    greaterhead->next = NULL;
    lowtail = lowhead;
    greatertail = greaterhead;
    struct ListNode* cur = head;
    //对原链表进行遍历，判断
    while (cur) {
        if (cur->val < x) {
            lowtail->next = cur;
            lowtail = cur;

        }
        else {
            greatertail->next = cur;
            greatertail = cur;

        }
        //迭代
        cur = cur->next;
    }
    //连接两个链表
    lowtail->next = greaterhead->next;
    greatertail->next = NULL;
    //记录新的链表的头
    struct ListNode* newhead = lowhead->next;
    //释放开辟的动态空间
    free(greaterhead);
    free(lowhead);
    //返回正确的新头
    return newhead;

}
