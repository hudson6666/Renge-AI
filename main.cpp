#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include"head.h"
using namespace std;
void startup();
void shutdown();
void startupfunc();
void startupscreen();
void init();
void save();
void process(char *in);
void commandExit();
void commandClear();
void commandNotFound();
Config user;
Record chatRecord;
Answerlist answers;
const char password[]="catsworld";
int main(){
    atexit(commandExit);
	startup();
	return 0;
}
void startup(){
    clearScreen();
	startupscreen();
	ifstream configin("config.tze");
	if(!configin) init();
	else startupfunc();
    while(true){
        char content[1000]={0};
        cin >> content;
        process(content);
    }
}
void shutdown(){
    clearScreen();
    save();
    exit(0);
}
void init(){
    chatRecord.add("Renge: 初、初次见面……请、请告诉我你的名字……>///<");
	char tmp[1000]={0};
	cin >> tmp;
	user.changeName(tmp);
    sprintf(tmp,"%s\n",user.name);
    chatRecord.add(tmp);
    sprintf(tmp,"Renge: %s……吗？好漂亮的名字呢=v=\n",user.name);
    chatRecord.add(tmp);
}
void startupfunc(){
    user.input();
    char tmp[1000]={0};
    sprintf(tmp,"Renge: 欢、欢迎回来……%s……\n",user.name);
    chatRecord.add(tmp);
}
void startupscreen(){
	char s1[][4]={" _ ","   "," _ " ,  " _ ","   " ," _ "," _ "," _ "," _ "," _ "};
	char s2[][4]={"| |","  |"," _|" ,  " _|","|_|", "|_ ","|_ ","  |","|_|","|_|"};
	char s3[][4]={"|_|","  |","|_ ",   " _|","  |", " _|","|_|","  |","|_|"," _|"};
	char s4[]="聊天机器人0.2 by koooyf & catsworld & crackpot";
    chatRecord.add("--------------------------------------------------------------\n");
    char tmp[1000]={0};
    sprintf(tmp,"%s%s%s\n",s1[2],s1[0],s1[8]);
    chatRecord.add(tmp);
    sprintf(tmp,"%s%s%s\n",s2[2],s2[0],s2[8]);
    chatRecord.add(tmp);
    sprintf(tmp,"%s%s%s      %s\n",s3[2],s3[0],s3[8],s4);
    chatRecord.add(tmp);
    chatRecord.add("--------------------------------------------------------------\n");
}
void save(){
    answers.output();
}
void process(char *in){
    if(in[0]!='/'){
        char tmp[1000]={0};
        cin.getline(tmp,1000,'\n');
        strcat(in,tmp);
        sprintf(tmp,"%s: %s\n",user.name,in);
        chatRecord.add(tmp);
        answers.answer(in);
    }else if(strcmp(in,"/exit")==0){
        char tmp[1000]={0};
        cin.getline(tmp,1000,'\n');
        exit(0);
    }else if(strcmp(in,"/clear")==0){
        char tmp[1000]={0};
        cin.getline(tmp,1000,'\n');
        commandClear();
    }else{
        char tmp[1000]={0};
        cin.getline(tmp,1000,'\n');
        commandNotFound();
    }
}
void commandExit(){
    chatRecord.add("Renge: 下、下次再见……\n");
    getchar();
    shutdown();
}
void commandClear(){
    clearScreen();
    chatRecord.clear();
}
void commandNotFound(){
    chatRecord.add("Renge: ……？\n");
}
