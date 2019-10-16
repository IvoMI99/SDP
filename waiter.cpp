#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> primes;
vector<stack<int> > a,b;

void primes_generator(int q){
    primes.resize(q+1);
    int i=1,x=2;
    for(int i;i<=q;i++){
        bool flag=false;
        while(flag==false){
            flag=true;
            for(int j=1;j<i && flag;j++){
                flag=!(x%primes[j]==0);
            }
        if(!flag)x++;
        }
        primes[i]=x;
    }
}

void serve(int i){
    while(!a[i-1].empty()){
        int x=a[i-1].top();
        a[i-1].pop();
        if(x%primes[i]==0){
            b[i].push(x);
        }
        else {
            a[i].push(x);
        }
    }
}

void print(int q){
    for(int i=0;i<=q;i++){
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
    int n,x,q;
    cin>>n>>q;
    a.resize(q+1);
    b.resize(q+1);
    for(int i=0;i<n;i++){
        cin>>x;
        a[0].push(x);
    }
    primes_generator(q);
    for(int i=1;i<=q;i++)
        serve(i);
    print(q);
    return 0;
}
