#include <stdio.h>

int main()
{
	FILE *ptr;
	FILE *ptrr;

	ptr = fopen("Untitled.bmp", "rb");
	ptrr = fopen("copy.bmp", "wb");

	if(ptr == NULL)
	{
		printf("file does not exist");
	}
	else
	{
		fseek(ptr, 0L, SEEK_END);
		int i = ftell(ptr);
		printf("%d", i);
		unsigned char arr[i];

		fread(&arr, sizeof(arr), 1, ptr);
		fwrite(&arr, sizeof(arr), 1, ptrr);
	}
	return 0;
}
