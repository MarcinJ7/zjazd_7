#include <stdio.h>
#pragma warning(disable: 4996)

void zero_arr(double tab[], int size)
{
	for (int i = 0; i < size; i++) //< size; i++)
	{
		tab[i] = 0;
	}
}

void print_arr(double tab[], int size)
{
	for (int i = 0; i < size; i++) //< size; i++)
	{
		printf("\n%d element: %lf", i, tab[i]);
	}
}

void calc_percentage(double tab[], int all_chars, int size)
{
	for (int i = 0; i < size; i++) //< size; i++)
	{
		tab[i] = (tab[i] / all_chars) * 100;
	}
}

void plot_hist(double tab[], int size)
{
	printf("\nHistogram - prezentacja udzialu poszczegolnych liczb:");
	for (int i = 0; i < size; i++) //< size; i++)
	{
		printf("\n%d. ", i);
		for (int j = 1; j < tab[i]; j++)
		{
			printf("#");
		}
	}
}

int main(int argc, char* argv[])
{
	int all_chars = 0;
	double histogram[10];
	FILE* input_file;
	FILE* output_file;

	char* file_name_in = "daneWej.txt";
	input_file = fopen(file_name_in, "r");
	output_file = fopen("daneWyj.txt", "w");
	int arr_size = (sizeof(histogram) / sizeof(double));
	
	zero_arr(histogram, arr_size);
	
	// czy wyzerowana
	printf("Czy wyzerowana?");
	print_arr(histogram, arr_size);

	// odczyt
	char single_char;

	while ((single_char = fgetc(input_file)) != EOF)
	{
		if (single_char >= '0' && single_char <= '9')
		{
			histogram[single_char - '0']++;
			all_chars++;
		}
		
	}

	printf("\n Pierwsze uzupelnienie");
	print_arr(histogram, arr_size);
	printf("\nLacznie znakow w pliku %d.", all_chars);

	calc_percentage(histogram, all_chars, arr_size);
	printf("\n Zawartosc procentowa");
	print_arr(histogram, arr_size);

	printf("\n");
	// plot hist
	plot_hist(histogram, (sizeof(histogram) / sizeof(double)));


	// Zamykamy pliki
	fclose(input_file);
	fclose(output_file);

	return 0;
} 
