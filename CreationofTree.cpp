#include<bits/stdc++.h>
using namespace std;

class Node
{
    // For tree it is created Tree Node 
public:
    Node *lchild;
    int data;
    Node *rchild;
};


class Queue
{
    // It is Queue Data Structure 
    // Tree Using Queue Data Structure 
    private:
    int front;
    int rear;
    int size;
    Node **Q; // Node is pointer and Q is also a pointer so two pointer is required 

    public:
    Queue()
    {
        front=rear=-1;
        size=10;
        Q=new Node*[size]; // We are taking Node insted of int becouse of we are passing in queue Not a Int 
    }
    Queue(int size)
    {
        this->size=size;
        front=rear=-1;
        Q=new Node*[this->size];
    }

    void enqueue(Node *x);
    Node* dequeue();
    void Display();
    int isEmpty();
};

int Queue::isEmpty()
{
    return rear==front;
}
void Queue::enqueue(Node *x)
{
    if(rear==size-1)
    {
        cout<<"Not possible "<<endl;
    }
    else
    {
        rear++;
        Q[rear]=x;
    }
}

Node* Queue::dequeue()
{
    Node* x=NULL;
    if(rear==front)
    {
        cout<<"Queue Is Empty Not Possible "<<endl;

    }
    else
    {
        x=Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display()
{
    int i;
    for(i=front+1;i<rear+1;i++)
    {
        cout<<Q[i]<<" ";
    }
}



class Tree 
{
public:
    Node *root;
    Tree()
    {
        root=NULL;
    }

    void CreateTree();
    void Preorder(Node *p);
    void PostOrder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *root);
};

void Tree::CreateTree()
{
    Node *p,*t=NULL;
    int x;
    Queue q(100); // Queue Of sie 100 will be Created We are Creating object of class Queue 

    cout<<"Enter root Value ";
    cin>>x;
    // Root Node Creation Of tree 
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p=q.dequeue();
        cout<<"Enter left child of "<<p->data<<" ";
        cin>>x;
        // Left child insertion
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->rchild=t->lchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"Enter rigth child of "<<p->data<<" ";
        cin>>x;
        //Right child Insertion 
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }

}

void Tree::Preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }  
}
void Tree::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void Tree::PostOrder(Node *p)
{
    if(p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout<<p->data<<" ";
    }
}
void Tree::Levelorder(Node *p)
{
    Queue q(100);
    cout<<root->data;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        root=q.dequeue();
        if(root->lchild)
        {
            cout<<root->lchild->data;
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            cout<<root->rchild->data;
            q.enqueue(root->rchild);
        }
    }
}
int  Tree::Height(Node *p)
{
    int x=0,y=0;
    if(root==0)
    {
        return 0;
    }
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }

}
int main()
{
   Tree t;
   
   t.CreateTree();
   cout<<"Preorder traversal Is :";
   t.Preorder(t.root);
   cout<<endl;
   cout<<"Inorder Traversal Is :";
   t.Inorder(t.root);
   return 0;
}