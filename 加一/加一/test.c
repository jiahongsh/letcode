//����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��
//
//
//
//ʾ�� 1��
//
//���룺digits = [1, 2, 3]
//�����[1, 2, 4]
//���ͣ����������ʾ���� 123��
//ʾ�� 2��
//
//���룺digits = [4, 3, 2, 1]
//�����[4, 3, 2, 2]
//���ͣ����������ʾ���� 4321��
//ʾ�� 3��
//
//���룺digits = [0]
//�����[1]



//Note: The returned array must be malloced, assume caller calls free().
//����66
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int x = digitsSize - 1;
    for (int i = digitsSize; i > 0; i--)
    {
        if (digits[x] == 9)
        {
            digits[x] = 0;
            x--;
        }
        else
        {
            digits[x]++;
            *returnSize = digitsSize;
            return digits;
        }
    }
    *returnSize = digitsSize + 1;
    int* tmp = (int*)malloc(sizeof(int) * (digitsSize + 1));
    if (!tmp) return 0;
    *tmp = 1;
    for (int i = 1; i < digitsSize + 1; i++) tmp[i] = digits[i - 1];
    return tmp;


}

