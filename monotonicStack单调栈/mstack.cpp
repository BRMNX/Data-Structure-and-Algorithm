#include <iostream>
using namespace std;
const int N = 100;
void insert(int x, int *mst, int *sst){
    if(*mst == 0){
        mst[++*mst] = x;
        return;
    }
    //当x大于mst的最小元素，则持续弹栈
    //注意弹栈不要越界
    while(x > mst[*mst] && *mst){
        sst[++*sst] = mst[*mst];
        --*mst;
    }
    mst[++*mst] = x;
    while(*sst){
        mst[++*mst] = sst[*sst];
        --*sst;
    }
    return;
}
void printMST(int *mst){
    for(int i = 1; i <= *mst; ++i) cout << mst[i] << " ";
    cout << endl;
}
int main(){
    //用两个栈实现单调栈，其中mst是要维护的单调栈
    //要求栈自顶向下单调递增
    //mst[] = 9 5 3 2 1
    int mst[N], sst[N];
    *mst = 0, *sst = 0;
    insert(2, mst, sst);
    printMST(mst);
    insert(5, mst, sst);
    printMST(mst);
    insert(1, mst, sst);
    printMST(mst);
    insert(3, mst, sst);
    printMST(mst);
    insert(9, mst, sst);
    printMST(mst);
}