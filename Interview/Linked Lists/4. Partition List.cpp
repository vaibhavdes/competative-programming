/*

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/

// CPP

ListNode* Solution::partition(ListNode* A, int B) {
     if(!A || !A->next)
            return A;
    ListNode* temp1=new ListNode(0);
    ListNode* temp2=new ListNode(0);    
    ListNode *s1=temp1,*s2=temp2;   
    while(A){       
        if(A->val<B){         
                s1->next=A;
                A=A->next;
                s1=s1->next;           
        }               
        else {                               
                s2->next=A;
                A=A->next;
                s2=s2->next;                                                      
        }                           
    }   
    s1->next=temp2->next;    
    s2->next=NULL;
    
    return temp1->next;
}

// JAVA
/*

public ListNode partition(ListNode A, int B) {
    ListNode curr = A;
    ListNode head = new ListNode(-1);
    head.next = A;
    ListNode prev = head;

    ListNode smallerHead = new ListNode(-1);
    ListNode small = smallerHead;

    while(curr!=null){
        if(curr.val < B){
            small.next = curr;
            small = small.next;

            prev.next = curr.next;
            curr = curr.next;
        }

        else{
            prev = curr;
            curr = curr.next;
        }
    }

    small.next = head.next;
    return smallerHead.next;
}

*/
