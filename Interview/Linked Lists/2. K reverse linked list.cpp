/*

Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode *curr = A, *prev = NULL, *next = NULL;
    int cnt =0;
     while(cnt<B && curr) {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         cnt++;
     }
     if(next) {
         A->next = reverseList(next, B);
     }
     return prev;
}




// JAVA

/*

public class Solution {
    public static ListNode reverseList(ListNode A, int B) 
    {
        int c=0;
        ListNode prev=null;
        ListNode next=null;
        ListNode current=A;
        while(current!=null && c<B)
        {
            next=current.next;
            current.next=prev;
            prev=current;
            current=next;
            c++;
        }
        if(current!=null)
        {
            A.next=reverseList(current, B);
        }
        
        return prev;
    }
}

*/
