#include <stdio.h>
void foo(int index, int a) {

    char *items[] = {"boat", "car", "truck", "train"};

    printf("You selected %s\n", items[index]);  //@violation

    if(index >= 0 && index <= 5 )
    {
        printf("You selected %s\n", items[index]);  //@violation
    }


    if(index >= 0 && index <= 3 )
        {
            printf("You selected %s\n", items[index]);
        }

}
int main (int argc, char **argv) {
    foo(4);
    return 0;
}
