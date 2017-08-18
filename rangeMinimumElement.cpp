#include <bits/stdc++.h>
using namespace std;
int tree[4*100000];
int arr[100000];
void build(int start,int end,int index)
{
    if(start==end)
        tree[index]=arr[start];
    else
    {
       int mid=start+(end-start)/2;
        build(start,mid,2*index+1);
        build(mid+1,end,2*index+2);
        tree[index]=min(tree[2*index+1],tree[2*index+2]);

    }
}
int query(int start,int end,int qs,int qe,int index)
{
    if(start>qe || end<qs )
        return INT_MAX;
    if(start>=qs && end<=qe)
        return tree[index];
    int mid=start+(end-start)/2;
    return min(query(start,mid,qs,qe,2*index+1),query(mid+1,end,qs,qe,2*index+2));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   int n;
    cin>>n;
    memset(arr,0,sizeof(arr));
    memset(tree,0,sizeof(tree));
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(0,n-1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int qs,qe;
        cin>>qs>>qe;
        cout<<query(0,n-1,qs,qe,0)<<endl;
    }

    return 0;
}
