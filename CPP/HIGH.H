#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<dos.h>

void window2();
void write();
void high();
void check_high(int,char qw[100]);
int pk=0;

void check_Empty (){
char ch;
ofstream m("High.dat",ios::app||ios::binary);
fstream f("High.dat",ios::binary||ios::in||ios::out);
while(!f.eof()){
f.get(ch);
::pk++;
}
if (::pk==1){
write();
}
f.close();
}
struct info{
char name[100];
int point;
};
void write(){
info t;
ofstream g("High.dat",ios::binary);
t.point=34;
strcpy(t.name,"Peter Gilbert");
g.write((char*)&t,sizeof(t));
t.point=10;
strcpy(t.name,"John Snow");
g.write((char*)&t,sizeof(t));
t.point=0;
strcpy(t.name,"Ramsay Bolton");
g.write((char*)&t,sizeof(t));
}
void high(){
clrscr();
window2();
info t;
//char ch;
textattr(YELLOW+BLINK);
gotoxy(38,1);
cprintf("HIGH SCORE");
gotoxy(4,3);
textattr(RED);
cprintf("Name");
gotoxy(72,3);
cprintf("Points");
textattr(GREEN);
ofstream m("High.dat",ios::app||ios::binary);
check_Empty();
fstream h("High.dat",ios::binary|ios::in);
int j=6;
char name[100];
while(h.read((char*)&t,sizeof(t))){
gotoxy(4,j);
strcpy(name,t.name);
cprintf(name);
gotoxy(75,j);
cout<<t.point;
j+=2;
}
m.close();
h.close();
}
void check_high(int n,char ch[100]){
info t;
int cv=0;
char tempc[100];
int temp;
char name[100];
check_Empty();
fstream f("High.dat",ios::in|ios::out|ios::binary);
while(f.read((char*)&t,sizeof(t))){
if(n>=t.point){
if (cv==0){
temp=n;
n=t.point;
t.point=temp;
if(strcmpi(t.name,ch)==0){
cv++;
}
else{
strcpy(tempc,ch);
strcpy(ch,t.name);
strcpy(t.name,tempc);
}
}
f.seekp(f.tellg()-sizeof(t));
f.write((char*)&t,sizeof(t));
}
}
f.close();
}
void window2(){
int k;
for(k=2;k<80;k++){
gotoxy(k,2);
cout<<"-";
}
for(k=1;k<14;k++){
gotoxy(1,k);
cout<<"|";
}
for(k=1;k<14;k++){
gotoxy(80,k);
cout<<"|";
}
for(k=2;k<80;k++){
gotoxy(k,13);
cout<<"-";
}
for(k=2;k<80;k++){
gotoxy(k,4);
cout<<"-";
}
for(k=3;k<13;k++){
gotoxy(40,k);
cout<<"|";
}
for(k=1;k<=80;k++){
gotoxy(k,14);
cout<<"-";
}
}