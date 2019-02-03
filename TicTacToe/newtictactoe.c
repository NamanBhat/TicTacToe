#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
void m(int,int);
void f(int,int);
int arr[3][3];
void delay(){
	int i,j;
	for(i=0;i<20000;i++){
		for(j=0;j<20000;j++){
			i-j;
		}
		
	}
}void gotoxy(int col,int row)
{
	COORD position ={row,col};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);	}
	int get2c(){
	char c;
	static int d;
	c=getch();
	fflush(stdin);
	d=c;
	return 256+d;
}
int arrowonly(){long int a=(get2c());
    if(a==224)
	a=(a)*1000+(get2c()-256);
	else a=a-256;

	return 0;

}
int arrow(){long int a=(get2c());
    if(a==224)
	a=(a)*1000+(get2c()-256);
	else a=a-256;

	return a;

}
	int getkey(){
	long int a=arrow();
	if(a==13) return 5;
	if(a==224072) return 1;
	if(a==224080) return 2;
	if(a==224075) return 3;
	if(a==224077) return 4;
	return 0;
}
void get(int*a,int*b)
{static int x=3,y=1;cursor(0);
wait:	
	 if(kbhit){
		 	int v=getkey();
		 	if(v==1)goto up;
		 	if(v==2)goto down;
		 	if(v==3)goto left;
		 	if(v==4)goto right;
			if(v==5)goto swap;
			  goto wait;}
	left:
		{if(x!=1)
		 x=x-1;
		 gotoxy((1+3*(y-1)),(1+4*(x-1)));
		 if(kbhit){
		 	int v=getkey();
		 	if(v==1)goto up;
		 	if(v==2)goto down;
		 	if(v==3)goto left;
		 	if(v==4)goto right;
		 	if(v==5)goto swap;
			
		     
;}
		 goto wait;

		}
	up:
		{if(y!=1)
		 y=y-1;
		 gotoxy((1+3*(y-1)),(1+4*(x-1)));
		 if(kbhit){
		 	int v=getkey();
		 	if(v==1)goto up;
		 	if(v==2)goto down;
		 	if(v==3)goto left;
		 	if(v==4)goto right;
		 	if(v==5)goto swap; }
		 
		    goto wait;
		}
	right:
		{if(x!=3)
		 x=x+1;
		 gotoxy((1+3*(y-1)),(1+4*(x-1)));
		 if(kbhit){
		 	int v=getkey();
		 	if(v==1)goto up;
		 	if(v==2)goto down;
		 	if(v==3)goto left;
		 	if(v==4)goto right;
		 	if(v==5)goto swap; }
		
		    goto wait;
		}
	down:
		{if(y!=3)
		 y=y+1;
		 gotoxy((1+3*(y-1)),(1+4*(x-1)));
		 if(kbhit){
		 	int v=getkey();
		 	if(v==1)goto up;
		 	if(v==2)goto down;
		 	if(v==3)goto left;
		 	if(v==4)goto right;
		 	if(v==5)goto swap; }
		
		    goto wait;
		}
			swap:
		{*a=y;*b=x;

		}
}void consolesize(){CONSOLE_FONT_INFOEX console_info  ;
    console_info.cbSize = sizeof(console_info);
	console_info.dwFontSize.X = 36;
	console_info.dwFontSize.Y= 48;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),FALSE,  &console_info);
	
}
void cursor(int i){
	CONSOLE_CURSOR_INFO info;
	info.dwSize=100;
	if(i==1)
	info.bVisible = FALSE;
	else info.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void vertical(int a,int b){
	f((3-((a+2)%3)),b);
}
void horizontal(int a,int b){
	f(a,(3-((b+2)%3)));
}	
void checkwin(){delay();gotoxy(10,10);
	printf("   COMPUTER WINS!!!");
	delay();
	delay();
	delay();
	exit(1);
}
void start()
{   printf("   |   |                                            \n");
	printf("   |   |                     TIC                    \n");
	printf("___|___|___                                         \n");
	printf("   |   |                                            \n");
	printf("   |   |                     TAC                    \n");
    printf("___|___|___                                         \n");
	printf("   |   |                                            \n");
	printf("   |   |                     TOE                    \n");
	printf("   |   |                                            \n");
	delay();
		gotoxy(10,10);
	printf("COMPUTER plays");
	delay();
	f(1,3);arr[0][2]=1;
	
	
}
 

void m(int a,int b){arr[a-1][b-1]=1;
	gotoxy((1+3*(a-1)),(1+4*(b-1)));
	printf("O");
	gotoxy(10,10);
	printf("                   ");
	}
void f(int a,int b){cursor(1);arr[a-1][b-1]=1;	delay();
		gotoxy(10,10);
	printf("COMPUTER plays");
	delay();
	gotoxy((1+3*(a-1)),(1+4*(b-1)));
	printf("X");
		gotoxy(10,10);
	printf("                   ");
	}
int main(){consolesize();
    cursor(1);
	int a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
	start();sos1:gotoxy(10,10);
	printf("Your turn      ");gotoxy((1+3*(1-1)),(1+4*(3-1)));
	get(&a1,&b1);
	if(arr[a1-1][b1-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos1;
	}
	m(a1,b1);
	
	
	//case 1 (+ positions)
	if((a1+b1)%2!=0){
		f(3-((a1+b1)%3),3-((a1+b1)%3));
	sos2:gotoxy(10,10);
	printf("Your turn     ");gotoxy((1+3*(a1-1)),(1+4*(b1-1)));
	get(&a2,&b2);
	if(arr[a2-1][b2-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos2;
	} 
	m(a2,b2);
	if((a2+b2==3)||(a2+b2==5))
	f(2,2);
	else {if(a1+b1==5)
	
	{f(1,2);
	 checkwin();}
	 if(a1+b1==3)
	{f(2,3);
	checkwin();}}
	sos3:gotoxy(10,10);
	printf("Your turn     ");gotoxy((1+3*(a2-1)),(1+4*(b2-1)));
	get(&a3,&b3);
	if(arr[a3-1][b3-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos3;
	}
	m(a3,b3);
	if(((a1+b1==5)&&((a3==3)&&((b3==1)||(b3==3))))||((a1+b1==3)&&((b3==1)&&((a3==1)||(a3==3)))))
	{
	if((b2-b1==2)||(b2-b1==1))
	vertical(a3,b3);	
	if((a1-a2==2)||(a1-a2==1))
	horizontal(a3,b3);
	checkwin();}
    else {
    if(a1+b1==5)
	{f(3,3);
	 checkwin();}
	else if(a1+b1==3)
	{f(1,1);
	checkwin();}
   	}}
   	
   	
   	//case 2 (alternate corner positions)
   	if((a1==b1)&&((a1==1)||(a1==3))){
   		f(3,1);
	sos4:gotoxy(10,10);
	printf("Your turn     ");gotoxy((1+3*(a1-1)),(1+4*(b1-1)));
	get(&a2,&b2);
	if(arr[a2-1][b2-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos4;
	}
	    m(a2,b2);
	    if((a2==2)&&(b2==2))
	    {f((3-((a1+2)%3)),(3-((a1+2)%3)));
	 	sos5:gotoxy(10,10);
		printf("Your turn     ");gotoxy((1+3*(a2-1)),(1+4*(b2-1)));
	get(&a3,&b3);
	if(arr[a3-1][b3-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos5;
	}
	    m(a3,b3);
	    if(((a3==2)&&(b3==(3-((a1+2)%3))))||((b3==2)&&(a3==(3-((a1+2)%3)))))
		{f(b3,a3);
		checkwin();	}
		else{
			f(2,a2);
		    checkwin();
		}
		}
   		else
   		{f(2,2);
   		checkwin();}
   		}
   		
	   
	   
    //case3 (opposite corner)
	if((a1==3)&&(b1==1))
	   {
	   f(3,3);
	   	sos6:gotoxy(10,10);
	printf("Your turn     ");gotoxy((1+3*(a1-1)),(1+4*(b1-1)));
	get(&a2,&b2);
	if(arr[a2-1][b2-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos6;
	}
	   m(a2,b2);
	   if((a2==2)&&(b2==3)){
	   	f(1,1);
	sos7:gotoxy(10,10);
	printf("Your turn     ");gotoxy((1+3*(a2-1)),(1+4*(b2-1)));
	get(&a3,&b3);
	if(arr[a3-1][b3-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos7;
	}
	   m(a3,b3);
	   if(((a3==1)||(a3==2))&&(b3==2)){
	   	f((2-((a3+1)%2)),2);
	   	checkwin();
	   }
	  else {
	   	f(2,2);
	   	checkwin();}
	    }
	    
	   else {
	   	f(2,3);
	   	checkwin();
	   }
	   }
	   
	   
	   
	   //case4 (middle position)
	   if((a1==2)&&(b1==2))
	   {f(3,1);
	   	sos8:gotoxy(10,10);
		printf("Your turn     ");gotoxy((1+3*(a1-1)),(1+4*(b1-1)));
	get(&a2,&b2);
	if(arr[a2-1][b2-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos8;
	}
	   m(a2,b2);
	   if((a2==b2)&&((b2==1)||(b2==3)))  //case 4a WIN
	   {f((3-((a2+2)%3)),(3-((a2+2)%3)));
	 	sos9:gotoxy(10,10);
		printf("Your turn     ");gotoxy((1+3*(a2-1)),(1+4*(b2-1)));
	get(&a3,&b3);
	if(arr[a3-1][b3-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos9;
	}
	    m(a3,b3);
	    if(((a3==2)&&(b3==(3-((a2+2)%3))))||((b3==2)&&(a3==(3-((a2+2)%3)))))
		{f(b3,a3);
		checkwin();	}
		else{
			f(2,a2);
		    checkwin();} }	
	   
	   
	   else   //case 4a DRAW
	   {
	  
	   if(a2==2){
	   
	   	f(2,(3-((b2+2)%3)));
	sos10:gotoxy(10,10);
		printf("Your turn     ");gotoxy((1+3*(a2-1)),(1+4*(b2-1)));
	get(&a4,&b4);
	if(arr[a4-1][b4-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos10;
	};
	    m(a4,b4);
	    if((a4==b4)&&(a4==3-((b2+2)%3))){
	    f(b2,b2);}
		else{
			f(3-((b2+2)%3),3-((b2+2)%3));
			checkwin();
		}
	   	sos11:gotoxy(10,10);
		printf("Your turn     ");gotoxy((1+3*(a4-1)),(1+4*(b4-1)));
	get(&a5,&b5);
	if(arr[a5-1][b5-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos11;
	}
	    m(a5,b5);
	    if((a5==b2)&&(b5==2))
	    {vertical(a5,b5);gotoxy(10,10);
	    printf("OOPS!! ITS A DRAW");
	    delay();delay();delay();
		}
		else{
			f(b2,2);
			checkwin();
		}}
		if(b2==2){
	   	f((3-((a2+2)%3)),2);
	   		sos12:gotoxy(10,10);
		printf("Your turn     ");gotoxy((1+3*(a2-1)),(1+4*(b2-1)));
	get(&a4,&b4);
	if(arr[a4-1][b4-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos12;
	}
	    m(a4,b4);
	    if((a4==b4)&&(a4==3-((a2+2)%3))){
	    f(a2,a2);}
		else{
			f(3-((a2+2)%3),3-((a2+2)%3));
			checkwin();
		}
	sos14:gotoxy(10,10);
	printf("Your turn     ");gotoxy((1+3*(a4-1)),(1+4*(b4-1)));
	get(&a5,&b5);
	if(arr[a5-1][b5-1]!=0){
		gotoxy(10,10);
		printf(" INVALID SELECTION!!!");
		delay();delay();gotoxy(10,10);
		printf("                       ");
		goto sos14;
	}
	    m(a5,b5);
	    if((b5==a2)&&(a5==2))
	    {horizontal(a5,b5);gotoxy(10,10);
	    printf("OOPS!! ITS A DRAW");
	    delay();delay();delay();
		}
		else{
			f(2,a2);
			checkwin();
		}}
		}}return 0;}



































