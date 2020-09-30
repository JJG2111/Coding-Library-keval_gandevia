#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;
node* get_new_node(int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=data;
    return newnode;
}
void add_to_bst(node **head,int data)
{
    
    if(*head==NULL)
    {
        node *temp=get_new_node(data);
        *head=temp;
        // printf("%d ",(*head)->data);
    }
    else
    {
        if(data<(*head)->data)
        {
            add_to_bst(&(*head)->left,data);
        }
        else
        {
            add_to_bst(&(*head)->right,data);
        }
        
    }
    
}
node *prev=NULL;
node* search(node **head,node **baap,int data,int call)
{
    
    node *tmp_head=*head;
    if(tmp_head==NULL)
    {

        prev=NULL;
        return NULL; 
    }
    else if(tmp_head->data==data)
    {
        // printf("%p ",tmp_head);
        if(call==0)
        {
            prev=NULL;
        }
        else
        {
            prev=*baap;
        }
        // printf("%p ",tmp_head);
        return tmp_head;
    }
    else if(tmp_head->data>data)
    {
        tmp_head=search(&(tmp_head->left),head,data,call+1);
    }
    else if(tmp_head->data<data)
    {
        tmp_head=search(&(tmp_head->right),head,data,call+1);
    }
}
void inorder(node **head)
{
    node *tmp=*head;
    if(tmp->left!=NULL)
    {
        inorder(&(tmp->left));
    }
    printf("%d ",tmp->data);
    if(tmp->right!=NULL)
    {
        inorder(&(tmp->right));
    }
}
void preorder(node **head)
{
    node* tmp=*head;
    printf("%d ",tmp->data);
    if(tmp->left!=NULL)
    {
        preorder(&(tmp->left));
    }
    if(tmp->right!=NULL)
    {
        preorder(&(tmp->right));
    }
    
}

int find_min_in_right(node **head,node **prev_ptr)
{
       
    if((*head)->left==NULL)
    {
        
        return (*head)->data;
    }
    else
    {
        find_min_in_right(&(*head)->left,head);
    }
    
    
}
void delete(node **head,int data)
{
    node *tmp=search(head,NULL,data,0);
    node *father=prev;
    // printf("\n \n \n%d %d\n",tmp->data,father->data);
    if(tmp==NULL)
    {
        printf("Node %d is not found in the tree",data);
        exit(0);
    }
    else if(tmp->left!=NULL && tmp->right==NULL)
    {
        // printf("onechild");
        tmp->data=(tmp->left)->data;
        tmp->left=(tmp->left)->left;
        
    }
    else if(tmp->right!=NULL && tmp->left==NULL)
    {
        printf("lonechild");
        tmp->data=(tmp->right)->data;
        tmp->right=(tmp->right)->right;
        
    }
    else if(tmp->right==NULL && tmp->left==NULL)
    {
        // printf("leaf node");
        if(father->left==tmp)
        {
            //confirm left child
            father->left=tmp->left;
        }    
        else
        {
            //confirm right child
            father->right=tmp->right;
        }
        
        
    }
    else
    {
        int ret=find_min_in_right(&(tmp->right),NULL);
        // printf("returned");
        node *search_node=search(head,NULL,ret,1);
        
        // printf("%p ",search_node);
        node *search_father=prev;
        if(tmp->right==search_node)
        {
            tmp->data=search_node->data;
            tmp->right=search_node->right;
        }
        else if(search_node->right!=NULL)
        {
            search_father->left=search_node->right;
            tmp->data=search_node->data;
        }
        else
        {
            search_father->left=NULL;
            tmp->data=search_node->data;
        }
        
        
    }
    
    
}

int main()
{
    node *head=(node*)malloc(sizeof(node));
    head=NULL;
    
    int no;
    scanf("%d",&no);
    for (int i = 0; i < no; i++)
    {
        int temp;
        scanf("%d",&temp);
        add_to_bst(&head,temp);
    }
    // inorder(&head);
    int ask_no;
    scanf("%d",&ask_no);
    for(int i=0;i<ask_no;i++)
    {
        int ask;
        scanf("%d",&ask);
        delete(&head,ask);
        // inorder(&head);
        
    }
    
    inorder(&head);
    printf("\n");
    preorder(&head);

    // delete(&head,ask);
    // inorder(&head);
    //print(&head);
}
