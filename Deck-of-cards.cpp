#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,x;
    queue<int> deck;
    cin>>n;
    for(int i=1;i<=n;i++)
        deck.push(i);
    cout<<"Discarded cards:";
    while(true){
        cout<<deck.front()<<'.';
        deck.pop();
        x=deck.front();
        deck.pop();
        if(deck.empty())
            break;
        deck.push(x);
    }
    cout<<"\n Last card:"<<x;

    return 0;
}
