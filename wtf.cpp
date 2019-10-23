#include <iostream>
#include <vector>

struct Pair
{
    int x,y;
};

using namespace std;

vector<int> a;
vector<int> path;
vector<Pair> paths;
int n,m;

void Inp();

vector<int> Lis()
{
    vector<int> p;
    vector<int> q;
    for(size_t i=0;i<a.size();i++)
    {
        p.push_back(1);
        q.push_back(i);
    }
    size_t i, j;
    for(i=1;i<a.size();i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i] && a[i]-a[j]<=2 && p[j]+1 > p[i])
            {
                p[i] = p[j]+1;
                q[i]=j;
                if(p[i] == m)
                {
                    return q;
                }
            }
        }
    }
}

int main()
{
    int i=0;
    Inp();
    vector<int> q = Lis();
    for (auto it = q.cbegin(); it != q.cend()/* && i<m*/; it++, i++) cout<<a[*it]<<' ';

    return 0;
}






















void Inp()
{
    cin>>n>>m;
    path.resize(n);
    paths.resize(m);
    for(int i=0;i<m;i++)
     cin>>paths[i].x>>paths[i].y;
    while(true)
    {
        int t;
        cin>>t;
        if(t <= 0 || t>1000) break;
        a.push_back(t);
    }
}
