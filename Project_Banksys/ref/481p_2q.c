#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *pi;
	double *pd;
	
	pi = (int *)malloc(sizeof(int));
	if(pi == NULL)
	{
		printf("#���� �޸𸮰� �����մϴ�\n");
		exit(1);
	}
	//pi = (int *)(pd);
	pd = (double *) malloc(sizeof(double));
	
	*pi = 10;
	*pd = 3.4l;
	
	
	printf("���������� ��� : %d \n", *pi );
	printf("�Ǽ������� ��� : %lf \n", *pd );
	
	free(pi);
	free(pd);
	
	return 0;
	
}
