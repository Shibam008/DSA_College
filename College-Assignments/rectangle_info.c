#include<stdio.h>

typedef struct rectangle {
    int length;
    int bredth;
    int area;
    int perimeter;
}rect;

int main() {
    rect r1;
    printf("Enter length of a rectangle : ");
    scanf("%d", &r1.length);
    printf("Enter bredth of a rectangle : ");
    scanf("%d", &r1.bredth);

    r1.area = r1.length * r1.bredth;
    r1.perimeter = 2 * (r1.length + r1.bredth);

    printf("Area of the rectangle : %d\n", r1.area);
    printf("Perimeter of rectangle : %d\n", r1.perimeter);
    return 0;
}