//build from level ordered

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
//function inorder LNR
void inorder(Node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//function preordered NLR
void preordered(Node*root){
    if(root == NULL){
         return;
    }
    cout<<root->data <<" ";
    preordered(root->left);
    preordered(root->right);
}

//function postordred LRN
void postordered(Node*root){
    if(root == NULL){
        return;
    }
    postordered(root->left);
    postordered(root->right);
    cout<<root->data <<" ";
    
}

//buil from level ordered

void buildFromLeveOrder(Node*root){
    queue<Node*>q;
    cout<<"Enter data for root" << endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node*temp = q.front();
        q.pop();

        cout<<"Enter left Node "<<temp->data <<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right data for "<<temp->data <<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
    Node*root = NULL;

    buildFromLeveOrder(root);
    Levelordertraversal(root);

    //creating a tre
    // root = buildtree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // cout<<"printing the level"<<endl;
    // Levelordertraversal(root);//1 3 7 -1 5 17 -1 -1 -1 -1 -1

    // cout<<"inordered traversal is :" <<endl;
    // inorder(root);

    // cout<<"preoredered traversal is :"<<endl;
    // preordered(root);

    // cout<<"postordere traversal is"<<endl;
    // postordered(root);

    // builfromlevelordere(root);

    return 0;
}