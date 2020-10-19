// playQueue.c
// Intersession term of 2020
// Duncan Campbell
#include <stdio.h>
#include <stdlib.h>
#include "Queue.c"
#define ENQUEUE 1
#define DEQUEUE 0
#define LIST 2
#define PEEK 3
int main(int argc, char * * argv)
{
  int iChoice;
  int iNRead;
  pPtQueue queue = (pPtQueue)mallocQueue();

  /* Processing loop */
  printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case ENQUEUE: ;
        int x;
        int y;
        printf("Point value to add:"); // Obviously you need to read the x and y values
        // Read the element, add it to the queue
        scanf("%d %d", &x, &y);
        printf("%d %d\n", x, y);
        Point2D* point = createPoint2D(x,y);
        pPtLink link = mallocLink();
        link -> payload = point;
        enqueue(queue, link);
        printf("Enqueue Successful\n");
      break;
      case DEQUEUE: ;
      // dequeue the Point2D and print it out.
          Point2D* temp = queue -> head -> payload;
          printf("%lf %lf\n", getXPoint2D(temp), getYPoint2D(temp));
          dequeue(queue);
          printf("Dequeue Successful\n");
      break;
      case LIST: ;
        // Print out the stack elements, 
        reportQueue(queue);
      break;
      case PEEK: ;
        // Print out the next value to be dequeue.
        peekQueue(queue);
      break;
      default: 
        return 0;
    }
    printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
  freeQueue(queue);
  return EXIT_SUCCESS;
}
