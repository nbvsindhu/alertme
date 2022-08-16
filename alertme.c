#include <stdio.h>
#include <stdlib.h>

main (int argc, char *argv[])
{


// 1alertme 210.31.32.227
	   FILE *in, *in2;
	   char ping_var[50];
	   char ping_loss[10];	
	   int ping_true1=2;
	   int ping_true2=2;
	   int ping_true3=2;
	   int i=0;
	   int j=0;
	   char cont_loop[20];
	   char task_kill[20];
	  // char field1[20],pid_field[20],field3[20],field4[20],field5[20],field6[20];

	   if(argc !=2) {
			printf("\n\tSyntax:  ALERTME [ip address]\n\n");
			exit(0);
			}
   
	system("alert_supp");

        strcpy(ping_var,"ping ");
        strcat(ping_var,argv[1]);
        strcat(ping_var,">test.cfg");       // Prepare the "ping 192.168.29.143 > test.cfg"  command
        system(ping_var);	   				// execute

	in = fopen("test.cfg", "r" );
	while(fscanf(in,"%s",ping_loss)!=EOF)
	{
	//printf("%s\n",ping_loss);
	
         
	ping_true1 = strcmp(ping_loss,"out.");
        ping_true2 = strcmp(ping_loss,"unreachable.");
        ping_true3 = strcmp(ping_loss,"not");
     
   //     printf("\nThe ping_true1,2 value is %d,%d\n", ping_true1,ping_true2);		
	
	if(ping_true1 == 0 || ping_true2 == 0 || ping_true3 == 0) 							// Checking the Not reacher server log messages
	{
	printf("\nThe server is down.");
	break;	
	}

	}

	fclose(in);

	if(ping_true1 != 0 && ping_true2 != 0 && ping_true3 != 0) 
	{
	printf("\nThe server %s is alive.\n", argv[1]);
	printf(".\a\a\a\n");												// Beeping....
		}

//printf("\nThe values of 1,2,3 are %d, %d, %d\n", ping_true1,ping_true2,ping_true3);
	
	strcpy(cont_loop,"alertme ");
	strcat(cont_loop,argv[1]);

system("tasklist | find \"alertme\">pids.cfg");	
	
		
	system(cont_loop);



        }
       