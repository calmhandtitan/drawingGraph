#include<stdio.h>
#include<stdlib.h>
#define MAX 1<<20

FILE *out;
FILE *in;
int is_connected[MAX];


int main()
{
	char filename_in[20], filename_out[20];

	printf("Enter filename whose graph to draw>>");
	scanf("%s", filename_in);		//get the filename

	in = fopen(filename_in, "r");	//open file
	if(in == NULL)
		printf("cannot open file %s\n", filename_in);
	
	sprintf(filename_out, "%s_graph.gv",filename_in);	//initialize name of output file
	
	out = fopen(filename_out, "w");	//open output dot file
	if(out == NULL)
		printf("unable to create file %s\n",filename_out);
	fprintf(out, "digraph G{\n");

	int flag = 1, x, y, no_of_nodes, i;
	while(fscanf(in, "%d %d", &x, &y) != EOF)
	{
		if(flag)
		{
			flag = 0;		//for the first iteration where n and e are entered
			no_of_nodes = x;
		}
		else
		{
			fprintf(out, "%d -> %d;\n", x, y);
			is_connected[x] = is_connected[y] = 1;
		}
	}
	for(i = 1; i <= no_of_nodes; i++)
	{
		if(!is_connected[i])
			fprintf(out, "%d;\n", i);
	}
	fprintf(out, "}\n");
	fclose(in);
	fclose(out);

	char buff[80];
	sprintf(buff, "dot -Tjpg %s -o %s_graph.jpg\n", filename_out, filename_in);

	system(buff);
	printf("\t\t\tgraph created succesffully\n");


	return 0;
}	
