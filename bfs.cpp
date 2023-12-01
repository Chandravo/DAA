//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;

#define V 4

class Pair{
    public:
    int first;
    int second;
};

class Queue{
    public:
    Pair arr[10000];
    int f;
    int b;

    Queue(){
        f = -1;
        b = -1;
    }
    void push(Pair x){
        if (f==-1) f = 0;
        b++;
        arr[b] = x;
    }
    void pop(){
        f++;
    }
    Pair front(){
        return arr[f];
    }
    int sz(){
        return b-f+1;
    }

};

void bfs(int adj[V][V], int src){
    Queue q = Queue();
    Pair p = Pair();
    p.first = src;
    p.second = -1;
    q.push(p);
    int visited[V]={0};
    while (q.sz()>0){
        int m = q.sz();
        for (int i=0;i<m;i++){
            Pair v = q.front();
            q.pop(); 
            if(visited[v.first]==0) cout<<"Node : "<<v.first+1<<" Parent : "<<v.second+1<<"\t";
            visited[v.first]=1;
            for (int j=0;j<V;j++){
                if (adj[v.first][j]!=0 && visited[j]==0){
                    Pair temp = Pair();
                    temp.first = j;
                    temp.second = v.first;
                    q.push(temp);
                }
            }
        }
        cout<<endl;
    }
}

int main(){
    int adj[V][V] = {
        {0,1,1,0},
        {0,0,1,1},
        {0,0,0,1},
        {0,0,0,0}
    };
    int src;cin>>src;
    bfs(adj, src-1);
}