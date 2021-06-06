template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}


struct Node {
  int key;
  int value;
  Node* next;
  Node* prev;

  Node(int k, int val){
    key = k;
    value = val;
  }

};

class LRUCache {
public:

  Node *head;
  Node *tail;
  std::unordered_map<int,Node*> hm;
  int size;
  int max;
  
  LRUCache(int capacity) {
    head = new Node(-1000, 17);
    tail = new Node(1000, 100);
    size = 0;
    max = capacity;
    head->next = tail;
    tail->prev = head;
      head->prev = nullptr;
      tail->next = nullptr;
  }
  
  // DummyHead <-> Node1 <-> Node2 <-> DummyTail

  

  int get(int key) {
    if (hm.count(key) == 0){
      return -1;
    }
    else {
      Node* getNode = hm[key];
      Node* newNode = new Node(getNode->key,getNode->value);
        
      del(getNode);
        getNode->next = nullptr;
        getNode->prev = nullptr;
        delete getNode;
        hm[newNode->key] = newNode;
      push_back(newNode);
      return newNode->value;
    }
  }

  // DummyHead <-> Node1 <-> DummyTail
  // DummyHead <-> Node1 --> NewNode            Node1<---DummyTail
  // 
  // DummyHead <-> Node1 <--> NewNode <--> DummyTail
  void print(){
    Node* cur = head;
    while(cur->key != 1000){
      std::cout << "Key & Value pair is: " << cur->key << " " << cur->value << "\n";
      cur = cur->next;
    } 
    std::cout << "Key & Value pair is: " << tail->key << " " << tail->value << "\n";
  }

  void del(Node* oldNode){
      
      
    Node* prevNode = oldNode->prev;
    Node* nextNode = oldNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    //Remove oldNode from Heap?
  }

  void push_back(Node* newNode){
    Node* tl = tail->prev;
    tl->next = newNode;
    newNode->prev = tl;
    newNode->next = tail;
    tail->prev = newNode;
  }

  void put(int key, int value) {
    //check if key and value pair exists
    Node *newNode = new Node(key, value);
    if(hm.count(key) > 0){
      Node *oldNode = hm[key];
      del(oldNode);
        
      hm.erase(oldNode->key);
        oldNode->next = nullptr;
        oldNode->prev = nullptr;
        delete oldNode;
      hm[key] = newNode;
      push_back(newNode);
    }
    else{
      if (size == max){
        //remove the node adjacent to head
        Node* lru = head->next;
        del(lru);
          hm.erase(lru->key);
          lru->next = nullptr;
        lru->prev = nullptr;
          delete lru;
          
        
        hm[key] = newNode;
        push_back(newNode);
      }
      else{
        //std::cout << "Adding Node to DLL with value of " << newNode.value << "\n";
        push_back(newNode);
        hm[key] = newNode;
        size++;
        //std::cout << "val of node in hashmap " << hm[key]->value << "\n";
      }
    }
    //std::cout << "Current size is: " << size << "\n";
  }
};