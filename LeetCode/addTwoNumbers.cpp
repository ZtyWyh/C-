// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      //ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* last = ret;
        ListNode* cur;
        
        int num = 0;
        int count = 0;
        
        while(l1 != NULL || l2 != NULL){
            num = count;
            if(l1 != NULL){
                num += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != NULL){
                num += l2->val;
                l2 = l2->next;
            }
            
            cur = new ListNode(num % 10);
            last->next = cur;
            last = last->next;
            count = (num / 10)? 1 : 0;
        }
        if(count == 1){
            last->next = new ListNode(1);
        }
        return ret->next;
        
        
    }
};