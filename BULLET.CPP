

  char namebin[30];
  float sscore=0;
  char mail[30];

 struct highscore
{
 char name[30];     //highscore binary struct
 float score;
 char email[30];
};

//Function Prototypes

 void high_set(highscore);
 void disphigh();


void bullet()
{
   clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"..\\BGI");
 setcolor(CYAN);
 int x=0,r=130,i=580,hitflag=0,level=1;
//x is bullet on or off     
//flag.r is x coordinate.i is y coordinate.
 float b_left=6,bul=0,no_bull=0,accuracy=0;
 char chnew;
 char playgame;
 randomize();

		  for(int q=1;q<180;q++)
	       {
		   delay(10);

		  if(q<90)
		 {
		   rectangle(200,200,200+q,205);

		   outtextxy(180,275," Searching for guns");
		 }

		  else if(q==90)
		 {
		  cleardevice();
		  rectangle(200,200,200+q,205);

	       }


	       else
	       {
	       rectangle(200,200,200+q,205);
	       outtextxy(180,275," Loading your guns");
	       }
	     }//loading loop

settextstyle(7,0,2);
setcolor(CYAN);
cleardevice();
outtextxy(150,275," Open your eys ....Take the aim... ");
delay(980);
cleardevice();
outtextxy(69,180,"Because.... ");
delay(980);
cleardevice();
outtextxy(120,300,"He is on the run...");
delay(980);
cleardevice();
outtextxy(111,140,"Blood hungry... ");
delay(980);
cleardevice();
setcolor(RED);
outtextxy(219,216,"  Waiting for the OBVIOUS ");
delay(3000);
cleardevice();

for(int llll=0;llll<4;llll++)
{
 for(int load=20;load<100;load+=20)
   {
    for(int lo=20;lo<100;lo+=20)
    {
   setcolor(YELLOW);
    rectangle(240+lo,240,246+lo,210);
    }
  setcolor(RED);
  setfillstyle(BKSLASH_FILL,RED);
  rectangle(240+load,240,246+load,210);
  floodfill(243+load,225,RED);
  delay(500);
  cleardevice();
    }
} //boxloading



       flg1:
{


 cleardevice();
 settextstyle(10,0,3);
 setcolor(RED);
//menu
 outtext("          ==\\\\ BULLET //==");
 settextstyle(7,0,1);
 setcolor(CYAN);
 outtextxy(200,125,"  1. START NEW GAME");
 settextstyle(7,0,1);
 outtextxy(200,175,"  2.   HIGH SCORE");
 setcolor(CYAN);
 outtextxy(200,225,"  3.    CREDITS");
 settextstyle(7,0,1);
 setcolor(CYAN);
 outtextxy(200,275,"  4.    EXIT");
 settextstyle(7,0,1);


 while(!kbhit())
{
	chnew = getch();
	if(chnew=='1')    //game starts
{
  do
 {
 cleardevice();
 outtextxy(200,200,"Enter your name: ");
 gotoxy(52,14);
 gets(namebin);
 cleardevice();
 outtextxy(100,200,"Enter your email id for updates: ");
 gotoxy(52,14);
 gets(mail);
 float score=0;
 cleardevice();

  do   //num of time zombie goes up
{

    if(x==1)
  {
    rectangle(r,189,9+r,192);
    r+=15;                        //BULLET

     if(r>=595)   //right end of screen reached by bullet
   {
   x=0;
   r=130;
   if(b_left<=0)
   break;//checking for last bullet if so break out of while(1) loop
   }
  }


 delay(40);
 cleardevice();
 setcolor(RED);    //game page

 if(no_bull>0)
 {
 accuracy= 100*bul/no_bull;
 }
gotoxy(45,25);
cout<<no_bull;
gotoxy(45,24);
cout<<bul;
gotoxy(45,22);
if(no_bull>0)
cout.setf(ios::fixed);
cout<<setprecision(2)<<accuracy<<" %";



outtextxy(200,400,"Press 'f' To Fire.");
outtextxy(200,420,"Press 'e' to exit,");

	    if(hitflag==1)
	 {
		   setcolor(WHITE);
		   setfillstyle(CLOSE_DOT_FILL,WHITE);
		   circle(560,i,20);
		   floodfill(570,i+10,WHITE);
		   outtextxy(520,i-50,"Power Up");
		   outtextxy(570,i+10,"2");
	 }//powerup

	   else if(hitflag==3||hitflag==5)
	 {
			 setcolor(RED);
			 setfillstyle(10,RED);
			 circle(560,i,20);
			 floodfill(570,i+10,RED);
			 outtextxy(520,i-50,"Banana");
			 outtextxy(570,i+10,"-1");
	 }//negetive powerup



		 else       //zombie
	{
			setfillstyle(SOLID_FILL,RED);
			//head
			circle(560,i,15);
			floodfill(560,7+i,RED);
			setcolor(YELLOW);
			//eyes
			circle(551,i-1,4);
			circle(563,i-1,4);
			setcolor(RED);
			setfillstyle(SOLID_FILL,RED);
			//body
			ellipse(560,47+i,0,360,10,30);
			floodfill(559,44+i,RED);
			setcolor(WHITE);
			 }
//gun always present
setcolor(LIGHTGRAY);
rectangle(5,5,620,455);
setfillstyle(1,LIGHTGRAY);
rectangle(70,180,130,200);
floodfill(71,181,LIGHTGRAY);
setfillstyle(1,LIGHTGRAY);
arc(70,190,90,270,10);
floodfill(65,190,LIGHTGRAY);
setfillstyle(1,LIGHTGRAY);
rectangle(120,179,123,177);
floodfill(122,178,LIGHTGRAY);
rectangle(130,189,139,192);//bullet
int rect[10] = {70,200,65,230,85,230,90,200,70,200};
setfillstyle(1,DARKGRAY);
fillpoly(5,rect);


gotoxy(45,8);       //level
cout<<"1";

//Bullet hitting zombie
 if(hitflag!=1&&hitflag!=3&&hitflag!=5)     //ensuring no presence of powerups
		{
	 if(x==1 && 189>=(i-15) && 192<=(77+i) && r+9>=560 && r<=570)
			{
			 score+=10;
			 r+=15;
			 delay(1000);

			 for(int pp=3;pp<30;pp++)
	{
		setcolor(1+pp);
		circle(550,189,5+pp);
		delay(50);
	}
			// delay(3000);
			 bul++;

			 }

		}//outer if

 else if(hitflag==1)//powerup hit checking
{
			 if(x==1 && (i-20)<189 && (i+20)>192 && (r+9)>560 && r<580)
	{
	 score+=5;
	 r+=40;
	 delay(1000);
	 for(int pp=3;pp<30;pp++)
		{
		 setcolor(1+pp);
		 circle(550,189,5+pp);
		 delay(50);
		}
	 b_left+=2;
	 bul++;
	}//if

}//else

 if(hitflag==3||hitflag==5)//negetive powerup check
{
		if(x==1 && (i-20)<189 && (i+20)>192 && (r+9)>560 && r<580)
		{

			score-=5;
			r+=40;
			delay(1000);
			for(int pp=3;pp<30;pp++)
			{
			 setcolor(1+pp);
			 circle(550,189,5+pp);
			 delay(50);
			}
			// delay(3000);
			 b_left-=2;
			 bul++;
		}//if

}//else


				//levels
	if(bul>=2&&bul<=4)
			{
		i-=3;   //incresing speed
		level=2;
		gotoxy(45,8);
		cout<<level;

			}
	else if(bul>=4&&bul<=6)
			{

		i-=6;
		level=3;
		gotoxy(45,8);
		cout<<level;
			}
	else if(bul>=6&&bul<=9)
			{

		i-=8;
		level=4;
		gotoxy(45,8);
		cout<<level;

			}
line(90, 200, 105, 210);

rectangle(120,179,123,177);
setcolor(YELLOW);

sscore=score;//storing score a in global variable for use in binary files
settextstyle(1,0,1);
setcolor(GREEN);
outtextxy(218,27,"WELCOME ");
gotoxy(40,3);
puts(namebin);
settextstyle(5,0,3);
setcolor(YELLOW);
settextstyle(8,0,3);
settextstyle(8,0,3);
outtextxy(252,99,"LEVEL ");
settextstyle(8,0,2);
outtextxy(50,355,"Number of hits         : ");
outtextxy(50,375,"Numer of bullets fired  : ");
outtextxy(50,330,"Accuracy               : ");
settextstyle(3,0,2);
setcolor(YELLOW);
outtextxy(10,294,"You have ");
outtextxy(140,294,"bullets left");
gotoxy(15,20);
cout<<b_left;
gotoxy(60,3);
cout<<score;
outtextxy(400,25,"Score: ");

i-=4;//decreasing y coordinate for zombie and powerups to move upward

if(i<=4)//ensuring if object(y coordinate) reached top of screen
{
 i=580;//starting form screen bottom
 hitflag = random(level+2);//used to decrease probability of approach of powerups
}

	 if(kbhit())
			 {
	char ch = getch();
	if(ch=='f' && x==0)
	 {
			 sound(500);
			 delay(255);
			 nosound();
			 b_left--;
			 no_bull++;
			 x=1;

	 }
 else if(ch=='e')
	goto flg1;




}//if


}//do-while loop
 while(1);
 b_left=6;
 no_bull=0;
 level=1;
 bul=0;
 accuracy=0;
 int rotate=0;
 cleardevice();

 for(int kkk=0;kkk<5;kkk++)
{
	settextstyle(7,(rotate%2),4);
	rotate++;
	if(rotate%2) outtextxy(200,200,"GAME OVER");
	else outtextxy(250,150,"GAME OVER");
	delay(300);
	cleardevice();
}


//END OF GAME

highscore s_new;
s_new.score =sscore;
strcpy(s_new.email,mail);
strcpy(s_new.name,namebin);
high_set(s_new);



settextstyle(4,0,3);
outtextxy(200,200,"Play again ?: press y");

	playgame= getch();

}//play game all ovr again do-while loop
 while(playgame=='y');
	cleardevice();
	goto flg1;


}//chnew 1 ends


 if(chnew=='3')//credits menu
{
cleardevice();
setcolor(YELLOW);
outtextxy(200,10,"Developed by BLITZ.inc.")   ;
delay(800);
cleardevice();
setcolor(YELLOW);
delay(400);
outtextxy(200,90,"Shanny and team"       )  ;
delay(800);
cleardevice();
setcolor(YELLOW);
delay(400);
outtextxy(200,180,"owe you Bjarn            " )  ;
delay(800);
cleardevice();
setcolor(YELLOW);
delay(400);
outtextxy(200,270,"thank you C++           "   )  ;
delay(800);
cleardevice();

setcolor(YELLOW);
delay(400);
outtextxy(200,360,"thank you you Bell labs"     )  ;
delay(800);
setcolor(YELLOW);
cleardevice();
setcolor(YELLOW);
delay(400);
outtextxy(200,140,"press 0 to go back");
char ch1;
cin>>ch1;
if(ch1=='0')
goto flg1;

}//chnew 3


if(chnew=='2')
{
cleardevice();


disphigh();

outtextxy(200,340,"press 0 to go back");
char ch2;
cin>>ch2;
if(ch2=='0')
goto flg1;

}

 if(chnew=='4')
 {
 break;
 }



}//FLAG ENDING





 }//kbhit for choice

}

void high_set(highscore Snew)
			{
	ifstream fin("higher.dat", ios::binary);
	highscore s[6],so;
	int i = 0;
	while( fin.read((char*)&so,sizeof (so)))
	{
	s[i] = so;
	i++;


	}

	for(i = 4; s[i].score<Snew.score && i>=0; i--)     //des
	{
		s[i+1] = s[i];


	}
	s[i+1].score=Snew.score;
			strcpy(s[i+1].name,Snew.name);
			strcpy(s[i+1].email,Snew.email);
	fin.close();

	ofstream fout("high_score.dat", ios::binary);
	for(i = 0; i<5 ;i++)
	{
		 fout.write((char*)&s[i],sizeof (s[i]));
	}
	fout.close();
}

void disphigh()
	{
			 int k=0;
	 highscore so;

	ifstream fin2("high_score.dat", ios::binary);

 while(fin2.read((char*)&so,sizeof(so)))
{
 setcolor(LIGHTRED);
 settextstyle(7,0,1);
 outtextxy(20,100,"  NAME: ");
 gotoxy(5,10+k);
 puts(so.name);

 setcolor(LIGHTRED);
 outtextxy(260,100,"    SCORE: ");
 settextstyle(7,0,1);
 gotoxy(40,10+k);
 cout<<so.score;


 setcolor(LIGHTRED);
 outtextxy(400,100,"              EMAIL: ");
 settextstyle(7,0,1);
 gotoxy(66,10+k);
 cout<<so.email;

	k+=2;
}

fin2.close();

			}







