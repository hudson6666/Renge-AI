#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include"crypt.h"
using namespace std;
class Config;
class Answerlist;
class Record;
void clearScreen();
class Config{
	public:
		char name[50]={0};
		void changeName(char *newName){
			sprintf(name,"%s",newName);
			output();
		}
        void input(){
			char tmp[50]={0};
			ifstream configin("config.tze");
			configin >> tmp;
            decrypt(tmp,tmp);
            sprintf(name,"%s",tmp);
			configin.close();
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
		void output(){
		}
	private:
		char ques[1000][100]={{0}},ans[1000][100]={{0}};
		int num=-1;
		void sort(int L,int r){
		}
};
class Record{
	public:
		void add(char *newRecord){
            num++;
            sprintf(rec[num%total],"%s",newRecord);
            output();
		}
        void clear(){
            num=-1;
            for(int i=0;i<total;i++) cout << "\n";
        }
	private:
        const char total=20;
		char rec[20][200]={{0}};
		int num=-1;
		void output(){
            clearScreen();
            if (num<=total){
                for(int i=0;i<=num;i++) cout << rec[i];
                for(int i=0;i<total-num-1;i++) cout << "\n";
            }
            else{
                for(int i=num%total+1;i<total;i++) cout << rec[i];
                for(int i=0;i<=num%total;i++) cout << rec[i];
            }
		}
};
void clearScreen(){
    system("clear");
    #ifdef _WIN32
        system£¨¡°cls");
    #endif
}
