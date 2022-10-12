#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data; 
  struct node *nxt;
} Linkedlist;

void initialisation (Linkedlist **);

void insertion_sorted_order (Linkedlist **, int);
void insertion_sequential_order (Linkedlist **, int);

void recursive_insertion_sequential_order (Linkedlist **, int);
void recursive_insertion_sorted_order (Linkedlist **, int);

void reverse (Linkedlist **);
void recursive_reverse (Linkedlist *);

int count (Linkedlist *);
int recursive_count (Linkedlist *);

void display (Linkedlist *);
void recursive_display (Linkedlist *);

void deletion (Linkedlist **, int );
void recursive_deletion (Linkedlist **, int );

void split_and_display (Linkedlist *, Linkedlist **, Linkedlist **);

void merge_and_display(Linkedlist *, Linkedlist *, Linkedlist **);

void alternative_merge_and_display(Linkedlist *,Linkedlist *, Linkedlist **);

void initialisation (Linkedlist **aa_head){
  *aa_head=NULL;
}

void insertion_sorted_order(Linkedlist **aa_head, int n){
  Linkedlist *t, *prv, *cur;
  t=(Linkedlist *) malloc (sizeof(Linkedlist));
  t->data=n; 
  for(cur =*aa_head, prv=NULL; cur && n>cur->data ; cur=cur->nxt)
    prv=cur;
  t->nxt=cur;
  if (prv!=NULL)
    prv->nxt=t;
  else
    *aa_head=t;
}

void insertion_sequential_order (Linkedlist **aa_head, int n){
  Linkedlist *t, *prv, *cur;
  t=( Linkedlist *) malloc(sizeof(Linkedlist));
  t->data=n;
  for(cur=*aa_head, prv=NULL; cur ; cur=cur->nxt)
    prv=cur;
  t->nxt=cur;
  if (prv)
    prv->nxt=t;
  else
    *aa_head=t;
}

void recursive_insertion_sequential_order (Linkedlist **aa_head, int n){
  if (*aa_head==NULL){
    *aa_head =( Linkedlist *) malloc(sizeof(Linkedlist));
    (*aa_head)->data=n;
    (*aa_head)->nxt=NULL;
  }
  else
    recursive_insertion_sequential_order (&(*aa_head)->nxt, n);
}

void recursive_insertion_sorted_order (Linkedlist **aa_head , int n){
  Linkedlist *t;
  t=( Linkedlist *) malloc(sizeof(Linkedlist));
  t->data=n;
  t->nxt=NULL;
  if (*aa_head==NULL)
    *aa_head =t; 
  else if (n < (*aa_head)->data){
      t->nxt=*aa_head;
    *aa_head =t; 
  }
  else
    recursive_insertion_sorted_order (&(*aa_head)->nxt, n);
}

void reverse (Linkedlist **aa_head){
  Linkedlist *prv , *cur, *t; 
  for (cur=*aa_head, prv=NULL; cur; cur=t){
    t=cur->nxt;     
    cur->nxt=prv; prv=cur;
  }
  *aa_head=prv;
}

void recursive_reverse (Linkedlist *a_head ){
  if (a_head->nxt)
    recursive_reverse (a_head ->nxt);
  printf("\t %d", a_head->data);
}

int count (Linkedlist *a_head){
  int count=0;
  for( ; a_head; a_head = a_head->nxt)
    count++;
  return (count);
}

int recursive_count (Linkedlist * a_head){
  if (a_head == NULL)
    return 0;
  else
    return (recursive_count (a_head->nxt) + 1);
}

void display (Linkedlist *a_head){
  for( ; a_head ; a_head = a_head->nxt)
    printf("\t %d", a_head->data);
}

void recursive_display (Linkedlist *a_head){
  if (a_head){
    printf("\t %d", a_head->data);
    recursive_display (a_head->nxt);
  }
  else
    printf("\t Null ");
}

void deletion (Linkedlist **aa_head, int n){
  Linkedlist *prv, *cur;
  int found=0;
  for (cur = *aa_head, prv=NULL; cur; cur=cur->nxt){
    if (prv != NULL && n ==  cur->data){
      found=1;
      prv->nxt = cur->nxt;
      free(cur);
      return;
    }
    else if (prv == NULL && n == cur->data){
      found=1;
      *aa_head = cur->nxt;
      free(cur);
      return;
    }
    else
      prv=cur;
  }
  if (!found)
    printf ("\nERROR: Data not found.");
}

void recursive_deletion (Linkedlist **aa_head, int n){
  Linkedlist *temp=*aa_head;
    if (temp->data==n) {
     *aa_head=temp->nxt;
      free(temp);
      return;
    }
    else if (temp->nxt== NULL && temp->data!=n) {
      printf ("\nERROR: Data not found.");
      return;
    }
    else
      recursive_deletion(&(*aa_head)->nxt,n);  
}

void split_and_display (Linkedlist *a_head,Linkedlist **aa_head_odd, Linkedlist **aa_head_even){
  Linkedlist *cur;
  initialisation (aa_head_even);
  initialisation (aa_head_odd);
  for (cur = a_head; cur; cur=cur->nxt){
    if(cur->data%2==0)
      insertion_sequential_order (aa_head_even, cur->data);
    else
      insertion_sequential_order (aa_head_odd, cur->data);
  }
  display(*aa_head_even);
  display(*aa_head_odd);
}

void merge_and_display(Linkedlist *a_head1,Linkedlist *a_head2, Linkedlist **aa_head_m){
  Linkedlist *cur;
  initialisation (aa_head_m);
  for (cur=a_head1; cur ;cur=cur->nxt)
    insertion_sorted_order (aa_head_m, cur->data);
  for (cur=a_head2; cur ;cur=cur->nxt)
    insertion_sorted_order (aa_head_m, cur->data);
  display(*aa_head_m);
}

void alternative_merge_and_display(Linkedlist *a_head1, Linkedlist *a_head2, Linkedlist **aa_head_m){
  Linkedlist *cur1,*cur2;
  initialisation (aa_head_m);
  for (cur1=a_head1, cur2=a_head2; cur1 && cur2; ){
    if (cur1->data < cur2->data){
      insertion_sequential_order (aa_head_m, cur1->data);
      cur1=cur1->nxt;
    }
    else{
      insertion_sequential_order (aa_head_m, cur2->data);
      cur2=cur2->nxt;
    }
  }
  for ( ;cur1; cur1=cur1->nxt)
    insertion_sequential_order (aa_head_m, cur1->data);
  for ( ; cur2; cur2=cur2->nxt)
    insertion_sequential_order (aa_head_m, cur2->data);
  display(*aa_head_m);
}

void search (Linkedlist *a_head,int a){
  int pos=0,d=0;
  for( ; a_head; a_head = a_head->nxt){
    pos++;
    if(a_head->data==a){
      d=1;
      break;
    }
  }
  if(d==1)
    printf("Found in location %d",pos);
  else 
    printf("ERROR: Not Found");
}

int sum(Linkedlist *aa_head){
  if(aa_head==NULL)
    return 0;
  else
    return(aa_head->data + sum(aa_head->nxt));
}

int product(Linkedlist *a_head){
  if(a_head==NULL)
    return 0;
  else if(a_head->nxt==NULL)
    return a_head->data;  
  else
    return(a_head->data * product(a_head->nxt));
}


void main(){
  Linkedlist *s=NULL,*a,*b;
  initialisation (&s);
  int f=1,choice,x,y;
  while(f){
    printf("--------LIST OF CHOICES--------\n");
    printf("What would you like to do?:\n1: Insert integers in sorted order using an iterative procedure.\n2: Insert integers in sorted order using a recursive procedure.\n3: Insert integers in sequential order using an iterative procedure.\n4: Insert integers in  sequential   order using a recursive procedure.\n5: Display the content of the linked list using an iterative procedure.\n6: Display the content of the linked list using a recursive procedure.\n7: Delete a given element of a linked list.\n8: Reverse the linked list using an iterative function.\n9: Display the content of a linked list in reverse order using a recursive function.\n10: Count the number of elements in the linked list using an iterative function.\n11: Count the number of elements in the linked list using a recursive function.\n12: Split a given linked list in two linked lists containing even and odd integers.\n13: Merge the content of two  linked lists in sorted order into another linked list.\n14: Search for a given integer inside a linked list.\n15: Recursive Deletion.");
    scanf("%d",&choice);
    int n;
    Linkedlist *a,*b;
    switch(choice){

      case 1:        
        printf("Enter the value you'd like to insert: ");
        scanf("%d",&n);
        insertion_sorted_order(&s,n);
        break;
        
      case 2:        
        printf("Enter the value you'd like to insert: ");
        scanf("%d",&n);
        recursive_insertion_sorted_order(&s,n);
        break;

      case 3:        
        printf("Enter the value you'd like to insert: ");
        scanf("%d",&n);
        insertion_sequential_order(&s,n);
        break;

      case 4:        
        printf("Enter the value you'd like to insert: ");
        scanf("%d",&n);
        recursive_insertion_sequential_order(&s,n);
        break;

      case 5:
        display(s);
        break;

      case 6:
        recursive_display(s);
        break;

      case 7:       
        printf("Enter the element you'd like to delete: ");
        scanf("%d",&n);
        deletion(&s,n);
        break;

      case 8:
        reverse(&s);
        break;

      case 9:
        recursive_reverse(s);
        break;

      case 10:
        printf("The number of elements in the linked list are: %d",count(s));
        break;

      case 11:
        printf("The number of elements in the linked list are: %d",recursive_count(s));
        break;

      case 12:
        initialisation(&a);
        initialisation(&b);
        split_and_display(s,&a,&b);
        break;


      case 13:
        merge_and_display(a,b,&s);
        break;

      case 14:
        printf("Enter the element to search: ");
        scanf("%d",&n);
        search(s,n);
        break;

      case 15:       
        printf("Enter the element you'd like to delete: ");
        scanf("%d",&n);
        recursive_deletion(&s,n);
        break;
      case 16: 
        x=sum(s);
        printf("Sum of all nodes are %d",x);
        break;
      case 17:        
        y=product(s);        
        printf("Product of all nodes are %d",y);
        break;
      default:
        printf("ERROR: Wrong Input");
        break;
    }

    printf("\nDo you like to choose again? 0: NO  1: YES\t");
    scanf("%d",&f);

  }
}