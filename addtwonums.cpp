#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  //Storing heads
  ListNode* head1 = l1;
  ListNode* head2 = l2;
  
  //Set the carry to 0
  int sum = 0;
  int carry = 0;
  int unit = 0;

  //vals in nodes
  int val1 = 0;
  int val2 = 0;

  //Storing current node
  ListNode* cur1 = l1;
  ListNode* cur2 = l2;

  ListNode* ansHead = new ListNode();
  ListNode* cur3 = ansHead;
  
  //Traverse the linked lists until both are nullptr
  while(cur1 != nullptr || cur2 != nullptr ){
    cur3->next = new ListNode();
    cur3 = cur3->next;
    
    if(cur1==nullptr){
      val1 = 0;
    }else{
      val1 = cur1->val; 
    }
    if(cur2==nullptr){
      val2 = 0;
    }
    else{
      val2 = cur2->val;
    }
    sum = val1 + val2 + carry;
    if (sum >= 10){
      unit = sum % 10;
      cur3->val = unit;
    
      carry = 1; //10
    }
    else{
      cur3->val = sum;
      carry = 0;
    }
    if(cur1 != nullptr){
      cur1 = cur1->next;
    }
    if(cur2 != nullptr){
      cur2 = cur2->next;
    }
  }
  if (carry !=0){
    cur3->next = new ListNode();
    cur3 = cur3->next;
    cur3->val = 1;
  }
  return ansHead->next;
}

