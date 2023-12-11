#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include<ctype.h>
#include<fstream>
#include"bullet.cpp"
using namespace std;
 void funstore();
 void colorof();
 void designpg();//func used in our code for calling the apps in the main
 void bullet();
 void clock();
 void phonebook();
 void intro();
 void memory_game();
 void day();
 union REGS i,o;
 int mx,my,mc;
 int gdriver=DETECT,gmode;

	void main()
	{
	intro();
	initgraph(&gdriver,&gmode,"..//bgi");
	Z:funstore();
	char c=getch();
	if(c=='e'||c==27)
		exit(0);
	else
		goto Z;
	closegraph();
 }



					////////////////////////////////////////////////////////

//main code over
//codes for the apps made


 void funstore()
{
 while(!kbhit()) //2nd page intro
	 {
			i.x.ax=1;
		int86(0X33,&i,&o);
		i.x.ax=3;              //mouse declaration
	 int86(0x33,&i,&o);
		mx=o.x.cx;
	 my=o.x.dx;
	 mc=o.x.bx;
	 colorof();

	 if(mx>=40&&mx<=100&&my>=40&&my<=120&&mc==1)
	{
		cleardevice();
		closegraph();
		//bullet();
		cleardevice();
	 }

	 if(mx>=280&&mx<=360&&my>=40&&my<=120&&mc==1)
		{
			cleardevice();
			closegraph();
			clock();
			cleardevice();
		}
		if(mx>=520&&mx<=600&&my>=40&&my<=120&&mc==1)
	{
	cleardevice();
	closegraph();
	memory_game();
	cleardevice();
	}


 if(mx>=160&&mx<=240&&my>=240&&my<=320&&mc==1)
 {
 cleardevice();
 closegraph();
 phonebook();
 cleardevice();
 }
		if(mx>=410&&mx<=490&&my>=240&&my<=320&&mc==1)
	{
		cleardevice();
		closegraph();
		day();
		cleardevice();
	 }


	if(mx>=441&&my>=439&&mc==1)
	break;
	 delay(200);
	}
}


void intro() //introduction pg
{
 initgraph(&gdriver,&gmode,"..//bgi");
 setcolor(LIGHTGREEN);
 setfillstyle(CLOSE_DOT_FILL,WHITE);
 settextstyle(7,0,5);
 cleardevice();
			for(int i=0;i<20;i++)
		 {
			delay(100);
			circle(20+(i*i),20+(i*i),20+(i*i));
			circle(600-(i*i),430-(i*i),20+(i*i));
			setcolor(GREEN);
		 }

	 setcolor(WHITE);
	 for(int j=0,p=10;j<10||p>=0;j++,p--)
		{
		delay(100);
		outtextxy(50+j,120,"  FUN ");
		outtextxy(100-p,190," STORE");
		}
 cleardevice();
 for(j=1;j<=10;j++)
 {
	 delay(200);
	 setcolor(j);
	 settextstyle(7,0,3);
	 outtextxy(255,235,"FUNSTORE");
	 delay(100);
	 line(30,50,200*j,50);
	 line(30,445,200*j,445);
 }
 for(i=20;i<100;i++)
 {
	 setcolor(5);
	 settextstyle(10,0,4);
	 outtextxy(5*i,165,">");
	 delay(20);
 }
 for(i=100;i>=20;i--)
 {
	 outtextxy(5*i,250,"<");
	 delay(20);
 }
 cleardevice();
 }



void colorof() //main screen page code
{

 setbkcolor(BLACK);
 rectangle(10,10,625,470);
 setfillstyle(INTERLEAVE_FILL,5);
 floodfill(1,1,BLACK);
 setfillstyle(INTERLEAVE_FILL,5);
 rectangle(10,10,625,470);
 floodfill(1,1,BLACK);
 setfillstyle(SOLID_FILL,YELLOW);
 bar(40,40,120,120);
 setfillstyle(SOLID_FILL,1);
 bar(280,40,360,120);
 setfillstyle(SOLID_FILL,2);
 bar(520,40,600,120);
 setfillstyle(SOLID_FILL,6);
 bar(160,240,240,320);
 setfillstyle(SOLID_FILL,7);
 bar(410,240,490,320);
 setcolor(BLACK);
 settextstyle(8,0,2);
 outtextxy(41,65,"BULLET");
 setcolor(3);
 settextstyle(8,0,2);
 outtextxy(287,65,"CLOCK");
 setcolor(12);
 settextstyle(8,0,1);
 outtextxy(525,65,"MIND") ;
 outtextxy(547,77,"GAME");
 setcolor(BLACK);
 settextstyle(8,0,4);
 setcolor(BLACK);
 settextstyle(8,0,1);
 outtextxy(165,260,"PHONE");
 outtextxy(168,275,"BOOK");
 setcolor(BLACK);
 outtextxy(418,265,"iDAY");
 setcolor(BLUE);
 settextstyle(8,0,1);
 setcolor(WHITE);
 outtextxy(360,440,"Press e or escape for exit");

}


													 /////PHONE BOOK/////

 struct contact_DETAILS
{
	char name[50];
	char id[150];
	char mobno[20];
	char favourite[20];
	int age;
	date today;
};
//union REGS i,o;
int pg_check=0,pg_colorup=4,pg_colordown=4,fav_count=0;
//int gdriver=DETECT,gmode,mx,my,mc;

void star(int x,int y)
{
	int poly[]={x,y,x-14,y,x-7,y-10,x,y};
	int poly1[]={x,y-5,x-14,y-5,x-7,y+5,x,y-5};
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	fillpoly(3,poly);
	fillpoly(3,poly1);
}


class contact
{
	contact_DETAILS S;

	int duplicate_check(char*,char*,char*,int);
	public:
	contact()
	{
		strcpy(S.favourite,"normal");
	}
	void getcontact();
	void search();
	void insert();
	char* show_NAME();
	char* show_fav();
	void deletion();
	void alter_NAME(char*);
	void alter_MOBNO(char*);
	void alter_ID(char *);
	void alter_fav(char *);
};

void general_setup(char T[],int x,int graphic_check,int under_x,int under_y,char under_c[])
{
	if(graphic_check!=1)
		cleardevice();
	setcolor(3);
	settextstyle(10,0,2);
	rectangle(10,10,625,470);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(1,0,0);
	outtextxy(x,20,T);
	outtextxy(under_x,under_y,under_c);
}

int contact::duplicate_check(char name[50],char dup[20],char dupid[20],int dupage)
{
	int duplicate=0;
	contact_DETAILS T;
	ifstream fin("contact.dat",ios::binary);
	while(fin.read((char*)&T,sizeof(T)))
	{
		if(strcmpi(dup,T.mobno)==0&&strcmpi(dupid,T.id)==0&&strcmpi(name,T.name)==0&&dupage==T.age)
		{
			duplicate=1;
			break;
		}
	}       //duplicate contact detected
	fin.close();
	if(duplicate==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


void contact:: getcontact()
{
	int flag=0,dup=-1;
	contact_DETAILS T;
	char c,insert_check;
	i.x.ax=1;
	int86(0x33,&i,&o);
	cleardevice();
	general_setup("GETTING DETAILS",180,0,180,40,"-------------");
	settextstyle(8,0,2);
	setcolor(WHITE);
	outtextxy(80,100,"ENTER THE NAME      :");
	gotoxy(46,8);
	gets(S.name);
	do
	{
		if(strcmp(S.name,'\0')==0)
		{
			setcolor(4);
			outtextxy(100,160,"ENTER NAME AGAIN");
			delay(600);
			cleardevice();
			general_setup("GETTING DETAILS",180,0,180,40,"-------------");
			settextstyle(8,0,2);
			setcolor(WHITE);
			outtextxy(80,100,"ENTER THE NAME     :");
			gotoxy(46,8);
			gets(S.name);
		}
	}while(S.name[0]=='\0');
	outtextxy(80,130,"ENTER THE EMAIL.ID   :");
	gotoxy(46,10);
	gets(S.id);
	outtextxy(80,160,"ENTER THE MOBILE NO :");
	gotoxy(46,12);
	gets(S.mobno);
	date t;
	getdate(&t);
	S.today=t;
	outtextxy(80,190,"ENTER THE AGE       :");
	gotoxy(46,14);
	cin>>S.age;

Z:
	for(int i=0;S.mobno[i];i++)
		if(isalpha(S.mobno[i]))
		{
			flag=1;
			break;
		}
	if(flag==1)
	{
		setcolor(4);
		outtextxy(70,180,"ENTER MOBILE NUMBER AGAIN");
		delay(600);
		cleardevice();
		general_setup("GETTING DETAILS",180,0,180,40,"-------------");
		settextstyle(8,0,2);
		setcolor(WHITE);
		outtextxy(80,100,"ENTER THE NAME     :");
		gotoxy(46,8);
		puts(S.name);
		outtextxy(80,130,"ENTER THE EMAIL.ID  :");
		gotoxy(46,10);
		puts(S.id);
		outtextxy(80,160,"ENTER THE MOBILE NO :");
		gotoxy(46,12);
		gets(S.mobno);
		outtextxy(80,190,"ENTER THE AGE       :");
		gotoxy(46,14);
		cin>>S.age;

		flag=0;
		goto Z;
	}
	fstream insertf("insert.txt",ios::in|ios::out); //file which keeps track for the 1st contact added
	insertf.get(insert_check);
	dup=duplicate_check(S.name,S.mobno,S.id,S.age);
	if(dup==1)
	{
		setcolor(4);
		settextstyle(8,0,2);
		outtextxy(135,260,"GIVEN RECORD ALREADY EXISTS ");
		outtextxy(155,280,"PRESS ANY TO EXIT");
		getch();
	}

	fstream f("contact.dat",ios::binary|ios::out|ios::app);

	if(insert_check=='n')   //first record getting inserted
	{
		f.write((char*)&S,sizeof(S));
		insert_check='y';
		insertf.seekp(-1,ios::cur);
		insertf.put(insert_check);
		insertf.close();
	}
	else if(!f)             //if all records deleted
	{
		insert_check='n';
		insertf.put(insert_check);
		insertf.close();
	}
	else if(dup==1)
	{
		dup=-1;//do nothing
	}
	else
	{
		insertf.close();
		insert();
	}

	f.close();
	cleardevice();
}
void contact:: insert()
{
	int flag=0;
	contact_DETAILS T;
	ifstream fin("contact.dat",ios::binary);
	if(fin)
	{
		ofstream fout("temp.dat",ios::binary|ios::app);
		while(fin.read((char*)&T,sizeof(T)))
		{
			if(strcmpi(S.name,T.name)<0&&flag==0)
			{
				flag++;
				fout.write((char*)&S,sizeof(S));
			}
			fout.write((char*)&T,sizeof(T));
		}

		fin.close();
		if(flag==0)
			fout.write((char*)&S,sizeof(S));
		fout.close();
		remove("contact.dat");
		rename("temp.dat","contact.dat");
	}
}

void contact:: search()
{
	fstream fin("contact.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	if(!fin||fin.tellg()==0)
	{
		general_setup("SEARCH",200,0,200,40,"------");
		settextstyle(8,0,2);
		setcolor(4);
		outtextxy(155,150,"NO CONTACTS YET SAVED");
		outtextxy(155,170,"PRESS ANY KEY TO EXIT");
		getch();
	}
	else
	{
		int search_count=0;
		cleardevice();
		general_setup("SEARCH",200,0,200,40,"------");
		setcolor(WHITE);
		settextstyle(7,0,2);
		char T[]="ENTER THE NAME:";
		outtextxy(80,100,T);

		rectangle(300,110,520,130);
		fin.seekg(0,ios::beg);
		char C[100] ="",Search_name[100];
		int i=0;

		int linecount=0;
		//for search results
		while(1)
		{
			char t=getch();
			cleardevice();
			setcolor(3);
			settextstyle(10,0,2);
			rectangle(10,10,625,470);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(1,0,0);
			outtextxy(200,20,"SEARCH");
			outtextxy(200,40,"------");
			setcolor(4);
			settextstyle(7,0,2);
			setcolor(WHITE);
			settextstyle(7,0,2);
			char T[]="ENTER THE NAME:";
			outtextxy(80,100,T);
			gotoxy(40,8);
			rectangle(300,110,520,130);


				C[i] = t;
				C[i+1] = '\0';


			if(t==8)
			{
				i-=2;
				C[i+1] ='\0';
			}


			setcolor(WHITE);
			outtextxy(302,110,C);

			fin.open("contact.dat",ios::binary|ios::in);

			linecount = 0;

			while(fin.read((char*)&S,sizeof(S)))
			{
				for(int z=0;z<strlen(C);z++)
					Search_name[z]=S.name[z];
				Search_name[z]='\0';
				if(strcmpi(C,Search_name)==0)
				{
					linecount++;
					setcolor(WHITE);
					outtextxy(302,110+20*linecount,S.name);
					rectangle(300,110,520,130+20*linecount);
				}
			}
			fin.close();

			if(t==80 )
			{
				i--;
				if(search_count<linecount)
					search_count++;
				setcolor(YELLOW);
				rectangle(300,110+20*search_count,520,130+20*search_count);

				continue;
			}
			if(t==72)
			{
				i--;
				if(search_count!=0)
					search_count--;
				setcolor(YELLOW);
				rectangle(300,110+20*search_count,520,130+20*search_count);
				continue;
			}



			if(t==13)
			{
				if(search_count==0)
				{
					C[i]='\0';
					int namefound=0;
					char A[100];
					strcpy(A,C);
					fin.open("contact.dat",ios::binary|ios::in);
					fin.seekg(0,ios::beg);
					general_setup("SEARCH",200,0,200,40,"------");
					while(fin.read((char*)&S,sizeof(S)))
					{
						if(strcmp(A,S.name)==0)
						{
							namefound=1;
							settextstyle(8,0,2);
							outtextxy(20,150,"NAME     :");
							outtextxy(150,150,S.name);
							outtextxy(20,190,"MOBILE NO:");
							outtextxy(150,190,S.mobno);
							outtextxy(20,230,"EMAIL  ID:");
							outtextxy(150,230,S.id);
							break;
						}
					}
					fin.close();
					if(namefound==0)
					{
						setcolor(4);
						settextstyle(8,0,2);
						outtextxy(145,155,"SORRY,NAME NOT FOUND");
					}
				}

				else

				{
					char A[100];
					int linecount=0;
					fin.open("contact.dat",ios::binary|ios::in);
					fin.seekg(0,ios::beg);
					C[i]='\0';
					strcpy(A,C);
					while(fin.read((char*)&S,sizeof(S)))
					{
						for(int z=0;z<i;z++)
							Search_name[z]=S.name[z];
						Search_name[z]='\0';
						if(strcmpi(A,Search_name)==0)
						{
							linecount++;
							if(linecount==search_count)
							{
								general_setup("SEARCH",210,0,210,40,"------");
								settextstyle(8,0,2);
								outtextxy(20,150,"NAME     :");
								outtextxy(150,150,S.name);
								outtextxy(20,190,"MOBILE NO:");
								outtextxy(150,190,S.mobno);
								outtextxy(20,230,"EMAIL  ID:");
								outtextxy(150,230,S.id);
								break;
							}
						}
					}
					fin.close();

				}
				setcolor(4);
				outtextxy(260,435,"PRESS ANY KEY TO EXIT");
				getch();
				break;
			}
			i++;
		}

	}
	cleardevice();
}

void  contact::deletion()
{
	fstream fin("contact.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	if(!fin||fin.tellg()==0)
	{
		general_setup("DELETE",200,0,200,40,"------");
		settextstyle(8,0,2);
		setcolor(4);
		outtextxy(150,150,"NO CONTACTS YET SAVED");
		outtextxy(150,170,"PRESS ANY KEY TO EXIT");
		getch();
	}
	else
	{
		cleardevice();
		int flag=0;
		char delete_NAME[50];

		general_setup("DELETE",200,1,200,40,"-------");
		setcolor(WHITE);
		settextstyle(7,0,2);
		char T[]="ENTER THE NAME:";
		outtextxy(80,100,T);

		rectangle(300,110,520,130);
		int search_count=0;
		fin.seekg(0,ios::beg);
		char C[50] ="",Search_name[50];
		int i=0;

		int linecount=0;


		//for search results
		while(1)
		{
			char t=getch();
			cleardevice();
			setcolor(3);
			general_setup("DELETE",220,1,220,40,"------");
			setcolor(WHITE);
			settextstyle(7,0,2);
			char T[]="ENTER THE NAME:";
			outtextxy(80,100,T);
			gotoxy(40,8);
			rectangle(300,110,520,130);


				C[i] = t;
				C[i+1] = '\0';


			if(t==8)
			{
				i-=2;
				C[i+1] ='\0';
			}


			setcolor(WHITE);
			outtextxy(302,110,C);

			fin.open("contact.dat",ios::binary|ios::in);

			linecount = 0;

			while(fin.read((char*)&S,sizeof(S)))
			{
				for(int z=0;z<strlen(C);z++)
					Search_name[z]=S.name[z];
				Search_name[z]='\0';
				if(strcmpi(C,Search_name)==0)
				{
					linecount++;
					setcolor(WHITE);
					outtextxy(302,110+20*linecount,S.name);
					rectangle(300,110,520,130+20*linecount);
				}
			}
			fin.close();

			if(t==80 )
			{
				i--;
				if(search_count<linecount)
					search_count++;
				setcolor(YELLOW);
				rectangle(300,110+20*search_count,520,130+20*search_count);

				continue;
			}
			if(t==72)
			{
				i--;
				if(search_count!=0)
					search_count--;
				setcolor(YELLOW);
				rectangle(300,110+20*search_count,520,130+20*search_count);
				continue;
			}
			if(t==13)
			{

						if(search_count==0)
				{
					 C[i]='\0';
					 strcpy(delete_NAME,C);
					 break;
				}
					 else
				{

					 C[i]='\0';
					 int linecount=0;
					 fin.open("contact.dat",ios::binary|ios::in);
					 while(fin.read((char*)&S,sizeof(S)))
					{
						for(int z=0;z<i;z++)
							Search_name[z]=S.name[z];
						Search_name[z]='\0';
						if(strcmpi(C,Search_name)==0)
						{
									 linecount++;
							if(linecount==search_count)
							{
								strcpy(delete_NAME,S.name);
								 break;
							}
						}
					}
					fin.close();
				}
				break;
			}
				 i++;
			 }

		ofstream fout ("t.dat",ios::binary|ios::app);
		ofstream insertf("insert.txt");
		fin.open("contact.dat",ios::binary|ios::in);
		while(fin.read((char*)&S,sizeof(S)))
			if(strcmp(delete_NAME,S.name)!=0)
			{
				fout.write((char*)&S,sizeof(S));
			}

		if(fin.tellg()==fout.tellp())
		{
			flag=1;
		}
		fin.close();
		fout.close();
		remove("contact.dat");
		rename("t.dat","contact.dat");
		if(flag==1)
		{
			general_setup("DELETE",220,0,220,40,"------");
			settextstyle(8,0,2);
			setcolor(4);
			outtextxy(150,150,"NO CONTACT DELETED");
			outtextxy(150,190,"PRESS ANY KEY TO EXIT");
			getch();
		}
		else
		{
			general_setup("DELETE",220,0,220,40,"------");
			settextstyle(8,0,2);
			setcolor(4);
			outtextxy(155,150,"GIVEN CONTACT DELETED");
			outtextxy(155,180,"PRESS ANY KEY TO EXIT");
			delay(600);
		}

		fin.open("contact.dat",ios::binary);
		if(fin.eof())
			insertf.put('n');
		insertf.close();
		fin.close();
	}
	cleardevice();
}
char* contact:: show_NAME()
{
	return S.name;
}
char* contact:: show_fav()
{
	return S.favourite;
}
void contact:: alter_NAME(char new_NAME[80])
{
	strcpy(S.name,new_NAME);
}
void contact:: alter_MOBNO(char new_MOBNO[80])
{
	strcpy(S.mobno,new_MOBNO);
}
void contact:: alter_ID(char new_ID[80])
{
	strcpy(S.id,new_ID);
}
void contact::alter_fav(char new_fav[80])
{
	strcpy(S.favourite,new_fav);
}

void EDIT(fstream &f,contact X,char alter[80],char c,char A[80])
{
	if(c=='1')
				{
				int flag=0;
				 X.alter_NAME(alter);
				 ifstream fin("contact.dat",ios::binary);
				 ofstream fout("T.dat",ios::binary);
				 contact T;
		while(fin.read((char*)&T,sizeof(T)))
		{
			if(strcmpi(X.show_NAME(),T.show_NAME())<0&&flag==0)
			{
				flag++;
				fout.write((char*)&X,sizeof(X));
			}
			fout.write((char*)&T,sizeof(T));
		}

		fin.close();
		if(flag==0)
			fout.write((char*)&X,sizeof(X));
		fout.close();
		remove("contact.dat");
		rename("T.dat","contact.dat");

		fin.open("contact.dat",ios::binary|ios::in);
		ofstream f ("t.dat",ios::binary|ios::app);
		while(fin.read((char*)&T,sizeof(T)))
			if(strcmp(A,T.show_NAME())!=0)
			{
				f.write((char*)&T,sizeof(T));
			}

		fin.close();
		f.close();
		remove("contact.dat");
		rename("t.dat","contact.dat");
				}
	else if(c=='2')
		X.alter_MOBNO(alter);
	else if(c=='3')
		X.alter_ID(alter);
	else
		X.alter_fav(alter);
	f.seekg(int(-1*sizeof(X)),ios::cur);
	f.write((char*)&X,sizeof(X));
	f.close();
}

	void EDIT_setup()
	{
		 int flag=0;
		 fstream f("contact.dat",ios::binary|ios::in|ios::out);
		 f.seekg(0,ios::end);
		 if(!f||f.tellg()==0)
			{
			 general_setup("EDIT CONTACT",200,0,200,40,"------------");
			 outtextxy(200,40,"-----------");
			 settextstyle(8,0,2);
			 setcolor(4);
			 outtextxy(155,150,"NO CONTACTS YET SAVED");
			 outtextxy(155,170,"PRESS ANY KEY TO EXIT");
			 getch();
			 cleardevice();
			}
		 else
		 {
			f.seekg(0,ios::beg);
		 char c;
		 cleardevice();
		 contact X;
		 char A[80];
		 settextstyle(7,0,2);
		 general_setup("EDIT CONTACT",200,0,200,40,"-----------");

		 contact_DETAILS S;
		 setcolor(WHITE);
		 settextstyle(8,0,2);
		 outtextxy(80,100,"ENTER THE NAME:");
		 rectangle(300,110,520,130);
		 int search_count=0;
		 char C[50] ="",Search_name[50];
		 int i=0;
		 int linecount=0;

		//for search results
		while(1)
		{
			char t=getch();
			cleardevice();
			setcolor(3);
			general_setup("EDIT CONTACT",200,0,200,40,"-----------");
			setcolor(WHITE);
			settextstyle(7,0,2);
			char T[]="ENTER THE NAME:";
			outtextxy(80,100,T);
			gotoxy(40,8);
			rectangle(300,110,520,130);


				C[i] = t;
				C[i+1] = '\0';


			if(t==8)
			{
				i-=2;
				C[i+1] ='\0';
			}


			setcolor(WHITE);
			outtextxy(302,110,C);

			f.open("contact.dat",ios::binary|ios::in);

			linecount = 0;

			while(f.read((char*)&S,sizeof(S)))
			{
				for(int z=0;z<strlen(C);z++)
					Search_name[z]=S.name[z];
				Search_name[z]='\0';
				if(strcmpi(C,Search_name)==0)
				{
					linecount++;
					setcolor(WHITE);
					outtextxy(302,110+20*linecount,S.name);
					rectangle(300,110,520,130+20*linecount);
				}
			}
			f.close();

			if(t==80 )
			{
				i--;
				if(search_count<linecount)
					search_count++;
				setcolor(YELLOW);
				rectangle(300,110+20*search_count,520,130+20*search_count);

				continue;
			}
			if(t==72)
			{
				i--;
				if(search_count!=0)
					search_count--;
				setcolor(YELLOW);
				rectangle(300,110+20*search_count,520,130+20*search_count);
				continue;
			}
			if(t==13)
			{
					 if(search_count==0)
					 {
						 C[i]='\0';
						 strcpy(A,C);
						 break;
					 }
					 else
					 {
					C[i]='\0';
					 int linecount=0;
					 f.open("contact.dat",ios::binary|ios::in);
					 while(f.read((char*)&S,sizeof(S)))
					{
						for(int z=0;z<i;z++)
							Search_name[z]=S.name[z];
						Search_name[z]='\0';
						if(strcmpi(C,Search_name)==0)
						{
									 linecount++;
							if(linecount==search_count)
							{
								strcpy(A,S.name);
								 break;
							}
						}
					}
					f.close();
					 }
				 break;
			}
		 i++;
			 }
		 f.open("contact.dat",ios::binary|ios::in|ios::out);
		 f.seekg(0,ios::beg);
		 while(f.read((char*)&X,sizeof(X)))
			{
				if(strcmp(A,X.show_NAME())==0)
				 {
						flag=1;
						break;
				 }
			}

		 if(flag==0)
			goto H;

		 cleardevice();
		 settextstyle(7,0,2);
		 general_setup("EDIT CONTACT",200,0,200,40,"-----------");
		 settextstyle(8,0,2);
		 outtextxy(100,120,"CHOOSE THE FIELD YOU WANT TO CHANGE:");
		 outtextxy(160,140,"1.NAME");
		 outtextxy(160,160,"2.MOBILE NO");
		 outtextxy(160,180,"3.EMAIL ID");
		 Z:
		 outtextxy(100,200,"ENTER THE CHOICE:");
		 gotoxy(42,14);
		 cin>>c;
		 if(c=='1')
			{
			cleardevice();
			char new_NAME[80];
			general_setup("EDIT CONTACT",200,0,200,40,"------------");
			settextstyle(8,0,2);
			setcolor(WHITE);
			settextstyle(7,0,2);
			char T[]="ENTER THE NAME:";
			outtextxy(80,100,T);
			gotoxy(40,8);
			gets(new_NAME);
			EDIT(f,X,new_NAME,c,A);
			goto H1;
			}
		 else if(c=='2')
			{
			cleardevice();
			char new_MOBNO[80];
			general_setup("EDIT CONTACT",200,0,200,40,"-----------");
			settextstyle(8,0,2);
			outtextxy(100,80,"ENTER THE NEW MOBILE NO:");
			gotoxy(55,7);
			gets(new_MOBNO);
			EDIT(f,X,new_MOBNO,c,A);
			goto H1;
			}
			else if(c=='3')
			{
			cleardevice();
			char new_ID[80];
			general_setup("EDIT CONTACT",200,0,200,40,"-----------");
			settextstyle(8,0,2);
			outtextxy(100,80,"ENTER THE NEW EMAIL ID:");
			gotoxy(55,7);
			gets(new_ID);
			EDIT(f,X,new_ID,c,A);
			goto H1;
			}
			else
			{
			outtextxy(120,220,"TYPE AGAIN!!");
			goto Z;
			}
		 H:
		 f.close();
		 outtextxy(120,220,"NO GIVEN CONTACT FOUND");
		 outtextxy(120,240,"PRESS ANY KEY TO EXIT");
		 getch();
		 H1:
		 cleardevice();
	}
 }


void Favourite()
{
	fstream f("contact.dat",ios::binary|ios::in|ios::out);
	f.seekg(0,ios::end);
	if(!f||f.tellg()==0)
	{
		general_setup("FAVOURITES",210,0,200,40,"----------");
		settextstyle(8,0,2);
		setcolor(4);
		outtextxy(155,150,"NO CONTACTS YET SAVED");
		outtextxy(155,170,"PRESS ANY KEY TO EXIT");
		getch();
		cleardevice();
	}
	else
	{
Z:
		f.seekg(0,ios::beg);
		char c;
		int flag=0;
		cleardevice();
		contact X;
		char A[80];
		settextstyle(7,0,2);
		general_setup("FAVOURITES",200,0,200,40,"---------");
		settextstyle(8,0,2);
		outtextxy(100,120,"CHOOSE THE FOLLOWING:");
		outtextxy(160,140,"1.MARK FAVORITE");
		outtextxy(160,160,"2.UNMARK FAVOURITE");
		outtextxy(100,200,"ENTER THE CHOICE:");
		gotoxy(42,14);
		cin>>c;
		if(c=='1')
		{
			settextstyle(7,0,2);
			general_setup("MARK FAVOURITES",200,0,200,40,"--------------");
			contact_DETAILS S;
			setcolor(WHITE);
			settextstyle(8,0,2);
			outtextxy(80,100,"ENTER THE NAME:");
			rectangle(300,110,520,130);
			int search_count=0;
			char C[50] ="",Search_name[50];
			int i=0;
			int linecount=0;

		//for search results
			while(1)
			{
			char t=getch();
			cleardevice();
			setcolor(3);
			general_setup("EDIT CONTACT",200,0,200,40,"-----------");
			setcolor(WHITE);
			settextstyle(7,0,2);
			char T[]="ENTER THE NAME:";
			outtextxy(80,100,T);
			gotoxy(40,8);
			rectangle(300,110,520,130);


				C[i] = t;
				C[i+1] = '\0';


			if(t==8)
			{
				i-=2;
				C[i+1] ='\0';
			}


			setcolor(WHITE);
			outtextxy(302,110,C);

			f.open("contact.dat",ios::binary|ios::in);

			linecount = 0;

			while(f.read((char*)&S,sizeof(S)))
			{
				for(int z=0;z<strlen(C);z++)
					Search_name[z]=S.name[z];
				Search_name[z]='\0';
				if(strcmpi(C,Search_name)==0)
				{
					linecount++;
					setcolor(WHITE);
					outtextxy(302,110+20*linecount,S.name);
					rectangle(300,110,520,130+20*linecount);
				}
			}
			f.close();

			if(t==80 )
			{
				i--;
				if(search_count<linecount)
					search_count++;
				setcolor(YELLOW);
				rectangle(300,110+20*search_count,520,130+20*search_count);

				continue;
			}
			if(t==72)
			{
				i--;
				if(search_count!=0)
					search_count--;
				setcolor(YELLOW);
				rectangle(300,110+20*search_count,520,130+20*search_count);
				continue;
			}
			if(t==13)
			{
					 if(search_count==0)
					 {
						 C[i]='\0';
						 strcpy(A,C);
						 break;
					 }
					 else
					 {
					C[i]='\0';
					 int linecount=0;
					 f.open("contact.dat",ios::binary|ios::in);
					 while(f.read((char*)&S,sizeof(S)))
					{
						for(int z=0;z<i;z++)
							Search_name[z]=S.name[z];
						Search_name[z]='\0';
						if(strcmpi(C,Search_name)==0)
						{
									 linecount++;
							if(linecount==search_count)
							{
								strcpy(A,S.name);
								 break;
							}
						}
					}
					f.close();
					 }
				 break;
			}
		 i++;
		 }


			//opening file for editing
			f.open("contact.dat",ios::binary|ios::in|ios::out);

			while(f.read((char*)&X,sizeof(X)))
			{
				if(strcmp(A,X.show_NAME())==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
				goto H;
			EDIT(f,X,"favourite",'4',A);
			setcolor(2);
			outtextxy(100,170,"GIVEN CONTACT MARKED AS FAVORITE");
			delay(600);
			goto H1;
		}
		else if(c=='2')
		{
			cleardevice();
			f.seekg(0,ios::beg);
			settextstyle(7,0,2);
			general_setup("UNMARK FAVOURITES",200,0,200,40,"----------------");
			contact_DETAILS S;
			setcolor(WHITE);
			settextstyle(8,0,2);
			outtextxy(80,100,"ENTER THE NAME:");
			rectangle(300,110,520,130);
			int search_count=0;
			char C[50] ="",Search_name[50];
			int i=0;
			int linecount=0;

		//for search results
		while(1)
		{
			char t=getch();
			cleardevice();
			setcolor(3);
			general_setup("EDIT CONTACT",200,0,200,40,"-----------");
			setcolor(WHITE);
			settextstyle(7,0,2);
			char T[]="ENTER THE NAME:";
			outtextxy(80,100,T);
			gotoxy(40,8);
			rectangle(300,110,520,130);


				C[i] = t;
				C[i+1] = '\0';


			if(t==8)
			{
				i-=2;
				C[i+1] ='\0';
			}


			setcolor(WHITE);
			outtextxy(302,110,C);

			f.open("contact.dat",ios::binary|ios::in);

			linecount = 0;

			while(f.read((char*)&S,sizeof(S)))
			{
				for(int z=0;z<strlen(C);z++)
					Search_name[z]=S.name[z];
				Search_name[z]='\0';
				if(strcmpi(C,Search_name)==0)
				{
					linecount++;
					setcolor(WHITE);
					outtextxy(302,110+20*linecount,S.name);
					rectangle(300,110,520,130+20*linecount);
				}
			}
			f.close();

			if(t==80 )
			{
				i--;
				if(search_count<linecount)
					search_count++;
				setcolor(YELLOW);
				rectangle(300,110+20*search_count,520,130+20*search_count);

				continue;
			}
			if(t==72)
			{
				i--;
				if(search_count!=0)
					search_count--;
				setcolor(YELLOW);
				rectangle(300,110+20*search_count,520,130+20*search_count);
				continue;
			}
			if(t==13)
			{
					 if(search_count==0)
					 {
						 C[i]='\0';
						 strcpy(A,C);
						 break;
					 }
					 else
					 {
					C[i]='\0';
					 int linecount=0;
					 f.open("contact.dat",ios::binary|ios::in);
					 while(f.read((char*)&S,sizeof(S)))
					{
						for(int z=0;z<i;z++)
							Search_name[z]=S.name[z];
						Search_name[z]='\0';
						if(strcmpi(C,Search_name)==0)
						{
									 linecount++;
							if(linecount==search_count)
							{
								strcpy(A,S.name);
								 break;
							}
						}
					}
					f.close();
					 }
				 break;
			}
		 i++;
			 }

			f.open("contact.dat",ios::binary|ios::in|ios::out);
			while(f.read((char*)&X,sizeof(X)))
			{
				if(strcmp(A,X.show_NAME())==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
				goto H;
			EDIT(f,X,"normal",'4',A);
			goto H1;
		}
		else
		{
			outtextxy(120,220,"TYPE AGAIN!!");
			getch();
			goto Z;
		}
H:
		f.close();
		outtextxy(120,220,"NO GIVEN CONTACT FOUND");
		outtextxy(120,240,"PRESS ANY KEY TO EXIT");
		getch();
		cleardevice();
H1:
		cleardevice();
	}
}


void sortby()
{

	fstream f("contact.dat",ios::binary|ios::in|ios::out);
	f.seekg(0,ios::end);
	if(!f||f.tellg()==0)
	{
		cleardevice();
		settextstyle(8,0,2);
		setcolor(4);
		outtextxy(155,150,"NO CONTACTS YET SAVED");
		outtextxy(155,170,"PRESS ANY KEY TO EXIT");
		getch();
		cleardevice();
		f.close();
	}
	else
	{
Z:
		f.close();
		contact_DETAILS X[50],T;
		char c;

		cleardevice();
		settextstyle(7,0,4);

		general_setup("SORT BY",200,0,200,40,"-------");

		settextstyle(8,0,2);
		outtextxy(100,120,"PRESS 1 FOR DATE MODIFIED");
		outtextxy(100,140,"PRESS 2 FOR AGE");
		outtextxy(100,200,"ENTER THE CHOICE:");
		gotoxy(42,14);

		cin>>c;
		if(c=='1')
		{
			cleardevice();
			general_setup("SORT BY",200,0,200,40,"-------");
			int n=0;
			ifstream fin("contact.dat",ios::binary);
			while(fin.read((char*)&X[n],sizeof(X[n])))
			{
				n++;
			}
			fin.close();

			for(int i=0;i<n-1;i++)
				for(int j=0;j<n-1-i;j++)
				{
					if(X[j].today.da_day>X[j+1].today.da_day)
					{
						T=X[j];
						X[j]=X[j+1];
						X[j+1]=T;
					}
				}


			for(i=0;i<n-1;i++)
				for(j=0;j<n-1-i;j++)
				{
					if(X[j].today.da_mon>X[j+1].today.da_mon)
					{
						T=X[j];
						X[j]=X[j+1];
						X[j+1]=T;
					}
				}

			for(i=0;i<n-1;i++)
				for(j=0;j<n-1-i;j++)
				{
					if(X[j].today.da_year>X[j+1].today.da_year)
					{
						T=X[j];
						X[j]=X[j+1];
						X[j+1]=T;
					}
				}

			settextstyle(7,0,3);
			int linecount=0;
			for(i=0;i<n;i++)
			{
				outtextxy(100,100+20*linecount,X[i].name);
				int a=X[i].today.da_day,b=X[i].today.da_mon,c=X[i].today.da_year;
				char str1[20];
				char str2[20];
				char str3[20];
				itoa(a,str1,10);
				itoa(b,str2,10);
				itoa(c,str3,10);
				strcat(str1,"/");
				strcat(str1,str2);
				strcat(str1,"/");
				strcat(str1,str3);
				outtextxy(300,100+20*linecount,str1);
				linecount++;

			}
					getch();
		}

				 else if(c=='2')
		{
			cleardevice();
			general_setup("SORT BY",200,0,200,40,"-------");
			int n=0;
			ifstream fin("contact.dat",ios::binary);
			while(fin.read((char*)&X[n],sizeof(X[n])))
			{
				n++;
			}
			fin.close();

			for(int i=0;i<n-1;i++)
				for(int j=0;j<n-1-i;j++)
				{
					if(X[j].age<X[j+1].age)
					{
						T=X[j];
						X[j]=X[j+1];
						X[j+1]=T;
					}
				}

			settextstyle(7,0,3);
			setcolor(WHITE);
			int linecount=0;
			for(i=0;i<n;i++)
			{
				outtextxy(100,100+20*linecount,X[i].name);
				char str1[20]="AGE:";
				char str2[20];
				itoa(X[i].age,str2,10);
				strcat(str1,str2);
				outtextxy(300,100+20*linecount,str1);
				linecount++;
			}
				 getch();
		}

			 else
				 {
			outtextxy(120,220,"TYPE AGAIN!!");
			delay(400);
			goto Z;
				 }
	}

}




void designpg()
{

	contact X;
	int linecount=0;
	setcolor(WHITE);
	rectangle(10,10,625,470);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(1,0,0);
	setcolor(4);
	settextstyle(7,0,4);
	outtextxy(165,20,"PHONE BOOK");
	outtextxy(165,40,"===========");
	setcolor(5);
	settextstyle(7,0,3);
	outtextxy(470,20,"ADD NEW(+)");
	setcolor(6);
	settextstyle(8,0,2);
	outtextxy(570,420,"EXIT");
	setcolor(5);
	outtextxy(470,50,"SEARCH");
	setcolor(5);
	outtextxy(470,80,"DELETE");
	outtextxy(470,110,"EDIT");
	outtextxy(470,140,"FAVOURITES");
	outtextxy(470,170,"SORT BY");

	int poly[]={562,367,581,367,572,348,562,367};
	//up arrow
	circle(572,360,12);
	setfillstyle(SOLID_FILL,pg_colorup);
	fillpoly(3,poly);
	//down arrow
	circle(572,400,12);
	int poly1[]={562,393,581,393,572,412,562,393};
	setfillstyle(SOLID_FILL,pg_colordown);
	fillpoly(3,poly1);
	if(pg_colorup>4)
		pg_colorup=4;
	if(pg_colordown>4)
		pg_colordown=4;


	ifstream display_CONTACT("contact.dat",ios::binary);
	display_CONTACT.seekg((int)pg_check*sizeof(contact),ios::beg);
	while(display_CONTACT.read((char*)&X,sizeof(X)))
	{
		char* temp,*fav;
		temp=X.show_NAME();
		if(strcmpi(X.show_fav(),"favourite")==0)
			star(25,77+20*linecount);
		setcolor(WHITE);
		outtextxy(28,60+20*linecount,temp);
		linecount++;
	}
	display_CONTACT.close();
}



void phonebook()     ////code for phone book
{
	initgraph(&gdriver,&gmode,"..\\bgi");
	contact C;
	while(1)
	{
		i.x.ax=1;
		int86(0x33,&i,&o);
		i.x.ax=3;
		int86(0x33,&i,&o);
		mx=o.x.cx;
		my=o.x.dx;
		mc=o.x.bx;
		designpg();
		if(mx>=470&&my>=20&&my<=50&&mc==1)
		{
			mc=0;
			C.getcontact();
		}
		if(mx>=470&&my>=50&&my<=70&&mc==1)
		{
			C.search();
		}
		if(mx>=470&&my>=110&&my<=125&&mc==1)
		{
			EDIT_setup();
		}
		if(mx>=470&&my>=140&&my<=155&&mc==1)
		{
			Favourite();
		}
		if(mx>=470&&my>=170&&my<=185&&mc==1)
		{
			sortby();
			cleardevice();
		}
		if(mx>=470&&my>=80&&my<=105&&mc==1)
		{
			cleardevice();
			C.deletion();
		}
		if(mx>=562&&mx<=582&&my>=348&&my<=372&&mc==1)
		{
			if(pg_check!=0)
			{
				pg_check--;
				pg_colorup++;
			}
			cleardevice();
		}
		if(mx>=562&&mx<=582&&my>=393&&my<=413&&mc==1)
		{
			pg_check++;
			pg_colordown++;
			cleardevice();
		}

		if(mx>=570&&my>=419&&mc==1)
			break;
		delay(150);
	}
	i.x.ax=2;
	int86(0x33,&i,&o);

}



														/////CLOCK/////

void clock()
{
 int x=320,y=240,r=200,i,h,m,s,thetamin,thetasec;
 struct  time t;
 char n[12][3]={"3","2","1","12","11","10","9","8","7","6","5","4"};
 initgraph(&gdriver,&gmode,"..\\BGI");
 circle(x,y,210);
 setcolor(4);
 settextstyle(4,0,5);
 for(i=0;i<12;i++)
	{
	 if(i!=3)
	 outtextxy(x+(r-14)*cos(M_PI/6*i)-10,y-(r-14)*sin(M_PI/6*i)-26,n[i]);
	 else
	 outtextxy(x+(r-14)*cos(M_PI/6*i)-20,y-(r-14)*sin(M_PI/6*i)-26,n[i]);
	}
 gettime(&t);
 printf("The current time is:%2d:%02d:%02d.%02d",t.ti_hour, t.ti_min,t.ti_sec, t.ti_hund);
 while(!kbhit())
	{
	 setcolor(5);
	 setfillstyle(1,5);
	 circle(x,y,10);
	 floodfill(x,y,5);
	 gettime(&t);
 if(t.ti_min!=m)
 {
 setcolor(0);
 line(x,y,x+(r-60)*cos(thetamin*(M_PI/180)),y-(r-60)*sin(thetamin*(M_PI/180)));
 circle(x+(r-80)*cos(thetamin*(M_PI/180)),y-(r-80)*sin(thetamin*(M_PI/180)),10);
 line(x,y,x+(r-110)*cos(M_PI/6*h-((m/2)*(M_PI/180))),y-(r-110)*sin(M_PI/6*h-((m/2)*(M_PI/180))));
 circle(x+(r-130)*cos(M_PI/6*h-((m/2)*(M_PI/180))),y-(r-130)*sin(M_PI/6*h-((m/2)*(M_PI/180))),10);
 }
 if(t.ti_hour>12)
 t.ti_hour=t.ti_hour-12;

 if(t.ti_hour<4)
 h=abs(t.ti_hour-3);

 else
 h=15-t.ti_hour;

 m=t.ti_min;
 if(t.ti_min<=15)
 thetamin=(15-t.ti_min)*6;
 else
 thetamin=450-t.ti_min*6;
 if(t.ti_sec<=15)
 thetasec=(15-t.ti_sec)*6;
 else
 thetasec=450-t.ti_sec*6;
 setcolor(4);
line(x,y,x+(r-110)*cos(M_PI/6*h-((m/2)*(M_PI/180))),y-(r-110)*sin(M_PI/6*h-((m/2)*(M_PI/180))));
circle(x+(r-130)*cos(M_PI/6*h-((m/2)*(M_PI/180))),y-(r-130)*sin(M_PI/6*h-((m/2)*(M_PI/180))),10);
line(x,y,x+(r-60)*cos(thetamin*(M_PI/180)),y-(r-60)*sin(thetamin*(M_PI/180)));
circle(x+(r-80)*cos(thetamin*(M_PI/180)),y-(r-80)*sin(thetamin*(M_PI/180)),10);
setcolor(15);
line(x,y,x+(r-70)*cos(thetasec*(M_PI/180)),y-(r-70)*sin(thetasec*(M_PI/180)));
delay(1000);
setcolor(0);
line(x,y,x+(r-70)*cos(thetasec*(M_PI/180)),y-(r-70)*sin(thetasec*(M_PI/180)));
}

getch();
}

													/////MIND GAME/////

 struct cards
 {
	char  c;
	int flag;
 }gamebox[6][6] ;
 int c;
 void memory_game()
	{


 void box();
 void box1();
 void game(int n,int x0,int y0,int ,int,int,int  );
 void gamedesign();
 void shuffle(int n);
	initgraph(&gdriver,&gmode,"..\\bgi");


	 i.x.ax=1;
	int86(0x33,&i,&o);
	while(1)
	 {
			gamedesign();
		 i.x.ax=3;
		 int86(0x33,&i,&o);
		 mx=o.x.cx;
		 my=o.x.dx;
		 mc=o.x.bx;
		 if(mx>=250&&mx<=300&&my>=130&&my<=160&&mc==1)
			{
			 shuffle(2);
			 cleardevice();
			 closegraph();
			 game(2,150,175,165,88,480,350);
			 c=1;
			 cleardevice();
		 }
		 if(mx>=250&&mx<=300&&my>=240&&my<=270&&mc==1)
			{
			 shuffle(4);
			 cleardevice();
			 closegraph();
			 i.x.ax=2;
			 game(4,120,120,95,70,500,400);
			 c=1;
			 cleardevice();
		 }
		 if(mx>=250&&mx<=300&&my>=350&&my<=380&&mc==1)
			{
	 shuffle(6);
	 cleardevice();
	 closegraph();
	 i.x.ax=2;
	 game(6,100,100,67,50,500,400);
	 c=1;
	 cleardevice();
			}
		 if(mx>=480&&my>=430&&mc==1)
			{
	break;
			}
		 delay(100);
		}
	}


 void shuffle(int n)
	{
	int k=0;
		randomize();
		char dup[20];
		for(int i=0;i<n/2;i++)
		 for(int j=0;j<n;j++)
			{
			 gamebox[i][j].c=100+random(200-100);
			 dup[k++]=gamebox[i][j].c;
			}

			k=0;
		for(i=n/2;i<n;i++)
		 for(j=n-1;j>=0;j--)
			{
			gamebox[i][j].c=dup[k];
			k++;
			}
	}

 void box()
 {
	 rectangle(10,10,625,470);
	setfillstyle(INTERLEAVE_FILL,6);
	floodfill(1,1,WHITE);
	setfillstyle(SOLID_FILL,8);
	bar(150,175,480,350);
	setcolor(BLACK);
	//vertical line
	line(315,175,315,350);
	//horizontal line
	line(150,263,480,263);
 }

 void box1()
	{
	 rectangle(10,10,625,470);
	setfillstyle(INTERLEAVE_FILL,6);
	floodfill(1,1,WHITE);
	 setfillstyle(SOLID_FILL,8);
	 bar(120,120,500,400);
	 setcolor(BLACK);
	 //vertical lines
	 line(215,120,215,400);
	 line(310,120,310,400);
	 line(405,120,405,400);

	 //horizontal lines
	 line(120,190,500,190);
	 line(120,260,500,260);
	 line(120,330,500,330);
 }

 void box2()
 {
		rectangle(10,10,625,470);
	 setfillstyle(INTERLEAVE_FILL,6);
	 floodfill(1,1,WHITE);
	 setfillstyle(SOLID_FILL,8);
		bar(100,100,500,400);
		setcolor(BLACK);
		//vertical lines
		line(167,100,167,400);
		line(234,100,234,400);
		line(301,100,301,400);
		line(368,100,368,400);
		line(435,100,435,400);
		line(502,100,502,400);

		//horizontal lines
		line(100,150,500,150);
		line(100,200,500,200);
		line(100,250,500,250);
		line(100,300,500,300);
		line(100,350,500,350);
	}
	void gamedesign()

	{
	 rectangle(10,10,625,470);
	setfillstyle(INTERLEAVE_FILL,6);
	if(c==0)
	floodfill(1,1,WHITE);
	else
	floodfill(1,1,CYAN);
	settextstyle(10,0,4);
	setcolor(3);
	outtextxy(60,20,"MEMORY CARD GAME");
	setcolor(9);
	setbkcolor(BLACK);
	settextstyle(8,0,5);
	outtextxy(250,130,"2*2");
	outtextxy(245,150,"---");
	outtextxy(250,240,"4*4");
	outtextxy(245,260,"---");
	outtextxy(250,350,"6*6");
	outtextxy(245,370,"---");
	settextstyle(7,0,2);
	outtextxy(480,430,"EXIT");
	}



	void game(int n,int x0,int y0,int a,int b,int x1,int y1)
	 {
	 //(x0,y0)->top left pt
	 //(x1,y1)->bottom right pt
	 //(a,b)->the mid pt of each box in the boxes drawn
	 int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"..\\bgi");

	 for(int z=0;z<n;z++)
		for(int z1=0;z1<n;z1++)
		 gamebox[z][z1].flag=0;
	 int game1=-1,game2=-1;
	 int  animate=1, p; //p is no of pairs ie n^2/2
	 if(n==2)
		p=2;
	 else if(n==4)
		p=8;
	 else if(n==6)
		p=18;

		i.x.ax=1;
		int86(0x33,&i,&o);
	while(1)
	 {

		 int getx,gety;

		 i.x.ax=3;
		 int86(0x33,&i,&o);

		 mx=o.x.cx;
		 my=o.x.dx;
		 mc=o.x.bx;
		 if(animate)
			{
			if(n==2)
				box();
			else if(n==4)
				box1();
			else if(n==6)
				box2();
		 animate=0;
		 for(int l=0;l<n;l++)
			for(int k=0;k<n;k++)
			 {

	 if(gamebox[l][k].flag==1)   //one card selected
		{
		char t[2]=" ";
		t[0]=gamebox[l][k].c;
			settextstyle(8,0,1);
		setcolor(BLACK);
		outtextxy(x0+l*a+a/3,y0+k*b+b/3,t);
		}
	 if(gamebox[l][k].flag==2)      //two card selected with same character in each
		{
		 setcolor(3);
		 setfillstyle(SOLID_FILL,3);

		 floodfill(l*a+x0+a/8,k*b+y0+b/8,BLACK);
		 if(p==0)
			goto Z;
		}
			 }
		}
	 if(mx>=x0&&mx<=x1&&my>=y0&&my<=y1)
	 {

		 getx=(mx-x0)/a;
		 gety=(my-y0)/b;
		 if(mc==1)
		 {
		 animate=1;
			if(gamebox[getx][gety].flag==0)
	if(game1==(-1)&&game2==(-1))
	 {
		 game1=getx;
		 game2=gety;
		 gamebox[getx][gety].flag=1;
	 }
	 else
	 {
		 if(gamebox[getx][gety].c==gamebox[game1][game2].c)
			{
		 p--;
		 gamebox[getx][gety].flag=2;
		 gamebox[game1][game2].flag=2;
		 }
		 else
		 {
		 gamebox[getx][gety].flag=0;
		 gamebox[game1][game2].flag=0;
		 }

			game1=-1;
			game2=-1 ;
	 }
			}
	 }

	 delay(5);
	 }
	Z:
	delay(100);
	i.x.ax=2;
	cleardevice();
	settextstyle(7,0,4);
	for(int g=30;g<=100;g++)
	{
	cleardevice();
	outtextxy(180+g,200,"YOU WON");
	delay(30);
 }
 }

	void day()
 {
 initgraph(&gdriver,&gmode,"..\\bgi");
 cleardevice();
 int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 char week[7][10];
 int X=0,date,mon,year;
 strcpy(week[0],"Sunday");
 strcpy(week[1],"Monday");
 strcpy(week[2],"Tuesday");
 strcpy(week[3],"Wednesday");
 strcpy(week[4],"Thursday");
 strcpy(week[5],"Friday");
 strcpy(week[6],"Saturday");
 setcolor(4);
 settextstyle(10,0,3);
 outtextxy(155,30,"DAY CALCULATOR");
 outtextxy(155,60,"--------------");
 settextstyle(7,0,2);
 setcolor(6);
 outtextxy(20,150,"Enter the date(dd/mm/yyyy format):");
 gotoxy(60,11);
 scanf("%d / %d / %d",&date,&mon,&year);


 if((date>month[mon-1]||mon>12)&&(!(((year%400==0)||((year%4==0)&&(year%100!=0)))&&date==29&&mon==2)))
		outtextxy(150,200,"   INVALID DATE    ");
 else
 {
	if((year%400==0)||((year%4==0)&&(year%100!=0)))
	 {
		 month[1]=29;
		 X--;
	 }
	for(int i=0;i<mon-1;i++)
		X+=month[i];
	X+=(date+year+(year/4)-2);
	X%=7;
	setcolor(10);
	settextstyle(7,0,2);
	outtextxy(10,200,"The day that corresponds to the date is :");
	setcolor(11);
	outtextxy(450,200,week[X]);
 }
 getch();
}

													///BULLET///
			 //THIS CODE IS INCLUDED FROM FILE:BULLET.CPP
