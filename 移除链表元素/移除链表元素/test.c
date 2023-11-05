//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
//
//
//ʾ�� 1��
//
//
//���룺head = [1, 2, 6, 3, 4, 5, 6], val = 6
//�����[1, 2, 3, 4, 5]
//ʾ�� 2��
//
//���룺head = [], val = 1
//�����[]
//ʾ�� 3��
//
//���룺head = [7, 7, 7, 7], val = 7
//�����[]
//
//
//��ʾ��
//
//�б��еĽڵ���Ŀ�ڷ�Χ[0, 104] ��
//1 <= Node.val <= 50
//0 <= val <= 50
#include<stdio.h>

//���203
struct ListNode {
    int val;
    struct ListNode* next;
    
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    while (cur) {
        if (cur->val != val) {
            //û�ҵ�
            pre = cur;
            cur = cur->next;
        }
        else if (cur->val == val) {
            //�ҵ���
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


