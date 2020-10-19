// playStack.c
// Intersession term of 2020
// Duncan Campbell
#include <stdio.h>
#include <stdlib.h>
#include "Stack.c"
#define PUSH 1
#define POP 0
#define LIST 2
#define PEEK 3
int main(int argc, char* argv[])
{
  int iChoice;
  int iNRead;
  pPtStack stack = (pPtStack)mallocStack();

  /* Processing loop */
  printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case PUSH: ;

        int x;
        int y;
        printf("Point value to add:"); // Obviously you need to read the x and y values
        // Read the element, add it to the stack
        scanf("%d %d", &x, &y);
        printf("%d %d\n", x, y);
        Point2D* point = createPoint2D(x,y);
        pPtLink link = mallocLink();
        link -> payload = point;
        pushStack(stack, link);
        printf("Push Successful\n");
      break;
      case POP: ;
      // Pop the Point2D and print it out.
        Point2D* temp = stack -> head -> payload;
        printf("%lf %lf\n", getXPoint2D(temp), getYPoint2D(temp));
        popStack(stack);
      break;
      case LIST: ;
        // Print out the stack elements
        reportStack(stack);
      break;
      case PEEK: ;
        // Print out the next value to be popped.
        peekStack(stack);
      break;
      default: 
        return 0;
    }
    printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }

  freeStack(stack);
  return EXIT_SUCCESS;
}
