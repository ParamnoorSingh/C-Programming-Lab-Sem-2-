#include<stdio.h>
#include<stdlib.h>
int stack[50], top=-1;
void isEmpty(){
   if(top==-1){
    printf("Stack Underflow\n");
    return;
  }
}
void isFull(){
   if(top==49){
        printf("Stack Overflow\n");
        return;
    }
}
void Push()
{
    if(top==49){
        printf("Stack Overflow\n");
    }
    else{
    int val;
  printf("Enter Element to push: ");
  scanf("%d", &val);
     top++;
     stack[top]=val;
     printf("Element Pushed successfully!!!\n");
    }
}

void Pop()
{
  if(top==-1){
    printf("Stack Underflow\n");
  }
  else{
    top--;
    printf("Element %d Removed Successfully!!!\n", stack[top+1]);
  }
}

void Peek()
{
 if(top==-1)
  {
    printf("Stack Underflow!!!\n");
  }
  else{
    printf("%d is the topmost element\n", stack[top]);
  }
}

void Show()
{
 if(top==-1)
  {
    printf("Stack Underflow!!!\n");
  }
  else{
    printf("Stack Elements are: \n");
   for(int i=top;i>=0;i--)
   {
    printf("%d\n", stack[i]);
   }
  }
}


int main()
{
    int choice;
    while (1) {
        system("cls");
        printf("1. Push.\n");
        printf("2. Pop.\n");
        printf("3. Peek.\n");
        printf("4. Show.\n");
        printf("5. Exit.\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Show();
                break;
            case 5:
                exit(0);
                return 0;
            default:
                printf("Invalid Choice...\n");
        }
        system("pause"); // press any key to continue
    
}