
#include<stdio.h>
#include<string.h>


int  main()
{
	struct  sale{
		const 	char  s[8];
		int   number;
	}record[4] = { { "levono", 0 }, { "acer", 0 }, { "asus", 0 }, { "dell", 0 } };


	char  brand[8];
	int i, n, m;
	scanf_s("%s  %d", brand, &m);
	for (n = 0; n < 4; n++)
	{
		if (0 == strcmp(record[n].s, brand))
		{
			record[n].number += m;
			break;
		}

	}
	FILE  *fp;
	i = fopen_s(&fp, "D:\\record.txt", "w+");
	if (!i)
	{

		for (n = 0; n < 4; n++)
		{
			fwrite(record[n].s, sizeof(record[n].s), 1, fp);
			fwrite("\t", sizeof('\t'), 1, fp);

			fwrite(&record[n].number, sizeof(int), 1, fp);
			fwrite("\n", sizeof('\n'), 1, fp);

		}
	}
	fclose(fp);

	return 0;
}


