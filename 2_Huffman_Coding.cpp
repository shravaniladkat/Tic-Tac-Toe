#include<bits/stdc++.h> 
using namespace std; 
 
struct Node{ 
      char ch; 
      int freq; 
      Node*left; 
      Node*right; 
 
      Node(char c,int f){ 
        ch=c; 
        freq=f; 
        left=right=nullptr; 
      } 
}; 
 
struct Compare{ 
    bool operator()(Node*left,Node*right){ 
        return left->freq > right->freq; 
    } 
}; 
 
void printtree(Node* root,string str){ 
    if(!root){ 
        return; 
    } 
    if(!root->left && !root->right){ 
        cout<<root->ch<<":"<<str<<"\n"; 
        return; 
    } 
    printtree(root->left,str+"0"); 
    printtree(root->right,str+"1"); 
} 
 
void hufmann(const string& text){ 
    unordered_map<char,int> freq; 
    for(char s:text){ 
        freq[s]++; 
    } 
 
    priority_queue<Node*,vector<Node*>,Compare> minheap; 
     
    for(auto it:freq){ 
        minheap.push(new Node(it.first,it.second)); 
    } 
 
    while(minheap.size()>1){ 
        Node*left=minheap.top(); 
        minheap.pop(); 
        Node*right=minheap.top(); 
        minheap.pop(); 
 
        Node*newNode=new Node('$',left->freq+right->freq); 
        newNode->left=left; 
        newNode->right=right; 
 
        minheap.push(newNode); 
    } 
    Node*root=minheap.top(); 
    cout<<"Huffmann Coding\n"; 
    printtree(root,""); 
 
} 
 
int main(){ 
    string text; 
    cout<<"Enter the string:"; 
    cin>>text; 
    hufmann(text);
    return 0;
}