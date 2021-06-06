/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
  stack<ListNode*> node_ptrs;
  ListNode* cur = head;
  if (head == nullptr){
    return nullptr;
  } 
  while(cur->next!=nullptr){
    node_ptrs.push(cur);
    cur = cur->next;
  }
  ListNode* oldTail = cur;
  while(node_ptrs.size() != 0){
    cur->next = node_ptrs.top();
    node_ptrs.pop();
    cur = cur->next;
  }
  cur->next = nullptr;
  return oldTail;
}
};