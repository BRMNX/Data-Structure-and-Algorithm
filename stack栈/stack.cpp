#include <iostream>
#include <stack>
using namespace std;
template <class T>
class stackFromArray{
    private:
        int topIndex = -1;
        int compacity;
        T *arr = nullptr;
    public:
        stackFromArray(int n):compacity(n){
            arr = new T[n];
        }

        void push(T t){
            if(topIndex == compacity - 1) return;
            arr[++topIndex] = t;
        }

        void pop(){
            if(topIndex == -1) return;
            --topIndex;
        }

        bool empty(){
            return topIndex == -1;
        }

        T top(){
            if(!empty()) return arr[topIndex];
            else cout << "Empty stack" << endl;
        }

        int size(){
            return topIndex + 1;
        }
};

void test1(){
    stackFromArray<int> st1(5);
    st1.push(1);
    st1.push(2);
    cout << "size = " << st1.size() << endl;
    cout << "top = " << st1.top() << endl;
    st1.push(4);
    cout << "is empty = " << st1.empty() << endl;
    st1.push(5);
    st1.push(6);
    cout << "top = " << st1.top() << endl;
    st1.pop();
    cout << "top = " << st1.top() << endl;
    st1.pop();
    st1.pop();
    st1.pop();
    st1.pop();
    st1.top();
}

int main(){
    test1();
    cout << "test2" << endl;
    //下面利用数组快速实现栈
    int st[5];
    //这里用st[0]，也就是*st的值来存储栈中元素个数
    //此时栈顶元素为st[*st]
    *st = 0;
    cout << "size = " << *st << endl;
    //push(5)
    st[++*st] = 5;
    //push(4)
    st[++*st] = 4;
    //top()
    cout << "top = " << st[*st] << endl;
    //pop(),注意越界问题，*st不为0时才可以弹栈
    if(*st) --*st;
    //clear()
    *st = 0;
    return 0;
}