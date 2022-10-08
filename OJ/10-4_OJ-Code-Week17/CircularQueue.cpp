

/*设计循环队列*/
/* https://leetcode.cn/problems/design-circular-queue/ */


typedef struct {

    int _front;
    int _rear;
    int _capa;
    int* _arr;

} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    return obj->_front == obj->_rear;

}

bool myCircularQueueIsFull(MyCircularQueue* obj) {

    
    return (obj->_rear + 1) % obj->_capa == obj->_front;

}

MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue* myCQ = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    myCQ->_arr = (int*)malloc(sizeof(int) * (k + 1));
    
    myCQ->_front = myCQ->_rear = 0;
    myCQ->_capa = k + 1;
    
    return myCQ;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if(myCircularQueueIsFull(obj)) return false;

    obj->_arr[obj->_rear] = value;
    obj->_rear = (obj->_rear + 1) % obj->_capa;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {

    if(myCircularQueueIsEmpty(obj)) return false;

    obj->_front = (obj->_front + 1) % obj->_capa;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {

    if(myCircularQueueIsEmpty(obj)) return -1;

    return obj->_arr[obj->_front];

}

int myCircularQueueRear(MyCircularQueue* obj) {

    if(myCircularQueueIsEmpty(obj)) return -1;

    return obj->_arr[(obj->_rear - 1 + obj->_capa) % obj->_capa];
}


void myCircularQueueFree(MyCircularQueue* obj) {

    free(obj->_arr);
    free(obj);

}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/