#include <stdio.h> 
int main(void) { int x, y; x = 10; y = 5; /* 第7行 */ 
    y = x + y; /*第8行*/ 
    x = x*y; /*第9行*/
    printf("%d %d\n", x, y); 
    return 0; 
}