#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include"head.h"
using namespace std;
void startup();
void shutdown();
void startupscreen();
void init();
Config user;
int main(){
	startup();
	shutdown();
	return 0;
}
void startup(){
	startupscreen();
	ifstream configin("config.tze");
	if(!configin) init();
	else{
	}
}
void shutdown(){
}
void init(){
	cout << "请……请告诉我你的名字……>///<：";
	char tmp[50]={0};
	cin >> tmp;
	user.changeName(tmp);
}
void startupscreen(){
	char s1[10][100]={"   "," _ " ,  " _ ","   " ," _ "," _ "," _ "," _ "," _ "," _ "};
	char s2[10][100]={"  |"," _|" ,  " _|","|_|", "|_ ","|_ ","  |","|_|","|_|","| |"};
	char s3[10][100]={"  |","|_ ",   " _|","  |", " _|","|_|","  |","|_|"," _|","|_|"};
	char s4[100]="聊天机器人0.1 by koooyf catsworld and crackpot";
 cout<<"------------------------------------------------------------------------------"<<endl;
 cout<<s1[1]<<s1[9]<<s1[7]<<endl;
 cout<<s2[1]<<s2[9]<<s2[7]<<endl;
 cout<<s3[1]<<s3[9]<<s3[7]<<"      "<<s4<<endl;
}
