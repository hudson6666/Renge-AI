#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include"crypt.h"
using namespace std;
class Config;
class Answerlist;
class Record;
void clearScreen();
void startupscreen();
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
            startupscreen();
            for(int i=0;i<total;i++) cout << "\n";
        }
	private:
        const char total=15;
		char rec[20][200]={{0}};
		int num=-1;
		void output(){
            clearScreen();
            startupscreen();
            if (num<total){
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
        system("cls");
    #endif
}
void screenSleep(){
    for(long long loop=0;loop<120000000;loop++);
}
void startupscreen(){
    struct tm *now;
    time_t timeNow=time(NULL);
    char tmp[6]={0};
    now=localtime(&timeNow);
    strftime(tmp,6,"%R",now);
	char s1[][4]={" _ ","   "," _ " ,  " _ ","   " ," _ "," _ "," _ "," _ "," _ ","   "};
	char s2[][4]={"| |","  |"," _|" ,  " _|","|_|", "|_ ","|_ ","  |","|_|","|_|"," . "};
	char s3[][4]={"|_|","  |","|_ ",   " _|","  |", " _|","|_|","  |","|_|"," _|"," . "};
    int a[]={tmp[0]-'0',tmp[1]-'0',10,tmp[3]-'0',tmp[4]-'0'};
    cout << "--------------------------------------------------------------------\n";
    cout << s1[a[0]] << s1[a[1]] << s1[a[2]] << s1[a[3]] << s1[a[4]] << "\n";
    cout << s2[a[0]] << s2[a[1]] << s2[a[2]] << s2[a[3]] << s2[a[4]] << "\n";
    cout << s3[a[0]] << s3[a[1]] << s3[a[2]] << s3[a[3]] << s3[a[4]];
    cout << "    莲酱0.2 by Koooyf & Catsworld & Crackpot from 208\n";
    cout << "--------------------------------------------------------------------\n";
}
