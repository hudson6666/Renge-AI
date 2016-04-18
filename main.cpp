#include"default.h"
using namespace std;
void startup();
void shutdown();
void startupfunc();
void init();
void save();
void process();
void commandExit();
void commandClear();
void commandTeach();
void commandHelp();
void commandNotFound();
void debug();
Config user;
RecordList chatRecord;
Answerlist answers;
const char password[]="catsworld";
int main(){
	startup();
	return 0;
}
void startup(){
    clearScreen();
	startupscreen();
	ifstream configin("config.tze");
	if(!configin) init();
	else startupfunc();
	answers.init();
    while(true) process();
}
void shutdown(){
    save();
	clearScreen();
    exit(0);
}
void init(){
    screenSleep();
    chatRecord.add("Renge: 初、初次见面……请、请告诉我你的名字……>///<\n",user);
	char tmp[1000]={0};
	cin.getline(tmp,1000,'\n');
	user.changeName(tmp);
    sprintf(tmp,"你：%s\n",user.name);
    chatRecord.add(tmp,user);
    screenSleep();
    sprintf(tmp,"Renge: %s……吗？好漂亮的名字呢=v=\n",user.name);
    chatRecord.add(tmp,user);
}
void startupfunc(){
    user.input();
    char tmp[1000];
    screenSleep();
    sprintf(tmp,"Renge: 欢、欢迎回来……%s……\n",user.name);
    chatRecord.add(tmp,user);
	answers.init();
}
void save(){
    answers.output();
}
void process(){
	char tmp[1000];
    cin.getline(tmp,1000,'\n');
	if(strlen(tmp)==0){
		chatRecord.output(user);
		return;
	}
	if(tmp[0]!='/'){
		char tmp2[1000];
        sprintf(tmp2,"%s: %s\n",user.name,tmp);
        chatRecord.add(tmp2,user);
        answers.answer(tmp,chatRecord,user);
    }else if(strhead(tmp,"/exit ")||strcmp(tmp,"/exit")==0) commandExit();
	else if(strhead(tmp,"/clear ")||strcmp(tmp,"/clear")==0) commandClear();
	else if(strhead(tmp,"/teach ")||strcmp(tmp,"/teach")==0) commandTeach();
    else if(strhead(tmp,"/help ")||strcmp(tmp,"/help")==0) commandHelp();
	else commandNotFound();
}
void commandExit(){
    screenSleep();
    chatRecord.add("Renge: 下、下次再见……\n",user);
	screenSleep();
	screenSleep();
    shutdown();
}
void commandClear(){
    clearScreen();
    chatRecord.clear();
}
void commandHelp(){
    screenSleep();
    chatRecord.add("Renge: 嗯……/exit可以用来退出=w=还有/clear用于清屏什么的……/teach的话就可以教窝说话啰~~\n",user);
}
void commandNotFound(){
    screenSleep();
    chatRecord.add("Renge: ……？大概可以用/help和/?来查看帮助……\n",user);
}
void commandTeach(){
	char tmp1[1000],tmp2[1000],tmp3[1000];
	chatRecord.add("Renge: 喵？要教我些什么……？\n",user);
	cin.getline(tmp1,1000,'\n');
	while(strlen(tmp1)==0){
		chatRecord.output(user);
		cin.getline(tmp1,1000,'\n');
	}
	sprintf(tmp3,"Renge: “%s”么……？我该怎么回答？\n",tmp1);
	chatRecord.add(tmp3,user);
	cin.getline(tmp2,1000,'\n');
	while(strlen(tmp2)==0){
		chatRecord.output(user);
		cin.getline(tmp2,1000,'\n');
	}
	sprintf(tmp3,"Renge: “%s”……我记住了……\n",tmp2);
	chatRecord.add(tmp3,user);
	answers.teach(tmp1,tmp2);
}
void debug(){
	char tmp[1000];
	sprintf(tmp,"%d %d\n",answers.debug1(),answers.debug2());
	chatRecord.add(tmp,user);
}
