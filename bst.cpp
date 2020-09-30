#include<stdio.h>
#include<stdlib.h>

struct data{
    int nodes;
    struct data *left, *right;
};

bool search(struct data* root, int keys){ 
    while(root!=NULL){
        if(keys>root->nodes){
            root=root->right;
        }
        else if(keys<root->nodes){
            root=root->left;
        }
        else{
            return true;
        }
    }
    return false;
}

struct data* newdata(int select){
    struct data* temporary=new data;
    temporary->nodes=select;
    temporary->left=temporary->right=NULL;
    return temporary;
}

struct data* insert(struct data* data, int nodes){
    if(data==NULL){
        return newdata(nodes);
    }
    if(nodes<data->nodes){
        data->left=insert(data->left, nodes);
    }
    else if(nodes>data->nodes){
        data->right=insert(data->right, nodes);
    }
    return data;
}
  
int main(){
	int num;
    struct data* root=NULL;
    root=insert(root, 40);
    insert(root, 45);
    insert(root, 30);
    insert(root, 21);
    insert(root, 92);
    insert(root, 34);
    insert(root, 42);
    printf("Enter number to search: ");
    scanf("%d", &num);
    if(search(root, num)){
        printf("Data Found!\n");
    }
    else{
        printf("Data Not Found!\n");
    }
    return 0;
} 
