#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class TreeNode
{
public:
    int value;
public:
    TreeNode *left,*right;
};
void CreateNode(TreeNode*ptr,int val)
{
    ptr->value=val;
    ptr->left=NULL;
    ptr->right=NULL;
}
void AddNode(TreeNode**root,int val)
{
    if(*root==NULL)
    {
        *root=new TreeNode();
        CreateNode(*root,val);
    }
    else
    {
        if ((*root)->value<val)
        {
            AddNode(&(*root)->right,val);
        }
        else
        {
            AddNode(&(*root)->left,val);
        }
    }


}

void Printpre(TreeNode *node)
{
    if (node==NULL) return;
    cout<<node->value<<" ";
    Printpre( node->left );
    Printpre( node->right );
}
TreeNode* FindMin(TreeNode**root)
{
    if(*root==NULL)
    {
        cout<<"Tree Doesn't Exist";
    }
    else
    {
        if((*root)->left==NULL)
            return *root;
        else
            FindMin(&(*root)->left);
    }
}
TreeNode* FindMax(TreeNode**root)
{
    if(*root==NULL)
    {
        cout<<"Tree Doesn't Exist"<<endl;
    }
    else
    {
        if((*root)->right==NULL)
            return *root;
        else
            FindMax(&(*root)->right);
    }
}
TreeNode* Predecesor(TreeNode**root)
{
    if(*root==NULL)
    {
        cout<<"Tree doesn't exist"<<endl;
    }
    else
    {
        return FindMax(&(*root)->left);
    }
}
TreeNode* Succesor(TreeNode**root)
{
    if(*root==NULL)
    {
        cout<<"Tree doesn't exist"<<endl;
    }
    else
    {
        return FindMin(&(*root)->right);
    }
}
//doesn't work if node is not found
TreeNode* Search(TreeNode**root,int num)
{

    if((*root)->value==num)
    {
        return (*root);
    }
    else if(num<(*root)->value)
    {
        Search(&(*root)->left,num);
    }
    else if (num>(*root)->value)
    {
        Search(&(*root)->right,num);
    }

}
void Delete(TreeNode**root,int key)
{
    TreeNode *ptr=Search(root,key);
    TreeNode *succ=Succesor(root);
}
void Tester(TreeNode**root)
{

    //for(int i=0; i<rand()%100+10; i++)
    //{
    //    AddNode(root,rand()%100+10);
    //}
    AddNode(root,18);
    AddNode(root,12);
    AddNode(root,56);
    AddNode(root,4);
    AddNode(root,20);
    AddNode(root,43);
    AddNode(root,82);
    AddNode(root,48);
    Printpre(*root);
    TreeNode*Min=FindMin(root);
    cout<<endl<<Min->value;
    TreeNode*Max=FindMax(root);
    cout<<endl<<Max->value;
    TreeNode*predecessor=Predecesor(root);
    cout<<endl<<predecessor->value;
    TreeNode*succesor=Succesor(root);
    cout<<endl<<succesor->value;
    Delete(root,48);
}
int main()
{
    TreeNode *root =NULL;
    Tester(&root);
}
