/*
    题目描述Description:
        某地有 N 个能量发射站排成一行，每个发射站i都有不相同的高度 H_i,
        并能向两边（两端的发射站只能向一边）同时发射能量值为 V_i的能量，
        发出的能量只被两边最近的且比它高的发射站接收。显然，每个发射站发来的能量有可能被0或1或2个其他发射站所接受。

        请计算出接收最多能量的发射站接收的能量是多少。

    输入格式Input:
        第 1 行一个整数 N
        第 2 到 N+1 行，每行有两个整数 H_i和 V_i，表示第 i个发射站的高度和发射的能量值。

    输出格式Output:
        输出仅一行，表示接收最多能量的发射站接收到的能量值。答案不超过 32 位带符号整数的表示范围。

    Sample Input:
        3
        4 2 
        3 5 
        6 10
    Sample Output:
        7
    题源：https://www.luogu.com.cn/problem/P1901#ide
*/

/*
    实际上就是找距离h[i]两侧最近的且比他大的元素
    只需维护两个单调栈，一个从头开始遍历，一个从尾开始遍历
    期间利用弹栈做一些运算
*/
#include<iostream>
#include<stack>
using namespace std;
int n;
const int N = 1e7;
long long h[N], v[N], ans[N], res = 0;
int main(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> h[i] >> v[i];
    }
    //从末尾开始遍历
    stack<int> st1;
    for(int i = n; i; --i) {
        while(st1.size() && h[i] >= h[st1.top()]){
            st1.pop();
        }
        if(st1.size()) ans[st1.top()] += v[i];
        st1.push(i);
    }
    //从开头开始遍历
    stack<int> st2;
    for(int i = 1; i <= n; ++i){
        while (st2.size() && h[i] >= h[st2.top()]){
            st2.pop();
        }
        if(st2.size()) ans[st2.top()] += v[i];
        st2.push(i);
    }
    //输出答案
    for(int i = 1; i <= n; i++) res = max(res, ans[i]);
    cout << res << endl;
}