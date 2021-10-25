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
node *search(node *root, int data);
void predecessor(node *root);


signed main()
{
    fast
        fast int n;
    cin >> n;
    int a[n];
    fo(i, n)
    {
        cin >> a[i];
    }
    node *root = bst(a, n);
    int k;
    cin >> k;
    node *found = search(root, k);
    if(found==NULL)
    {
        cout<<0;
    }
    else
    {
        if(found->left==NULL)
        {
            cout<<0;
        }
        else
        {
            predecessor(found->left);
        }
    }

    return 0;
}

node *bst(int *a, int n)
{
    node *root = new node(a[0]); // first element root node
    stack<node *> s;
    s.push(root);

    fo1(i, n - 1)
    {
        node *temp = NULL;

        while (!s.empty() && a[i] > s.top()->data)
        {
            temp = s.top();
            s.pop();
        }

        if (temp == NULL)
        {
            temp = s.top();
            temp->left = new node(a[i]);
            s.push(temp->left);
        }
        else
        {
            temp->right = new node(a[i]);
            s.push(temp->right);
        }
    }

    return root;
}

node *search(node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (root->data > data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
    return NULL;
}

void predecessor(node *root)
{
    if (root->right == NULL)
    {
        cout << root->data;
    }
    else
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        cout << root->data;
    }
}