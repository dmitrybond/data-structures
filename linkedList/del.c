#include <stdio.h>
#include <string.h>

int main(){
    int a1 = 4;
    int a2 = 4;

    int ans = memcmp(&a1, &a2, sizeof(int));

    printf("ans = %d\n", ans);
}
