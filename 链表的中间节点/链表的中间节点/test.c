//���㵥�����ͷ��� head �������ҳ�������������м��㡣
//
//����������м��㣬�򷵻صڶ����м��㡣
//
//
//
//ʾ�� 1��
//
//
//���룺head = [1, 2, 3, 4, 5]
//�����[3, 4, 5]
//���ͣ�����ֻ��һ���м��㣬ֵΪ 3 ��
//ʾ�� 2��
//
//
//���룺head = [1, 2, 3, 4, 5, 6]
//�����[4, 5, 6]
//���ͣ��������������м��㣬ֵ�ֱ�Ϊ 3 �� 4 �����صڶ�����㡣
//
//
//��ʾ��
//
//����Ľ������Χ��[1, 100]
//1 <= Node.val <= 100


 Definition for singly - linked list.
 struct ListNode {
    int val;
    struct ListNode* next;
    
};
 //����876��
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow, * fast;
    fast = head;
    slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}