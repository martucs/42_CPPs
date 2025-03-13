#include <stdio.h>

int	box1 = 1;
int	box2 = 2;
int	*p = &box1;
int	*gptr = &box2;


void	passByPtrRef(int *&ptrRef)
{
	*ptrRef = 5;
	ptrRef = gptr;
	*ptrRef = 6;
}

void	passByPtr(int *ptr)
{
	*ptr = 3;
	ptr = gptr;
	*ptr = 4;
}

int	main()
{
	passByPtr(p);
//	passByPtrRef(p);
	if (p == &box1)
		printf("p is pointing to box1\n");
	else if (p == &box2)
		printf("p is pointing to box2\n");
	if (gptr == &box1)
		printf("gptr is pointing to box1\n");
	else if (gptr == &box2)
		printf("p is pointing to box2\n");
	printf("box1 = %d\nbox2 = %d\n", box1, box2);
	return (0);

}
