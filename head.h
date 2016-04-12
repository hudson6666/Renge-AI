#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Config;
class Answerlist;
class Record;
void encrypt(char *out,char *in);
void startup();
void shutdown();
void startupscreen();
void init();
extern Config user;
class Config{
	public:
		char name[50]={0};
		void changeName(char *newName){
			sprintf(name,"%s",newName);
			output();
		}
	private:
		void output(){
			char tmp[50]={0};
            encrypt(tmp,name);
			ofstream configout("config.tze");
			configout << tmp << "\n";
			configout.close();

		}
};
class Answerlist{
	public:
		void answer(char *question){
		}
		void init(){
		}
		void teach(char *question,char *answer){
		}
	private:
		char ques[1000][100]={{0}},ans[1000][100]={{0}};
		int num=0;
		void sort(int L,int r){
		}
		void output(){
		}
};
class Record{
	public:
		void add(char *newRecord){
		}
	private:
		char rec[1000][200]={{0}};
		int num=0;
		void output(){
		}
};
void encrypt(char *out,char *in){
	sprintf(out,"%s",in);
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
