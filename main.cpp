#include"head.h"
using namespace std;
void startup();
void shutdown();
void startupfunc();
void init();
void save();
void process(char *in);
void commandExit();
void commandClear();
void commandHelp();
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
    screenSleep();
    chatRecord.add("Renge: 初、初次见面……请、请告诉我你的名字……>///<\n");
	char tmp[1000]={0};
	cin >> tmp;
	user.changeName(tmp);
    sprintf(tmp,"你：%s\n",user.name);
    chatRecord.add(tmp);
    screenSleep();
    sprintf(tmp,"Renge: %s……吗？好漂亮的名字呢=v=\n",user.name);
    chatRecord.add(tmp);
}
void startupfunc(){
    user.input();
    char tmp[1000]={0};
    screenSleep();
    sprintf(tmp,"Renge: 欢、欢迎回来……%s……\n",user.name);
    chatRecord.add(tmp);
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
    }else if(strcmp(in,"/help")==0||strcmp(in,"/?")==0){
        char tmp[1000]={0};
        cin.getline(tmp,1000,'\n');
        commandHelp();
    }else{
        char tmp[1000]={0};
        cin.getline(tmp,1000,'\n');
        commandNotFound();
    }
}
void commandExit(){
    screenSleep();
    chatRecord.add("Renge: 下、下次再见……\n");
    getchar();
    shutdown();
}
void commandClear(){
    clearScreen();
    chatRecord.clear();
}
void commandHelp(){
    screenSleep();
    chatRecord.add("Renge: 嗯……/exit可以用来退出=w=还有/clear用于清屏什么的……\n");
}
void commandNotFound(){
    screenSleep();
    chatRecord.add("Renge: ……？大概可以用/help和/?来查看帮助……\n");
}
