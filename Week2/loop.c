#include <stdio.h>

int main(){

/*While loop*/
int condition = 1;

while (condition <= 5) {
    printf("We are in a loop, again!\n");
    condition = condition + 1;
}

printf("\n");

/*For loop*/
for (int i = 0; i <= 5; i = i + 1) {
    printf("We are in the %dth iteration of a for loop.\n", i);
}

return (condition);
}
