//ʵ��һ���㷨���ҳ����������е����� k ���ڵ㡣���ظýڵ��ֵ��
//
//ע�⣺�������ԭ�������Ķ�
//
//ʾ����
//
//���룺 1->2->3->4->5 �� k = 2
//����� 4
//˵����
//
//������ k ��֤����Ч�ġ�


//����������02.02
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
