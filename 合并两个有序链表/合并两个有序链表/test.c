//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//
//
//示例 1：
//
//
//输入：l1 = [1, 2, 4], l2 = [1, 3, 4]
//输出：[1, 1, 2, 3, 4, 4]
//示例 2：
//
//输入：l1 = [], l2 = []
//输出：[]
//示例 3：
//
//输入：l1 = [], l2 = [0]
//输出：[0]
//
//
//提示：
//
//两个链表的节点数目范围是[0, 50]
//- 100 <= Node.val <= 100
//l1 和 l2 均按 非递减顺序 排列


//力扣第21题
 struct ListNode {
    int val;
    struct ListNode* next;
    
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct ListNode* tail, * head;
    while (list1 && list2) {
        if ((list1->val) < (list2->val)) {
            head = list1;
            tail = list1;
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            tail = list2;
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }
    if (list1 == NULL) {
        tail->next = list2;
    }
    else {
        tail->next = list1;
    }
    return head;
}