class Node {
    int val;
    Node next;
    
    public Node(int val, Node next){
        this.val = val;
        this.next = next;
    }
    public Node(int val){
        this.val = val;
    }
}

class MyCircularQueue {
    int curSize = 0, capSize;
    Node head, tail;
    public MyCircularQueue(int k) {
        capSize = k;
        head = tail = null;
    }
    
    public boolean enQueue(int value) {
        if (curSize + 1 > capSize) return false;
        Node newNode = new Node(value);
        if (curSize == 0){
            head = tail = newNode;
        }else{
            tail.next = newNode;
            tail = tail.next;
        }
        curSize++;
        return true;
    }
    
    public boolean deQueue() {
        if (curSize == 0) return false;
        Node result = head;
        head = head.next;
        if (head == null) tail = null; // if the ori queue only have 1 element
        curSize--;
        return true;
    }
    
    public int Front() {
        if (curSize == 0) return -1;
        return head.val;
    }
    
    public int Rear() {
        if (curSize == 0) return -1;
        return tail.val;
    }
    
    public boolean isEmpty() {
        return curSize == 0;
    }
    
    public boolean isFull() {
        return curSize == capSize;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */
