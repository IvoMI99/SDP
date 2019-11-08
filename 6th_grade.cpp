#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[512];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    stack<int> u1;
    stack<int> u2;
    for(int i=1;i<=n;i++)
        u1.push(i);
    int arrIndex=0;
    while(arrIndex<n){
        while(!u1.empty() && arr[arrIndex]<=u1.top()){
            u2.push(u1.top());
            u1.pop();
            cout<<1;
        }
        while(arr[arrIndex]>u2.top()){
            u1.push(u2.top());
            u2.pop();
            cout<<3;
        }
        u2.pop();
        cout<<2;
        arrIndex++;
    }
    return 0;
}
