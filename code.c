#include <stdio.h>
#include <math.h>
#include <locale.h>

void revers(char* str, int in, int ik)
{
	while (in < ik)
	{
		char temp = *(str + in);
		*(str + in) = *(str + ik);
		*(str + ik) = temp;
		in++; ik--;
	}
}

void comboRevers(char* str, int jn1, int jk1, int jn2, int jk2)
{
	if (*(str + jk2) == '\0')
	{
		revers(str, jn1, jk2 - 1);
		revers(str, jn1, jn1 + (jk2 - jn2) - 1);
		revers(str, jk2 - (jk1 - jn1), jk2 - 1);
		revers(str, jn1 + (jk2 - jn2), jk2 - (jk1 - jn1) - 1);
	}
	else
	{
		revers(str, jn1, jk2 - 1);
		revers(str, jn1, jn1 + (jk2 - jn2) - 1);
		revers(str, jk2 - (jk1 - jn1), jk2 - 1);
		revers(str, jn1 + (jk2 - jn2), jk2 - (jk1 - jn1) - 1);
	}
}

void lengthWord(char* str, int jn1, int* jk1)
{
	int i = jn1;
	while (*(str + i) != ' ') i++;
	*jk1 = i;
}

int main(int argc, char* argv[])
{
	int j = 0, j1 = 0, jn1, jn2, jk1, jk2;
	char iter = 0;
	for (int i = 1; i < argc; i++)
	{
		puts(argv[i]);
	}
	for (int i = 1; i < argc; i++)
	{
		while (*(argv[i] + j))
		{
			while (*(argv[i] + j) == ' ') j++;
			jn1 = j;
			while (*(argv[i] + j) != ' ' && *(argv[i] + j)) j++;
			jk1 = j;
			if (*(argv[i] + j)) j1 = j + 1;
			else break;
			iter = 0;
			while (j1 > jk1)
			{
				if (j1 == j + 1 && iter == 0)
				{  
					while (*(argv[i] + j1) != '\0') j1++;
					jk2 = j1;
					while (*(argv[i] + j1) != ' ') j1--;
					jn2 = j1 + 1;
					iter = 1; 
				}
				else
				{
					while (*(argv[i] + j1) == ' ') j1--;
					jk2 = j1 + 1;
					while (*(argv[i] + j1) != ' ') j1--;
					jn2 = j1 + 1;
				}
				if (*(argv[i] + jn1) - *(argv[i] + jn2) > 0)
				{
					comboRevers(argv[i], jn1, jk1, jn2, jk2);
					lengthWord(argv[i], jn1, &jk1);
					j = jk1;
				}
				else if (*(argv[i] + jn1) == *(argv[i] + jn2))
				{
					int jn1_d = jn1, jn2_d = jn2;
					while (*(argv[i] + jn1_d) == *(argv[i] + jn2_d))
					{
						jn1_d++; jn2_d++;
					}
					if (*(argv[i] + jn1_d) - *(argv[i] + jn2_d) > 0)
					{
						comboRevers(argv[i], jn1, jk1, jn2, jk2);
						lengthWord(argv[i], jn1, &jk1);
					}
				}
			}
		}
	}
	for (int i = 1; i < argc; i++)
	{
		puts(argv[i]);
	}
	return 0;
}

 