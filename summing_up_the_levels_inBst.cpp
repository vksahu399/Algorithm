#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define rfo(i, n) for (int i = n - 1; i >= 0; i--)
#define fo1(i, n) for (int i = 1; i <= n; i++)
#define rfo1(i, n) for (int i = n; i > o; i--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define mii map<int, int>
#define mivi map<int, vector<int>>
#define int long long
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1e9

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
node *bst(int *a, int n);
int height(node *root);
void lvl_sum(node* node, int level, int sum[]);

signed main()
{
    fast int n;
    cin >> n;
    int a[n];
    fo(i, n)
    {
        cin >> a[i];
    }
    node *root=bst(a,n);

    int lvl=height(root)+1;

    int sum_all[lvl]={0};

    lvl_sum(root,0,sum_all);

    int k;
    cin>>k;
    int b[k];

    fo(i,k)
    {
        cin>>b[i];
    }

    int sum=0;

    fo(i,k)
    {
        sum+=sum_all[b[i]-1];
    }

    cout<<sum;

    return 0;
}

node *bst(int *a, int n)
{
    node *root = new node(a[0]); // first element root node
    stack<node *> s;
    s.push(root);

    fo1(i, n-1)
    {
        node *temp = NULL;

        while (!s.empty() && a[i] > s.top()->data)
        {
            temp = s.top();
            s.pop();
        }

        if(temp==NULL)
        {
            temp=s.top();
            temp->left=new node(a[i]);
            s.push(temp->left);
        }
        else
        {
            temp->right=new node(a[i]);
            s.push(temp->right);
        }
    }

    return root;
}

int height(node *root)
{
    if(root->left==NULL&&root->right==NULL)
    {
        return 0;
    }
    int left=0;
    if(root->left!=NULL)
    {
        left=height(root->left);
    }

    int right=0;
    if(root->right!=NULL)
    {
        right=height(root->right);
    }

    return(max(left,right)+1);
}

void lvl_sum(node* node, int level, int sum[])
{
    if (node == NULL)
    {
        return;
    }

    sum[level] += node->data;

    lvl_sum(node->left, level + 1, sum);
    lvl_sum(node->right, level + 1, sum);
}