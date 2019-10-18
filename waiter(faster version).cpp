#include <iostream>
#include <vector>
#include<stack>
using namespace std;

vector<stack<int> >a, b;
vector<int>p;

void primes(int q){
    p.resize(q+1);
    p[1]=2;
    int cnt=2, x=3;
    while(cnt<=q){
        bool isPrime=true;
        for(int j=1; j<cnt && isPrime; j++)
            isPrime=(x%p[j]!=0);
        if(isPrime){
            p[cnt]=x;
            cnt++;
        }
        x++;
    }
}

void read(int n, int q){
    int x;
    a.resize(q+1);
    b.resize(q+1);
    for(int i=0;i<n;i++){
        cin>>x;
        a[0].push(x);
    }
    primes(q);
}

void serve(int i){
    int x;
    while(!a[i-1].empty()){
        x=a[i-1].top();
        a[i-1].pop();
        if(x%p[i]==0) b[i].push(x);
        else a[i].push(x);
    }
}

void print(int q){
    for(int i=0; i<=q; i++){
        while(!b[i].empty()){
            cout<<b[i].top()<<endl;
            b[i].pop();
        }
    }

    while(!a[q].empty()){
        cout<<a[q].top()<<endl;
            a[q].pop();
    }
}

int main(){
    int n, q;
    cin>>n>>q;
    read(n, q);

    for(int i=1; i<=q; i++)
        serve(i);

    print(q);
    return 0;
}

