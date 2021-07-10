class MyCircularQueue {
private:
  vector<int> q;
  int head;
  int tail;
  int size;
public:
  MyCircularQueue(int k) {
    for(int i=0; i<k; i++){
      q.push_back(0);
    }
    head = 0;
    tail = 0;
    size = k;
  }

  void printq(){
    for(int i = 0; i < q.size(); i++){
        cout<< q[i] << ", ";
    }
    cout<<endl;
  }

  bool enQueue(int value) {
    if(isEmpty()){
      tail = tail%size;
      q[tail] = value;
      tail++;
      
      printq();
      cout<< tail << "\n";
      return true;
    }
    if(!isFull()){
      tail = tail%size;
      q[tail] = value;
      tail++;
      printq();
      cout<< tail << "\n";
      return true;
    }
    printq();
    cout<< tail << "\n";
    return false;
  }

  bool deQueue() {
    if(!isEmpty()){
      head++;
      head = head%size;
      return true;
    }
    return false;  
  }

  int Front() {
    if (isEmpty()){
      return -1;
    }
    return q[head];
  }

  int Rear() {
    if (isEmpty()){
      return -1;
    }
    // cout << tail;
    // cout << endl;
    return q[tail-1];
  }

  bool isEmpty() {
    if(head == tail){
      return true;
    }else{
      return false;
    }
  }

  bool isFull() {
    if(tail == head-1){
      return true;
    }
    else if(head == 0 && tail ==  size){
      return true;
    }else{
      return false;
    }
  }
};