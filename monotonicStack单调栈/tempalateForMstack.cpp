/*
    题目描述Description:
        给出项数为 n 的整数数列 a_1,...,a_n.
        定义函数 f(i) 代表数列中第 i 个元素之后第一个大于 a_i的元素的下标,
        即 f(i)=min{j}, where i<j<=n, a_i < a_j.
        若不存在这样的a_j，则 f(i)=0.
        试求出 f(1),...,f(n).

        1≤n≤3×10^6 ，1≤a_i​≤10^9
    
    输入格式Input:
        第一行一个正整数 n.
        第二行 n 个正整数 a_1,…,a_n

    输出格式Output:
        一行 n 个整数表示 f(1),f(2),…,f(n) 的值.

    Sample Input:
        5
        1 4 2 3 5
    Sample Output:
        2 5 4 5 0
    题源:https://www.luogu.com.cn/problem/P5788#ide
*/
/*
    题解：
        1.a[i]存储原始数据,stack存储下标,ans[i]存储答案
        2.对于每个输入的a[i]:
            while stk.size() && a[i] > ans[stk.top()]
                ans[stk.top()] = i;
                stk.pop();
            stk.push(i);
        3.由于编译器，默认没有赋值的ans[i]都是0.
          保险起见，可以在while循环中加一个判断是否弹栈，如果没弹栈，则ans[i]=0.
*/
#include <iostream>
#include <stack>
using namespace std;
const long long N = 1e7;
int n; 
long long a[N], ans[N];
int main(){
    cin >> n;
    stack<int> stk;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        while(stk.size() && a[i] > a[stk.top()]){
            ans[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}

void solution2(){
    /*
        另一种解法，从数组的末尾开始遍历，以a[] = (8,9,7,0,3)为例
        维护一个从栈顶到栈底递增的栈，存储对应元素的下标
        当遍历到a[i]时,栈中已有的都是位于a[i]后面的元素(的下标)
        要找比a[i]大的元素，只需不断弹栈，直到栈顶对应的元素大于a[i]
        若弹栈直到空栈，说明a[i]后面没有比他大的，f(i) = 0
        这样的解法比我的更加稳定
    */
    int a[3000005], ans[3000005];
    stack<int> s;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = n; i; --i) {
        while (s.size() && a[s.top()] <= a[i]) s.pop();
        ans[i] = s.size() ? s.top() : 0, s.push(i);
    }
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);

}