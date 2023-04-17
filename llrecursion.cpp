#include <iostream>
using namespace std;
class linklist
{
private:
    struct node {
        int data;
        node *next;
    }*head;

public:
    linklist()
    {
        head=NULL;
    }

    void add(int num)
    {
        addatend(&head,num);
    }

    void addatend(node **ptr,int num)
    {
        if (*ptr==NULL) {
            (*ptr)=new node;
            (*ptr)->data=num;
            (*ptr)->next=NULL;
        } else addatend(&((*ptr)->next),num);
    }

    void display()
    {
        node *temp=head;
        while(temp) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int length()
    {
        return getlength(head);
    }

    int getlength(node *ptr)
    {
        int l=0;
        if(ptr==NULL)
            return 0;

        else {
            l=1+getlength(ptr->next);
            return l;
        }
    }

    int operator == (linklist &l)
    {
        return compare(head,l.head);
    }

    int compare(node*p,node*q)
    {
        if(p==NULL && q==NULL)
            return 1;

        else {
            if(p==NULL || q==NULL)
                return 0;
            else if(p->data != q->data)
                return 0;
            else
                compare(p->next,q->next);
        }
    }

    void copy(linklist &l)
    {
        duplicate(l.head,&head);
    }

    void duplicate(node *p,node **q)
    {
        if(p!=NULL) {
            *q=new node;
            (*q)->data=p->data;
            (*q)->next=NULL;
            duplicate(p->next,&((*q)->next));
        }
    }

    ~linklist()
    {
        node*q;
        while(head!=NULL) {
            q=head->next;
            delete head;
            head=q;
        }
    }

};

int main()
{
    linklist l1;
    l1.add(10);
    l1.add(20);
    l1.add(30);
    l1.add(40);
    l1.add(50);
    cout<<"displaying elements of first linklist:\n";
    l1.display();
    cout<<"Length of L.L : "<<l1.length()<<endl;

    linklist l2;
    l2.add(100);
    l2.add(200);
    l2.add(300);
    l2.add(400);
    l2.add(500);
    cout<<"displaying elements of second linklist:\n";
    l2.display();

    if(l1==l2)
        cout<<"Both L.Ls are equal\n";
    else
        cout<<"Both L.Ls are different\n";

    linklist l3;
    l3.copy(l1);
    cout<<"displying elements of coppied L.L:\n";
    l3.display();
    return 0;
}
