#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<dos.h>
#define t 1000
#define t2 2000

void timings();
void borders();
void loading();
void invalid();
void menu();
void new_member();
void login();
void retrieve();
void terminate();

void main()
{
   int temp,check;
   char n1[100],n2[100];
   clrscr();
   borders();
//////////   delay(500);
   gotoxy(23,3);
   printf("WELCOME TO YOUTEE BANK OF INDIA");
   timings();
//////////   delay(t);
   gotoxy(5,11);
   printf("Welcome User!");
//////////   delay(t);
   gotoxy(5,13);
   printf("Enter your first name : ");
   scanf("%s",&n1);
   gotoxy(5,14);
   printf("Enter your last name : ");
   scanf("%s",&n2);
//////////   delay(t);
   gotoxy(27,18);
   printf("Welcome, %s %s!",n1,n2);
//////////   delay(t);
   gotoxy(15,23);
   printf("Press ENTER to continue and any other key to exit!");
   temp=getch();
   if(temp==13)
   {
      menu();
   }
}

void menu()
{
      int choice;
      clrscr();
      borders();
      delay(200);
      gotoxy(29,3);
      printf("SELECT FROM THE FOLLOWING");
      delay(200);
      timings();
      delay(200);
      gotoxy(3,8);
      printf("1. BECOME A NEW MEMBER");
      gotoxy(3,10);
      printf("2. LOGIN TO YOUR ACCOUNT");
      gotoxy(3,12);
      printf("3. RETRIEVE ACCOUNT");
      gotoxy(3,14);
      printf("4. EXIT");
      while(1)
      {
       //	 system("cls");
	 gotoxy(27,18);
	 printf("Enter your choice : ");
	 scanf("%d",&choice);
////////// Check for enhancement!
      //	 choice=getch();
	 if(choice<1||choice>4)
	 {
	    invalid();
	 }
	 else
	 break;
      }
      switch(choice)
      {
/*	 case 1: new_member();
		 break;

	 case 2: login();
		 break;

	 case 3: retrieve();
		 break;
*/
	 case 4: terminate();
		 break;

	 default: printf("Choice Unavailable!");
		  break;
      }
//      getch();
}

void terminate()
{
   int temp;
   clrscr();
   borders();
   gotoxy(30,10);
   printf("You chose to exit!");
   gotoxy(22,11);
   printf("Are you sure you want to continue?");
   gotoxy(16,13);
   printf("Press \"Y\" to CONTINUE or \"N\" to return to MENU!");
   x:
   temp=getch();
   if(temp==78||temp==110)
   {
      gotoxy(35,18);
      printf("Loading");
      loading();
      delay(t);
      menu();
   }
   else if(temp==89||temp==121)
   {
      gotoxy(35,17);
      printf("Goodbye!");
      delay(t2);
   }
   else
   {
      gotoxy(27,17);
      printf("Wrong Choice, Try Again!");
      delay(t2);
      gotoxy(27,17);
      printf("                        ");
      delay(2001);
      gotoxy(63,13);
      goto x;
   }
//   getch();
}

void invalid()
{
   gotoxy(30,22);
   printf("Invalid Choice!");
   delay(t);
   gotoxy(28,22);
   printf("                                ");
   delay(1);
   gotoxy(47,18);
   printf("         ");
   delay(1);
}

void loading()
{
    delay(500);
    printf(".");
    delay(500);
    printf(".");
    delay(500);
    printf(".");
}

void borders()
{
   int i,x,y,z;
//   clrscr();
   for(i=2;i<79;i++)
   {
     gotoxy(i,1);
     printf("-");
//////////     delay(5);
   }
   goto x;
   y:
   for(i=78;i>1;i--)
   {
     gotoxy(i,25);
     printf("-");
//////////     delay(5);
   }
   for(i=24;i>1;i--)
   {
     gotoxy(1,i);
     printf("|");
//////////     delay(5);
   }
   goto z;
   x:
   for(i=2;i<25;i++)
   {
     gotoxy(79,i);
     printf("|");
//////////     delay(5);
   }
   goto y;
   z:
//   getch();
//   timings();
//   getch();
}

void timings()
{
   time_t rawtime;
   struct tm *timeinfo;
//   clrscr();
   time(&rawtime);
   timeinfo=localtime(&rawtime);
//////////   delay(t);
   gotoxy(50,6);
///// printf("Current time and date :\n");
///// gotoxy(50,7);
   printf("%s", asctime(timeinfo));
//   getch();
}
