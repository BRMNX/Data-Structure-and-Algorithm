/*
    Description:
        Farmer John has N cows at a messy hair festival.
        Each cow is standing in the same row facing right and they are numbered 1,2,⋯,N from left to right. 
        The height of the cow numbered i is h_i 
        The N-th cow is at the front and the first cow is at the end.
        eg. END->Cow#1->Cow#2->Cow#2->...->Cow#N->Front
        For the i-th cow: 
            1.If there is a j-th cow (j > i) to its right such that the height of the
            j-th cow is a "local peak", then the range that the i-th cow can see is from i+1-th cow to j-th cow.
            2.If there not exists such local "local peak", then the i-th cow can see all cows to its right.
        Denote the number of cows that the i-th cow can see as C_i.
    
    Input:
        Enter a total of N+1 lines.
        The first row is an integer N, representing the number of cows.
        The next N rows, each with an integer a_i, represent the height of the 1,2,⋯,N-th cow.

    Output:
        Each line with an integer, representing C_1+C_2+...+C_N.
    
    Sample Input:
        6
        10
        3
        7
        4
        12
        2
    Sample Output:
        5
*/

#include <iostream>
using namespace std;
int N, h;
long long ans;

int main(){
    cin >> N;
    int* st = new int[N];
    *st = 0;
    while(N--){
        cin >> h;
        while(h >= st[*st] && *st){
            --*st;
        }
        ans += *st;
        st[++*st] = h;
    }
    cout << ans << endl;
}