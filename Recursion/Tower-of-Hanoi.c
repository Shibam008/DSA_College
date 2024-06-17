#include<stdio.h>
#include<math.h>

void toh(int n, char src, char help, char dest) {
   // base case
   if(n == 1) {
      printf("Move disk %d -> from rod %c to rod %c\n", n, src, dest);
      return;
   }
   toh(n-1, src, dest, help);  // first we will go src to help, using dest as helper.
   printf("Move disk %d -> from rod %c to rod %c\n", n, src, dest);
   toh(n-1, help, src, dest);  // now we are going from help to dest, using src as helper.
}

int main() {
   int n;
   char src = 'A', help = 'B', dest = 'C';
   printf("\nFor how many disk you want to solve this game ? : ");
   scanf("%d", &n);

   int moves = pow(2,n)-1;
   printf("\nMinimum number of moves to solve this game : %d\n", moves);

   toh(n, src, help, dest);
   return 0;
}