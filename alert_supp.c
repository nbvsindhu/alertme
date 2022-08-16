#include <stdio.h>
#include <stdlib.h>

main()
{

FILE *in2;
int i=0;
char field1[20],pid_field[20],field3[20],field4[20],field5[20],field6[20];
char task_kill[20];
	   

//system("tasklist | find \"alertme\">pids.cfg");	
	
in2 = fopen("pids.cfg", "r" );
	while(fscanf(in2,"%s %s %s %s %s %s ",field1,pid_field,field3,field4,field5,field6)!=EOF)
	{
	strcpy(task_kill,"taskkill /PID ");
	strcat(task_kill,pid_field);
	strcat(task_kill," /F > test5.cfg");
	system(task_kill);
	//printf("\n\n%s\n\n", task_kill);
	break;      
	}

fclose(in2);

}