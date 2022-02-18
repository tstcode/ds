#include<stdio.h> 
#include<stdlib.h> 
struct bstnode{ 
int data; 
struct bstnode *left,*right; 
}; 
struct bstnode* search(struct bstnode *root,int d){ 
if(root==NULL || root->data==d) 
return root; 
else if(d<root->data) 
return search(root->left,d); 
else 
return search(root->right,d); 
} 
struct bstnode* newnode(int d){ 
struct bstnode *p; 
p=(struct bstnode*)malloc(sizeof(struct bstnode)); 
p->data=d; 
p->left=p->right=NULL; 
return p; 
} 
struct bstnode* insert(struct bstnode *root,int d){ 
if(root==NULL) 
return newnode(d); 
if(d< root->data) 
root->left= insert(root->left,d); 
else 
root->right= insert(root->right,d); 
return root; 
} 
struct bstnode* minimum(struct bstnode *root){ 
if(root==NULL) 
return root; 
else if(root->left==NULL) 
return root; 
else 
return minimum(root->left); 
} 
struct bstnode* delete(struct bstnode *root,int d){ 
struct bstnode *q; 
if(root==NULL) 
return root; 
if(d<root->data) 
root->left=delete(root->left,d); 
else if(d>root->data) 
root->right=delete(root->right,d); 
else{ 
if(root->left==NULL){ 
q=root->right; 
free(root); 
return q; 
} 
else if(root->right==NULL){ 
q=root->left; 
free(root); 
return q; 
 
} 
else{ 
q=minimum(root->right); 
int t=q->data; 
q->data=root->data; 
root->data=t; 
return delete(root->right,d); 
} 
} 
return root; 
} 
 
struct bstnode* maximum(struct bstnode *root){ 
if(root==NULL) 
return root; 
else if(root->right==NULL) 
return root; 
else 
return maximum(root->right); 
} 
void inorder(struct bstnode *root){ 
if(root!=NULL){ 
inorder(root->left); 
printf("%d ",root->data); 
inorder(root->right); 
} 
} 
 
int main(){ 
struct bstnode *root=NULL,*p; 
int op,d; 
while(1){ 
printf("\n1.Insertion 2.Deletion 3.Search 4.Inoder 5.Minimum 6.Maximum 7.exit\n"); 
printf("Enter your option:\n"); 
scanf("%d",&op); 
switch(op){ 
case 1:printf("Enter element to be inserted:\n"); 
scanf("%d",&d); 
root=insert(root,d); 
inorder(root); 
break; 
case 2:printf("Enter an Element to be deleted:\n"); 
scanf("%d",&d); 
root=delete(root,d); 
inorder(root); 
break; 
case 3:printf("Enter an element to be searched:\n"); 
scanf("%d",&d); 
p=search(root,d); 
if(p) 
printf("Search is Successfull!!\n"); 
else 
printf("Search is unsuccesfull\n"); 
break; 
case 4:inorder(root);break; 
case 5:p=minimum(root); 
if(p) 
printf("Minimum element is %d",p->data); 
else 
printf("Tree is Empty!!!\n"); 
break; 
case 6:p=maximum(root); 
if(p) 
printf("Maximum element is %d",p->data); 
else 
printf("Tree is Empty!!!\n"); 
break; 
 
case 7:printf("Exiting Program...\n"); 
exit(0); 
break; 
default: printf("Enter a valid option from 1 to 9!!!\n"); 
} 
} 
}
