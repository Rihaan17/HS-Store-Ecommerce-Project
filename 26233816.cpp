#include<iostream>
using namespace std;

struct node
{
    long long data,pos;
    node *left;
    node *right;
};

struct node* newnode(long long item, long long pos)
{
    struct node *node=(struct node*)new struct node;
    node->data = item;
    node->left = node->right = NULL;
    node->pos = pos;
    cout<<pos<<endl;
    return node;
}

struct node* min(struct node* root)
{
    if(root->left==NULL)
    {
        return root;
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct node* insert(struct node *node,long long key, long long pos)
{
    if(node== NULL)
    {
        return newnode(key,pos);
    }
    if(key < node->data)
    {
        pos=2*pos;
        node->left = insert(node->left,key,pos);
    }
    else if(key > node->data)
    {
        pos=2*pos+1;
        node->right= insert(node->right,key,pos);
    }
    return node;
}

struct node* del(struct node* root,long long data)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(data > root->data)
    {
        root->right= del(root->right,data);
        return root;
    }
     if(data<root->data)
    {
        root->left=del(root->left,data);
        return root;
    }
        cout << root->pos;
        cout << "\n";
        if(root->left==NULL && root->right==NULL)
        {
            struct node* temp = root;
            delete temp;
            return NULL;
        }
        if(root->left==NULL)
        {
            struct node* temp =root;
            root=root->right;
            delete temp;
            return root;
        }
        if(root->right==NULL)
        {
            struct node* temp=root;
            root=root->left;
            delete temp;
            return root;
        }

        {
            struct node* temp = min(root->right);
            root->data=temp->data;
            root->right=del(root->right,temp->data);
            return root;
        }

}

int main()
{
    struct node *root = NULL;
    long long n;
    long long data;
    char c;
    cin>>n;
    while(n--)
    {
        cin>>c>>data;
        if(c=='i')
        {
            root = insert(root,data,1);
        }
        else if(c=='d')
        {
            root = del(root,data);
        }
    }
    return 0;
}
