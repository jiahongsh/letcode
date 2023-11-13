//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
//
//
//
//示例 1：
//
//
//输入：head = [1, 2, 2, 1]
//输出：true
//示例 2：
//
//
//输入：head = [1, 2]
//输出：false
//
//
//提示：
//
//链表中节点数目在范围[1, 105] 内
//0 <= Node.val <= 9
//
//
//进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？






//力扣第234题
 struct ListNode {
    int val;
    struct ListNode* next;
    
};


bool isPalindrome(struct ListNode* head) {

    //先找到中间节点
    struct ListNode* slow, * fast;
    fast = head;
    slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* mid = slow;
    //将后半段倒置

    struct ListNode* newhead = NULL;
    struct ListNode* next;
    struct ListNode* cur = mid;

    while (cur) {
        //保存cur的下一个
        next = cur->next;
        //头插插入
        cur->next = newhead;
        newhead = cur;
        //迭代
        cur = next;


    }
    //比较

    while ((head && newhead)) {
        if (head->val == newhead->val) {
            head = head->next;
            newhead = newhead->next;
        }
        else {
            return false;
        }
    }

    return true;

}
