#include<high.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<dos.h>

using namepace std;
int c_name=1;
char na[100];
void name();
void start();
void created();
void option();
void ins();
void high_s();
void menu();
void proceed();


char str[3];
int p=0;
int e=0;
int snake();
void wrong();
void window();
void food1(char ,char );


char *food(char ch,int l,int &sn){
_setcursortype(_NOCURSOR);
int u,v,i,j,z;
u=77;v=22;//79 23
randomize();
if(sn==0){
gotoxy(u,v);
cout<<"*";
str[0]=u;
str[1]=v;
sn++;
}
else{
if(::p==0)
z=2;
if(::p!=0)
z=2*p+2;
a:
i=random(u);
j=random(v);
if (ch=='a'){
if((!((i==0 || i==1 || i==2 || i==3) || (j==0 || j==1 || j==2))) && (i>(l+z) || i<l)){
gotoxy(i,j);
cout<<"*";
str[0]=i;
str[1]=j;
}
else
goto a;
}
else{
if((!((i==0 || i==1 || i==2 || i==3) || (j==0 || j==1 || j==2))) && (i>l+2 || i<(l-z))){
gotoxy(i,j);
cout<<"*";
str[0]=i;
str[1]=j;
}
else
goto a;
}
}
str[2]='\0';
return str;
}
void win(){
_setcursortype(_NOCURSOR);
clrscr();
char name[100];
strcpy(name,na);
if(islower(name[0]))
name[0]=toupper(name[0]);
check_high(34,name);
gotoxy(38,1);
textattr(YELLOW+BLINK);
cprintf("WINNER");
gotoxy(30,4);
textattr(GREEN);
cprintf("Congratulations !!!");
cout<<endl<<endl;
cprintf("You Win The Game.Not More Than This Score Can Be Achieved In This Version.");
cout<<endl;
cprintf("Wait For Its Update.");
cout<<endl<<endl;
cprintf("You Can Mail Me At : ");
textattr(RED);
cprintf("Rishimishra244@gmail.com");
cout<<endl<<endl;
proceed();
}
void wrong(){
_setcursortype(_NOCURSOR);
clrscr();
if (e!=2){
gotoxy(28,12);
textattr(RED);
cprintf("Do Not Press The Wrong Key Again");
delay(1000);
e++;
snake();
}
else {
gotoxy(22,12);
textattr(RED);
cprintf("You Reached Your Limit Game Is Going To Quit");
delay(2500);
cout<<endl<<endl;
clrscr();
proceed();
}
}
int snake(){   //1
_setcursortype(_NOCURSOR);
::p=0;
int m,z,y,u,v,b,c,w,k,f,n,l,sn,ban;
m=1;z=1;y=0;u=1;v=0;b=0;c=1;w=0;k=2;n=1;l=0;sn=0;
char ar[100]="-->";
char ar1[100]="<--";
window();
gotoxy(17,12);
textattr(GREEN);
cprintf("Press Its Control Keys(W,A,S,D) To Continue The Game");
char ch;
ch=getch();
if (ch=='a'|| ch=='w'||ch=='s'||ch=='d'){  //2
int i=40;
int j=12;
clrscr();
gotoxy(22,12);
textattr(YELLOW+BLINK);
cprintf("Press It Again Your Game Is Going To Start");
window();
strcpy(str,food(ch,l,sn));
for(;ch=='a'|| ch=='w'||ch=='s'||ch=='d';){   //3
st: //
char pre;
if (ban==0){
pre=ch;
}
if(p!=34){     //4
ch=getch();
if(pre=='a'){
if(ch=='w'|| ch=='s'){  //5
clrscr();
gotoxy(31,12);
textattr(RED);
cprintf("This Is Not Valid Move");
cout<<endl;
gotoxy(20,13);
ban++;
cprintf("Move Your Snake But Do Not Use That Move Again");
cout<<endl;
textattr(GREEN);
gotoxy(26,14);
cprintf("Press Either A Or D.Better Press D");
pre='a';
goto st;
}                          //5
}                           //4
ban=0;
if(ch=='d' && c==1){
y=k+w;
w=y;
c++;
b=0;
u=1;
}
if(ch=='a' && b==0){
if(c!=1){
y=k-w;
w=y;
b++;
c=1;
u++;
}}
l=i+y;
v=l;
if(n==1){
f=v-1;}
else
f=v-2;
clrscr();
food1(str[0],str[1]);
window();
if((int)str[0]==l && (int)str[1]==j){ //4
n++;
p++;
k+=2;
gotoxy((int)str[0],(int)str[1]);
cout<<' ';
ar[z]='*';
ar[++z]='-';
ar[++z]='>';
ar1[m]='*';
ar1[++m]='-';
ar1[++m]='-';
strcpy(str,food(ch,l,sn));
if (ch=='a'){
if (u!=1){
w+=k;
y=k-w;
w-=k; }
b++;c=1;
}
if (ch=='d'||ch=='w'||ch=='s'){
y=k;
w+=2;
c++;
b=0;
}
}//4
if (ch=='a'){
i--;
if(i!=1 && i!=78 && j!=24 && j!=1){
gotoxy(i,j);
cout<<ar1;
}
else break;
}
else if(ch=='d'){
i++;
if(i!=1 && f!=78 && j!=24 && j!=1){
gotoxy(i,j);
cout<<ar;
}
else break;
}
else if(ch=='w') {
j--;
if(i!=1 && i!=78 && j!=24 && j!=1){
gotoxy(i,j);
cout<<ar;
}
else break;
}
else if(ch=='s'){
j++;
if(i!=1 && i!=78 && j!=24 && j!=1){
gotoxy(i,j);
cout<<ar;
}
else break;
}
else
wrong();
}//4
else{
win();
break;
}
}//3
return p;
}   //2
else{
wrong();
}
}      //1
void window(){
_setcursortype(_NOCURSOR);
int k;
for(k=2;k<80;k++){
gotoxy(k,1);
cout<<"-";
}
for(k=1;k<25;k++){
gotoxy(1,k);
cout<<"|";
}
for(k=1;k<25;k++){
gotoxy(80,k);
cout<<"|";
}
for(k=2;k<80;k++){
gotoxy(k,24);
cout<<"-";
}
}

void food1(char x,char y){
_setcursortype(_NOCURSOR);
gotoxy((int)x,(int)y);
cout<<"*";
}











void name(){
_setcursortype(_NORMALCURSOR);
zx:
clrscr();
gotoxy(35,12);
textattr(YELLOW+BLINK);
cprintf("WELCOME TO GAME");
gotoxy(35,15);
textattr(GREEN);
cprintf("Enter Your Name");
gotoxy(35,16);
gets(na);
if(strlen(na)<3) {
clrscr();
textattr(RED);
cprintf("Name Should Contain Atleast Three Characters");
delay(1500);
goto zx;
}
}
void proceed(){
_setcursortype(_NORMALCURSOR);
char name[100];
strcpy(name,na);
if(islower(name[0]))
name[0]=toupper(name[0]);
a:
char ch[100];
textattr(CYAN);
cprintf(name);
cprintf(" Would You Like To Go The Menu Again Or End The Game");
cout<<endl;
gets(ch);
if((strcmpi(ch,"Yes")==0)||(strcmpi(ch,"Yes")==0)||(ch[0]=='n')||(ch[0]=='y')){
if (strlen(ch)!=1){
if(strcmpi(ch,"Yes")==0)
menu();
else
exit(0);
}
else{
if(ch[0]=='y'||ch[0]=='Y')
menu();
else
exit(0);
}
}
else {
textattr(RED);
cprintf("Enter Yes Or No ");
cout<<endl;
delay(500);
clrscr();
goto a;
}
}
void menu(){
// _setcursortype(_NOCURSOR);
_setcursortype(_NORMALCURSOR);
if (::c_name==1){
name();
::c_name++;}
a:
char ch[100];
clrscr();
gotoxy(28,7);
textattr(GREEN+BLINK);
cprintf("WELCOME TO SNAKE GAME");
textattr(YELLOW);
cout<<endl<<endl<<"\t\t\t\t";
cprintf("1.Start");
cout<<endl<<"\t\t\t\t";
cprintf("2.High Score");
cout<<endl<<"\t\t\t\t";
cprintf("3.Options");
cout<<endl<<"\t\t\t\t";
cprintf("4.Instructions");
cout<<endl<<"\t\t\t\t";
cprintf("5.Created By");
cout<<endl<<"\t\t\t\t";
cprintf("6.End");
cout<<endl<<"\t\t\t\t";
gets(ch);
if (strlen(ch)!=1){
clrscr();
textattr(RED);
cprintf("Alphanumeric Entities are not allowed");
cout<<endl;
textattr(GREEN);
cprintf("Enter Numbers");
cout<<endl;
delay(1000);
proceed();
}
else  {
switch(ch[0]){
case '1':start();break;
case '2':high_s();break;
case '3':option();break;
case '4':ins(); break;
case '5':created();break;
case '6':exit(0);
default:clrscr();textattr(RED); cprintf("Enter Valid Choice");cout<<endl;cprintf("Redirecting Back To The Menu");cout<<endl;delay(1000);goto a;
}
}
}
void start(){
 _setcursortype(_NOCURSOR);
char name[100];
strcpy(name,na);
if(islower(name[0]))
name[0]=toupper(name[0]);
clrscr();
int m=snake();
clrscr();
gotoxy(38,12);
textattr(RED);
cprintf("GAME OVER");
delay(1100);
clrscr();
gotoxy(34,12);
textattr(GREEN);
cprintf("Your Score Is : ");
cout<<m<<endl<<endl;
check_high(m,name);
delay(1500);
clrscr();
proceed();
}
void high_s(){
_setcursortype(_NOCURSOR);
clrscr();
high();
gotoxy(1,16);
proceed();
}
void option(){
_setcursortype(_NOCURSOR);
clrscr();
gotoxy(33,1);
textattr(YELLOW+BLINK);
cprintf("Options");
cout<<endl<<endl;
textattr(GREEN);
cprintf("Options Will Be Available Soon In This Game In Its Next Update");
cout<<endl;
cprintf("For More Details Email Me At : ");
textattr(RED);
cprintf("Rishimishra244@gmail.com");
cout<<endl<<endl;
proceed();
}
void ins(){
_setcursortype(_NOCURSOR);
clrscr();
gotoxy(30,1);
textattr(YELLOW+BLINK);
cprintf("INSTRUCTIONS");
cout<<endl<<endl;
textattr(GREEN);
cprintf("Use W,A,S,D To Move The Snake");
cout<<endl;
cprintf("W :- To Move Snake Upward");
cout<<endl;
cprintf("S :- To Move Snake Downward");
cout<<endl;
cprintf("A :- To Move Snake Left");
cout<<endl;
cprintf("D :- To Move Snake Right");
cout<<endl<<endl;
cprintf("And Protect It From Borders Otherwise Your ");
textattr(RED);
cprintf("GAME WILL BE OVER");
cout<<endl<<endl;
cprintf("Note : ");
textattr(GREEN);
cprintf("Do Not Press W Or S Key After Pressing A Becuase It Is Regarded As An");
cout<<endl;
textattr(YELLOW);
cprintf("Invalid Move ");
textattr(GREEN);
cprintf("In this Game To Increase Its Difficulty Level!!");
cout<<endl<<endl;
proceed();
}
void created(){
_setcursortype(_NOCURSOR);
clrscr();
gotoxy(33,1);
textattr(YELLOW+BLINK);
cprintf("Created");
cout<<endl<<endl;
textattr(GREEN);
cprintf("This Game Is Created By :- ");
textattr(RED);
cprintf(" RISHI MISHRA");
cout<<endl<<endl;
proceed();
}