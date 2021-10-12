/*
Intersection Point in Y Shapped Linked Lists 
Medium Accuracy: 49.55% Submissions: 78119 Points: 4
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

Y ShapedLinked List
Above diagram shows an example with two linked list having 15 as intersection point.

Example 1:

Input:
LinkList1 = {10,20,5,10}
LinkList2 = {30,40,50,5,10}
Output: 5
Explanation:The point of intersection of
two linked list is 5, means both of them
get linked (intersects) with each other
at node whose value is 5.
Your Task:
The task is to complete the function intersetPoint() which finds the point of intersection of two linked list. The function should return data value of a node where two linked lists merge. If linked list do not merge at any point, then it should return -1.

Challenge : Try to solve the problem without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)
*/
//solution:
// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int getCount(Node* head);
int getIntersection(int d,Node* head1,Node* head2);
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Hereint 
    int c1=getCount(head1);
    int c2=getCount(head2);
    int d;
    if(c1>c2){
        d=c1-c2;
        return getIntersection(d,head1,head2);
    }else{
        d=c2-c1;
        return getIntersection(d,head2,head1);
    }
}

int getIntersection(int d,Node* head1,Node* head2){
    Node* curr1=head1;Node* curr2=head2;
    for(int i=0;i<d;i++){
        if(curr1==NULL){
            return -1;
        }
        curr1=curr1->next;
    }
    while(curr1!=NULL && curr2!=NULL){
        if(curr1==curr2){
            return curr1->data;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}
int getCount(Node* head){
    Node* curr =head;
    int count=0;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
    return count;
}