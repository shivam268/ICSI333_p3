/* -------------------------------- */
/*|      FIRST GROUP PROJECT       |*/
/* -------------------------------- */

/* ------------------------------- */
/*|            MEMBERS            |*/
/*|---------Parikh Shivam---------|*/
/*|-------Ukpere Stephanie--------|*/
/*|--------Class: CSI333----------|*/
/*|----Lab: Wednesday 9:20 AM-----|*/
/*|----Programming Assignment 3---|*/
/* ------------------------------- */

/* --------------------------------------------- */
/*| Beginning of every method contains the name |*/
/*| of the group  member who coded that method. |*/
/*| If there are two names, both members worked |*/
/*| on that method                              |*/
/* --------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 4;

/* ---------------------------------------------- */
/*| Define all the required global variable here |*/
/* ---------------------------------------------- */
char command[4];

int coeff = 0;
int exponent = 0;

int startRange = 0;
int endRange = 0;

int dexInput = 0;

int der1 = 0;
int der2 = 0;

int val = 0;

int createOne = 0;

/* Struct for each node in the linked list. */
struct node {
  int co;
  int ex;
  struct node *next;
} NODE, *PNODE;

struct node *head, *tail, *curr;

void adc(int coe, int exp);
void pvp(int valOfX);
int myExp(int base, int exp);
void prp();
void dex(int expToDelete);
void der(int e1, int e2);
void prd();
void prc(int findCoe);
void plc();
void psc();

/*----------------------------------*/
/*|       Main method starts       |*/
/*|     Author: Parikh, Shivam     |*/
/*----------------------------------*/

int main(void) {

  int exp, valX = 0;

  //---While Loop Starts

  while(!strcmp(command, "end") == 0){

    scanf("%s", command);

    if(strcmp(command, "adc") == 0){
      printf("adc was entered \n");
      fflush(stdout);

      scanf("%d %d", &coeff, &exponent);
      printf("%d\n", coeff);
      fflush(stdout);

      printf("%d\n", exponent);
      fflush(stdout);

      adc(coeff, exponent);
    }
    else if(strcmp(command, "dex") == 0){
      printf("dex was entered \n");
      fflush(stdout);

      scanf("%d", &dexInput);

      dex(dexInput);
    }
    else if(strcmp(command, "der") == 0){
      printf("der was entered \n");
      fflush(stdout);

      scanf("%d %d", &der1, &der2);

      der(der1, der2);
    }
    else if(strcmp(command, "prp") == 0){
      printf("prp was entered \n");
      fflush(stdout);

      prp();
    }
    else if(strcmp(command, "pvp") == 0){
      printf("pvp was entered \n");
      fflush(stdout);

      scanf("%d", &valX);
      pvp(valX);
    }
    else if(strcmp(command, "prd") == 0){
      printf("prd was entered \n");
      fflush(stdout);

      prd();
    }
    else if(strcmp(command, "prc") == 0){
      printf("prc was entered \n");
      fflush(stdout);

      scanf("%d", &exp);

      prc(exp);
    }
    else if(strcmp(command, "plc") == 0){
      printf("plc was entered \n");
      fflush(stdout);

      plc();
    }
    else if(strcmp(command, "psc") == 0){
      printf("psc was entered \n");
      fflush(stdout);

      psc();
    }
    else if(strcmp(command, "num") == 0){
      coeff = getchar();

      printf("%d", coeff);
      fflush(stdout);

    }

  } //---While Loop Ends


  return 0;
}
/* ------------------------------ */
/*|       Main method ends       |*/
/* ------------------------------ */


/* ------------------------------ */
/*|       adc method starts      |*/
/*|     Author: Parikh, Shivam   |*/
/*|    Author: Stephanie Ukpere  |*/
/* ------------------------------ */
void adc(int coe, int exp){

  /* If list is currently empty, adc creates first node. */
  if(head == NULL){

    /* If malloc returns null, print error message. Stop. */
    if((curr =  malloc(sizeof(struct node))) == NULL){
      printf("Node allocation failed. \n");
      fflush(stdout);

      exit(1);
    }

    /* Save coefficient and exponent values in curr node. */
    curr->co = coe;
    curr->ex = exp;

    /* First node is head and tail of list. */
    head = curr;
    tail = curr;
    tail->next = NULL;

    curr = curr->next;
  }
  else{

    struct node *equalExpCheck, *p1, *p2;
    struct node *equalExpCheckPrev;

    equalExpCheck = head;
    equalExpCheckPrev = head;

    /* While equalExpCheck is not null, if exponents are equal, add coefficients */
    while(((equalExpCheck==NULL)!=1)){

      if(equalExpCheck->ex == exp){
        equalExpCheck->co += coe;
        createOne = 1;
      }

      else{
      }

      if(equalExpCheck->co == 0){
        printf("equalExpCheckPrev-> co: %d\n", equalExpCheckPrev->co);
        fflush(stdout);

        printf("equalExpCheck-> co: %d\n", equalExpCheck->co);
        fflush(stdout);

        printf("Head-> co: %d\n", head->co);
        fflush(stdout);

        if(equalExpCheck == head){

          if(head->next == NULL){
            printf("head->next is NULL \n");
            fflush(stdout);

            head = NULL;
          }

          else{

            printf("equalExpCheck is Head \n");

            head = head->next;
            equalExpCheck = equalExpCheck->next;
          }

        }

        else{
          printf("equalExpCheck is not Head \n");
          equalExpCheckPrev->next = equalExpCheck->next;
        }

      }

      else{}

      equalExpCheckPrev = equalExpCheck;
      equalExpCheck = equalExpCheck->next;


    }

    /* While ends */
    if(createOne == 0){
      curr = p1 = p2 =  malloc(sizeof(struct node));
      if ( (curr == NULL) || (p1 == NULL) || (p2 == NULL) ) {
        printf("Allocation failed.\n");
        exit(1);
      }
      printf("creating it now\n");

      curr->co = coe;
      curr->ex = exp;

      /* Pointer used to reference head while ordering nodes */
      p1 = head;

      /* If curr exponent is greater that p1 exponent, curr becomes head */
      if(curr->ex > p1->ex){
        curr->next = p1;
        p1  = curr;
        head = curr;
        head->next = curr->next;
      }

      /* Else if curr exponent is greater than tail */
      else{
        if(curr->ex > tail->ex){

          /* Move p1 to point to node in front of curr's new location and add curr after p1 */
          while( (p1->next)->ex > curr->ex ){
            p1 = p1->next;
          }
          p2 = p1->next;
          p1->next = curr;
          curr->next = p2;
        }

        /* if curr is not greater than tail, curr is last in the list */
        else{
          tail->next = curr;

          tail = curr;
          tail->next = NULL;

          curr = curr->next;
        }
     }
    }
    else{
    }


  } /// Else Ends

  createOne = 0;
}
/* ------------------------------ */
/*|          adc ends            |*/
/* ------------------------------ */


/* ------------------------------ */
/*|          pvp starts          |*/
/*|  @author Ukpere Stephanie    |*/
/* ------------------------------ */

/* ---------------------------------------- */
/*| pvp takes the value of X as an input,  |*/
/*| and runs the myExp to do the power     |*/
/*| functionality and stores them in val   |*/
/* ---------------------------------------- */

void pvp(int valofX){

  int val = 0;
  struct node *temp;

  temp = head;

  /* While temp is not null */
  while(temp != NULL){

    /* Multiply temp's coefficient by the valofX to the power of temp's exponent. */
    val += (temp->co) * myExp(valofX, temp->ex);

    /* temp points to next node */
    temp = temp->next;

  }

  printf("%d\n", val);
  fflush(stdout);
}
/* ------------------------------ */
/*|           pvp ends           |*/
/* ------------------------------ */


/* ------------------------------ */
/*|         myExp starts         |*/
/*|  @author Ukpere Stephanie    |*/
/* ------------------------------ */

/* ----------------------------------------- */
/*| myExp takes base and exp as variables.  |*/
/*| If the exp is 0, it returns 1.          |*/
/*| If the base is 1, it returns 1. Else it |*/
/*| uses recursion to return the raised to  |*/
/*| the power value                         |*/
/* ----------------------------------------- */

int myExp(int base, int exp){

  if(exp == 0){
    return 1;
  }
  else if (base == 1)
    return 1;
  else
    return base * myExp(base, exp - 1);
}
/* ------------------------------ */
/*|          myExp ends          |*/
/* ------------------------------ */


/* ------------------------------ */
/*|         prp starts           |*/
/*|    @author Parikh Shivam     |*/
/* ------------------------------ */

/* ------------------------------------------ */
/*| This will print the total linked list    |*/
/*| with the sign (+ or -) for coefficient   |*/
/*| and prints the list in polynomial format |*/
/* ------------------------------------------ */

void prp(){
  struct node *printPointer;

  printPointer = head;

  if(printPointer == NULL) {
    printf("0x^0\n");
    fflush(stdout);

  }

  while((printPointer == NULL)!=1){

    // if the coefficient is positive then it will not print + sign by default
    // so we have to hard code it

    if(printPointer->co > 0){
      printf(" +%d", printPointer->co);
      fflush(stdout);
      printf("x^");
      fflush(stdout);
      printf("%d", printPointer->ex);
      fflush(stdout);

    }

    // else it's negative then printf function will print the - sign so we don't need to hard code it
    else{
      printf(" %d", printPointer->co);
      fflush(stdout);

      printf("x^");
      fflush(stdout);

      printf("%d", printPointer->ex);
      fflush(stdout);

    }


    printPointer = printPointer->next;

  }

  printf("\n");
  fflush(stdout);

}
/* ------------------------------ */
/*|           prp ends           |*/
/* ------------------------------ */


/* ------------------------------ */
/*|          dex starts          |*/
/*|     @author Parikh Shivam    |*/
/* ------------------------------ */

/* -------------------------------------- */
/*| This function deletes if the given   |*/
/*| exponent is matches to any exponent  |*/
/*| of the polonomials.                  |*/
/* -------------------------------------- */

void dex (int expToDelete){
  struct node *dexPrev, *dexCurr;

  dexPrev = head;
  dexCurr = head;

  // While loop will run until the end and checks if exponent is matched to any polonomial
  // if it is then checks if that node is head then head
  // will point to the 2nd node, if it's not head then it will make dexPrev to one over
  // else the function will leave the linked list untouched

  while((dexCurr == NULL) !=1){
    if(expToDelete == dexCurr->ex){
      if(dexCurr == head){
        head = dexCurr->next;
      }
      else{
      dexPrev->next = dexCurr->next;
      }
    }
    else{
    }
    dexPrev = dexCurr;
    dexCurr = dexCurr->next;
  }

}
/* ------------------------------ */
/*|           dex ends           |*/
/* ------------------------------ */


/* ------------------------------ */
/*|          der starts          |*/
/*|   @author Ukpere Stephanie   |*/
/* ------------------------------ */

/* -------------------------------------- */
/*| This method will run the while loop  |*/
/*| and check if the exponent is in the  |*/
/*| given range. if it is then it will   |*/
/*| delete that node.-- It uses the dex  |*/
/*| method to delete that node           |*/
/* -------------------------------------- */
void der (int e1, int e2){

  int range = e2 - e1 + 1;
  int i = 0;

  // while loop will use dex method to delete the node

  while (range > 0){
    dex(e2 - i);
    i++;
    range--;
  }

}
/* ------------------------------ */
/*|           der ends           |*/
/* ------------------------------ */


/* ------------------------------ */
/*|          prd starts          |*/
/*|    @author Parikh Shivam     |*/
/* ------------------------------ */

/* ------------------------------------ */
/*| This function prints the largest   |*/
/*| exponent.                          |*/
/*| while loops runs until the pointer |*/
/*| reaches to NULL and if the stored  |*/
/*| prdDegree is less then the current |*/
/*| node's exponent. then it stores    |*/
/*| the higher value into prdDegree.   |*/
/*| else do nothing                    |*/
/* ------------------------------------ */

void prd(){

  int prdDegree = 0;
  struct node *prdCurr;
  prdCurr = head;

  while((prdCurr == NULL) !=1){
    if(prdCurr->ex > prdDegree){ // if the pointed node's exponent is greater than stored degree
      prdDegree = prdCurr->ex; // then change the value of the stored degree to that exponent
    }
    else{
    }
    prdCurr = prdCurr->next; // pointer needs to point to next one inorder to prevent infinite loop
  }

  printf("The Largest exponent: %d\n", prdDegree); // prints the highest exponent after while loop ends
  fflush(stdout);

}

/* ------------------------------ */
/*|         prd  ends            |*/
/* ------------------------------ */


/* ------------------------------ */
/*|          prc starts          |*/
/*|    @author Parikh Shivam     |*/
/* ------------------------------ */

/* ---------------------------------------------------- */
/*| This method prints the coefficient of the given    |*/
/*| exponent method takes exponent as a parameter      |*/
/*| and uses pointer to check for the matched exponent |*/
/*| if it reaches to the exponent it will print the    |*/
/*| coefficient of that node                           |*/
/* ---------------------------------------------------- */

void prc(int findCoe){
  int coeOfExp = 0;
  struct node *prcCurr;
  prcCurr = head;

  while((prcCurr == NULL) !=1){
    if(prcCurr->ex == findCoe){  // if the exponen of the current node matches with the parameter
      coeOfExp = prcCurr->co;    // then store the coefficient of that node
    }
    else{
    }
    prcCurr = prcCurr->next;  // pointer will point to next next each time while runs
  }

  printf("The Coefficient of the given exponent: %d\n", coeOfExp); // print the coefficient
  fflush(stdout);

}

/* ------------------------------ */
/*|         prc  ends            |*/
/* ------------------------------ */


/* ------------------------------ */
/*|          plc starts          |*/
/*|    @author Parikh Shivam     |*/
/* ------------------------------ */

/* --------------------------------------------------- */
/*| This function prints the largest coefficient of   |*/
/*| them all.  basically the while loop runs through  |*/
/*| the linked list and stores the coefficcient value |*/
/*| of the head node just to compare with rest node's |*/
/*| coefficients.                                     |*/
/* --------------------------------------------------- */

void plc(){
  int largestCoe = 0;
  struct node *plcCurr;
  plcCurr = head;

  while((plcCurr == NULL) !=1){
    if(plcCurr->co > largestCoe){  // if the current node's coefficient is greater than store one
      largestCoe = plcCurr->co;  // then over write the store coefficient by the new coefficient
    }
    else{
    }
    plcCurr = plcCurr->next;  // pointer will point to next node
  }

  printf("Largest Coefficient: %d\n", largestCoe); // prints the largest coefficient
  fflush(stdout);

}

/* ------------------------------ */
/*|         plc  ends            |*/
/* ------------------------------ */


/* ------------------------------- */
/*|           psc starts          |*/
/*|  @author Ukpere Stephanie     |*/
/* ------------------------------- */

/* --------------------------------------------------------------------- */
/*| This function will do the reverse job of the previous function      |*/
/*| This function will print the smallest coefficient of the polynomial |*/
/* --------------------------------------------------------------------- */
void psc(){
  int smallestCoe = 0;
  struct node *pscCurr;

  pscCurr = head;

  if(pscCurr == NULL){                                     // if there is no node then print 0
    printf("Smallest Coefficient: %d\n", smallestCoe);
  }
  else{
    /*
      else store the head coefficient value
      and then compare that with rest of them and if it finds smaller value then
      store small coefficient it will store the current coefficient as a smallest coefficient
    */

    smallestCoe = pscCurr->co;
    while((pscCurr == NULL) !=1){
      if(pscCurr->co < smallestCoe){
        smallestCoe = pscCurr->co;
      }
      else{
      }
      pscCurr = pscCurr->next;     // pointer will point to next node
    }
  }
  printf("Smallest Coefficient: %d\n", smallestCoe);  // prints the smallest coefficient
  fflush(stdout);

}
/* ------------------------------ */
/*|         psc  ends            |*/
/* ------------------------------ */
