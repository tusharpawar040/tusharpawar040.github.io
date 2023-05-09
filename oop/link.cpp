#include<iostream>
using namespace std;

  class node
  {
    public:
    int data;
    node* next;

    node(int val)
    {
     data = val;
     next = NULL;
    }
   };

    void attachBegin(node*&head,int val)
    {
     node* n=new node(val);
     n->next=head;
     head=n;
    }

    void attachEnd(node*&head,int val)
    {
     node* n=new node(val);
     node*temp=head;
     if(head==NULL)
     {
      head=n ;
      return ;
     }

     while(temp->next!=NULL)
     {
      temp=temp->next;
     }
      temp->next=n;
    }

    void detachBegin(node*&head)
    {
     node*n;
     if(head==NULL)
     {
      return ;
     }
     else
     {
      n=head;
      head=n->next;
     }
    }




    void display(node* head)
    {
     node*temp=head;
     while(temp!=NULL)
     {
      cout<<temp->data<<" ";
      temp=temp->next;
     }
     cout<<endl;
    }


   int main()
   {
    node*head=NULL;
    attachEnd(head,11);
    attachEnd(head,22);
    attachEnd(head,33);
    display(head);

    attachBegin(head,44);
    display(head);

    detachBegin(head);
    display(head);

      return 0;
   }
