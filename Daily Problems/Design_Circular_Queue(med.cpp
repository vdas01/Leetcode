//https://leetcode.com/problems/design-circular-queue/
class MyCircularQueue {
public:
    int *arr;
         int f ,b,n;
    MyCircularQueue(int k) {
       f=-1;
        b=-1;
        arr = new int[k];
        n=k;
    }
    
    bool enQueue(int value) {
        if(f == -1 && b == -1){
            f=0;
            b=0;
            arr[b] = value;
            return true;
        }
        else if((b+1)%n == f)
            return false;
        else{
            b = (b+1)%n;
            arr[b] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if(f==-1 && b == -1) return false;
       else  if(f==b){
            f=-1;
            b=-1;
            return true;
        }
        else{
            f = (f+1)%n;
            return true;
        }
    }
    
    int Front() {
        if(f==-1) return -1;
        return arr[f];
    }
    
    int Rear() {
        if(f ==-1) return -1;
        return arr[b];
    }
    
    bool isEmpty() {
        if(f== -1 && b ==-1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((b+1)%n == f)
            return true;
        return false;
    }
};

