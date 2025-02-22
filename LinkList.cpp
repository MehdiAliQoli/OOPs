#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Linklist {
    Node* head = NULL;
    public:

    void start(int val){
        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }
    void end(int val){
        if(head ==NULL){
            start(val);
            return;
        }
        Node* newnode = new Node(val);
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void position(int val, int pos){
        if(head == NULL || pos == 0){
            start(val);
            return;
        }
    
        Node* newnode = new Node(val);
        Node* temp = head;
    
        
        for(int i = 0; i < pos - 1 && temp->next != NULL; i++){
            temp = temp->next;
        }
    
        newnode->next = temp->next;
        temp->next = newnode;
    }
    

    Node* reverse(){
        Node *prev = NULL , *current = head , *next = NULL;
       
        while(current !=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    Node* reverseLinklistthroughrecursion(Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* NewNode =  reverseLinklistthroughrecursion(head->next);
        head->next->next = head;
        head->next = NULL;
        return NewNode;

    }

    Node* sortLinkList(){
        vector <int> vec={};
        Node* temp = head;
        while(temp !=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        temp = head;
        sort(vec.begin() , vec.end());
        int ind = 0;
        while(temp !=NULL){
            temp->val = vec[ind++];
            temp=temp->next;
        }
        return head;
    }



   
};
