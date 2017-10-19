#include <iostream>
using namespace std;
struct node
{
  int num;
  node *next;
}
bool isEmpty(node *head);
char menu();
void insertAsFirst(node *head, node *last, int number);
void insert(node *head, node *last, int number);
void remove(node *head, node *last);
void display(node *current);
bool isEmpty(node *head)
{
  if(head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}
char menu()
{
  char choice;
  cout << "Menu:"
  cout << "1. Add an item:\n";
  cout << "2. Remove an item.\n";
  cout << "3. Show the list.\n";
  cout << "4. exit";
  cin >> choice;
  return choice;
}
void insertAsFirst(node *head, node *last, int number)
{
  node *temp = new node;
  temp->num = number;
  temp->next = NULL;
  head = temp;
  last = temp;
}
void insert(node *head, node *last, int number)
{
  if(isEmpty(head)==true)
  {
    insertAsFirst(head, last, number)
  }
  else
  {
    node *temp = new node;
    temp->num = number;
    temp->next = NULL;
    last->next = temp;
    last = temp;
  }
}
void remove(node *head, node *last)
{
  if(isEmpty(head))
  {
    cout << "The list is already Empty";
  }
  else if (head == last)
  {
    delete head;
    head = NULL;
    last = NULL;
  }
  else
  {
  node *temp = head;
  head = head->next;
  delete temp;
  }
}
void display(node *current)
{
  if(isEmpty())
  {
    cout << "The list is empty";
  }
  else
  {
    cout << "The list contains: \n";
      while(current!=NULL)
      {
        cout << current->num << end1;
        current = current->next;
      }
  }
}
int main()
{
  node *head = NULL;
  node *last = NULL;
  char choice;
  int number;
  do
  {
    choice = menu();
    switch(choice)
    {
      case '1': cout << "Please enter a number:";
                cin >> number;
                insert(head,last,number);
                break;
      case '2': remove(head,last);
                break;
      case '3': display(head);
                break;
      default: cout << "System exit";
    }
  }(while choice!='4')
  return 0;
}
