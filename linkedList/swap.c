#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void swap(void *vp1, void *vp2, int elemSize)
{
	void *buffer = malloc(elemSize);
	memcpy(buffer, vp1, elemSize);
	memcpy(vp1, vp2, elemSize);
	memcpy(vp2, buffer, elemSize);
	free(buffer);
}

int main()
{
	int a = 3;
	int b = 4;

	swap(&a, &b, sizeof(int));
	printf("a,b = 3,4 -> a,b = %d,%d\n", a, b);

	return 0;
}
