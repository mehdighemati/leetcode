ListNode* swapPairs(ListNode* head) {
  if(head == nullptr || head->next == nullptr){
    return head;
  }
  
  ListNode* firstNode = head;
  ListNode* secondNode = head->next;

  firstNode->next = swapPairs(secondNode->next);
  secondNode->next = firstNode;

  return secondNode;
  
}