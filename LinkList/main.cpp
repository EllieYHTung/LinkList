//
//  main.cpp
//  LinkList
//
//  Created by YunHua Tung on 2019/4/3.
//  Copyright © 2019 YunHua Tung. All rights reserved.
//

#include <iostream>
using namespace std;
template <class T>
class Node{
public:
    T element;
    Node* previous;
    Node* next;
};
template <class B>
class LinkList{
public:
    LinkList(){
        headNode->previous=headNode->next=headNode;
    }
    void insertAtIndex(int index, B _element){
        Node<B>* temp=headNode;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        insert(temp, _element);
    }
    void printOut()const{
        Node<B>* temp=headNode->next;
        while(temp!=headNode){
            cout<<temp->element<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
    
    void removeElement(B _element){
        Node<B>* currentNode=headNode->next;
        while(currentNode!=headNode){
            if (currentNode->element==_element){
                Node<B>* p=currentNode->previous;
                Node<B>* n=currentNode->next;
                p->next=currentNode->next;
                n->previous=currentNode->previous;
                
                //                delete currentNode;
                return;
            }
            currentNode=currentNode->next;
        }
    }
protected:
    Node<B>* headNode=new Node<B>;
    void insert(Node<B>* beforeNode, B _element){
        Node<B>* insertNode=new Node<B>;
        Node<B>* afterNode=beforeNode->next;
        beforeNode->next=insertNode;
        insertNode->next=afterNode;
        afterNode->previous=insertNode;
        insertNode->previous=beforeNode;
        insertNode->element=_element;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    LinkList<int> a;
    a.insertAtIndex(0, 0);
    a.insertAtIndex(1, 8);
    a.insertAtIndex(2, 77);
    a.insertAtIndex(3, 1);
    a.insertAtIndex(3, 100);
    a.insertAtIndex(1, 58);
    a.printOut();
    a.removeElement(77);
    a.printOut();
    return 0;
}
