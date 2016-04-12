#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Config;
class Answerlist;
class Record;
void encrypt(wchar_t *out,wchar_t *in);
void startup();
void shutdown();
void startupscreen();
void init();
extern Config user;
class Config{
	public:
		wchar_t name[50]={0};
		void changeName(wchar_t *newName){
			sprintf(name,"%s",newName);
			output();
		}
	private:
		void output(){
			wchar_t tmp[50]={0};
            encrypt(tmp,name);
			ofstream configout("config.tze");
			configout << tmp << "\n";
			configout.close();

		}
};
class Answerlist{
	public:
		void answer(wchar_t *question){
		}
		void init(){
		}
		void teach(wchar_t *question,wchar_t *answer){
		}
	private:
		wchar_t ques[1000][100]={{0}},ans[1000][100]={{0}};
		int num=0;
		void sort(int L,int r){
		}
		void output(){
		}
};
class Record{
	public:
		void add(wchar_t *newRecord){
		}
	private:
		wchar_t rec[1000][200]={{0}};
		int num=0;
		void output(){
		}
};
void encrypt(wchar_t *out,wchar_t *in){
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
	wchar_t tmp[50]={0};
	cin >> tmp;
	user.changeName(tmp);
}
void startupscreen(){
}
