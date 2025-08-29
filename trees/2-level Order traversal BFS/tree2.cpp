//level order traversal BFS

#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node*left;
    Node*right;

    //constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node*buildtree(Node*root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting left"<<endl;
    root->left = buildtree(root->left);

    cout<<"Enter the data for insserting in right"<<endl;
    root->right = buildtree(root->right);

    return root;
}
void Levelordertraversal(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);//separation

    while(!q.empty()){
        Node*temp = q.front();
        
        q.pop();

        if(temp == NULL){//pura level traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){//queue still has some child node
                q.push(NULL);//separation
            }
        }
        else{
            cout<<temp->data <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node*root = NULL;
    //creating a tre
    root = buildtree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"printing the level"<<endl;
    Levelordertraversal(root);//1 3 7 -1 5 17 -1 -1 -1 -1 -1
    return 0;
}




