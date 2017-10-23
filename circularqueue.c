

#include<stdio.h>
#include<limits.h>

int front=-1;
int rear=-1;
void enqueue(int * arr,int b,int size){
int nexrear=(rear%(size-1));
if(rear!=size-1)
nexrear=nexrear+1;
if(nexrear==front){
    printf("queue is full");
    return;
}
    else{
        arr[nexrear]=b;
        rear=nexrear;
        if(front==-1)
        front=0;
    }
}


void print(int *arr,int size){

    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
   printf("\n updated queue is :");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }

}

int IsEmpty(){
    if(front ==-1 || rear==-1)
    return 1;
    else return 0;
}
int isfull(int size){
    int nexrear=(rear%(size-1));
    if(rear!=size-1)
    nexrear=nexrear+1;
    if(nexrear==front){
    
        return 1;
    }
else return 0;
}

void dequeue(int *arr,int size){

printf("\n the dequeued element is %d",arr[front]);
    arr[front]=INT_MIN;
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        int tempfront=front;
        front=(front%(size-1));
        if(tempfront!=size-1)
        front=front+1;
    }
}



int main(){


    int arr[4];
    for(int i=0;i<4;i++){
        arr[i]=INT_MIN;
    }
    printf("press 0 to enqueue\n");
    printf("press 1 to dequeue\n");
    printf("press 2 to check if queue is empty\n");
    printf("press 3 to check if queue is full\n");
    printf("press ctrl+z to exit");
while(1){
    int a;
    printf("\n Enter the choice");
    scanf("%d",&a);

    switch(a)
    {
        case 0:

        if(isfull(4)){
        printf("the queue is full");
        break;
        }
        else{
            printf("enter the element to enqueue");
            int b;scanf("%d",&b);
        enqueue(arr,b,4);
        print(arr,4);
        }
        break;


        case 1:
 
        if(IsEmpty())
        printf("the queue is empty");
        else{
            dequeue(arr,4);
            print(arr,4);
        }
          break;

          case 2:
          if(IsEmpty())
          printf("the queue is empty");
          else
          printf("the queue is not empty");
          break;

          case 3:
          if(isfull(4))
          printf("the queue is full");
          else
          printf("the queue is not full");
          break;
        
          default:
          printf("enter the valid choice\n");
          break;
    }
}
}

