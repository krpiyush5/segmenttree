#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct node
{
    int first,second;
};
node tree[4*100000];
int arr[100005];
void build(int start,int end,int index)
{
    if(start==end)
    {
        tree[index].first=arr[start];
        tree[index].second=INT_MIN;
    }

    else
    {
        int mid=start+(end-start)/2;
        build(start,mid,2*index+1);
        build(mid+1,end,2*index+2);
        tree[index].first=max(tree[2*index+1].first,tree[2*index+2].first);
        tree[index].second=min(max(tree[2*index+1].first,tree[2*index+2].second),max(tree[2*index+1].second,tree[2*index+2].first));


    }

}
node queries(int start,int end,int qs,int qe,int index)
{
    node result;
    result.first=result.second=-1;
    if(start>qe || end<qs)
        return result;
    if(start>=qs && end<=qe)
    {
        return tree[index];
    }
    int mid=start+(end-start)/2;
    if(qs>mid)
        return queries(mid+1,end,qs,qe,2*index+2);
    if(qe<=mid)
        return queries(start,mid,qs,qe,2*index+1);
    node left=queries(start,mid,qs,qe,2*index+1);
    node right=queries(mid+1,end,qs,qe,2*index+2);
    result.first=max(right.first,left.first);
    result.second=min(max(left.first,right.second),max(left.second,right.first));
    return result;
}
void update(int start,int end,int idx,int val,int index)
{
    if(start==end)
    {
        tree[index].first=val;
        tree[index].second=INT_MIN;
    } else
    {
        int mid=start+(end-start)/2;
        if(idx<=mid)
        {
            update(start,mid,idx,val,2*index+1);
        } else
            update(mid+1,end,idx,val,2*index+2);
        tree[index].first=max(tree[2*index+1].first,tree[2*index+2].first);
        tree[index].second=min(max(tree[2*index+1].first,tree[2*index+2].second),max(tree[2*index+1].second,tree[2*index+2].first));

    }
}
int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    memset(arr,0,sizeof(arr));
    memset(tree,0,sizeof(tree));
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(0,n-1,0);
    ll q;
    cin>>q;
    while(q--)
    {
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c=='Q')
        {
            node ans=queries(0,n-1,a-1,b-1,0);
            cout<<ans.second+ans.first<<endl;
        } else
            update(0,n-1,a-1,b,0);
    }

    return 0;

}