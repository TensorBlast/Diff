#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 10000

int print_usage();

int main(int argc, char **argv)
{	

	if (argc<3)
		print_usage();

	FILE *f1;
	FILE *f2;
	char *line1, *line2;
	int linenum = 0;

	line1 = (char *)malloc(MAXLINE * sizeof(char));
	line2 = (char *)malloc(MAXLINE * sizeof(char));

	if((f1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "%s cant open %s\n",argv[0], argv[1]);
		exit(2);
	}
	if ((f2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "%s cant open %s\n",argv[0], argv[1]);
		exit(2);
	}

	while((fgets(line1, MAXLINE, f1)) !=NULL && (fgets(line2, MAXLINE, f2))!=NULL){
		linenum++;
		if (strcmp(line1,line2)!=0) {
			printf("Line %d: %s\n",linenum, line2);
		}
	}
	fclose(f1);
	fclose(f2);

	exit(0);
}

int print_usage()
{
	printf("%s\n", "Usage: diff file1 file2");
	exit(1);
}