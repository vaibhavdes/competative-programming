/*

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

*/


ListNode *addTwoNumbers(ListNode *A, ListNode *B) {
        if(!A)
            return B;
        if(!B)
            return A;

        int carry = (A->val + B->val) / 10;
        ListNode *heads = new ListNode((A->val + B->val) % 10);
        ListNode *tail = heads;
        A = A->next;
        B = B->next;

        while(A || B || carry)
        {
            int sum = ((A ? A->val : 0) + (B ? B->val : 0) + carry);
            ListNode *t  = new ListNode(sum % 10);
            carry = sum / 10;                                          

            if(A)
                A = A->next;
            if(B)
                B = B->next;
            tail->next = t;
            tail = t;
        }

        return heads;
    }
