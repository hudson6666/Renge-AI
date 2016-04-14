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
}
