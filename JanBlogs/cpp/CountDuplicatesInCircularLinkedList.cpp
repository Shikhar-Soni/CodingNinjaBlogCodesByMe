#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Node{
   public:
   int val;
   Node *next;
   Node(int x){
       val = x;
       next = NULL;
   }
};
int main(){
   
  // let us store all the content in the below vector into the circular linked list
  vector<int> data = {10, 1, 1, 7, 5, 5, 5};
  Node *head = new Node(data[0]);
  Node *temp = head;
  
  for(int i = 1; i < data.size(); i++){
      temp->next = new Node(data[i]);
      temp = temp->next;
  }
  temp->next = head; // the end element points back to the head, making it a circular linked list
  
  
  //from here on we have the logic for counting the duplicates
  int duplicates = 0;
  unordered_set<int> s;
  Node *loop_var = head;
  do{
      if(s.find(loop_var->val) != s.end()){
          // if a previous occurence is found
          duplicates += 1;
      }
      else{
          s.insert(loop_var->val);
      }
      loop_var = loop_var->next;
  }
  while(loop_var != head);
  
  // print the total duplicates
  // [10, 1, 1 <-, 7, 5, 5 <-, 5 <-]
  // I have put arrows next to the duplicates and we expect an output of 3 for the given input
  cout << duplicates << endl;
}
