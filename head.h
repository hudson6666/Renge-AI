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
class RecordList;
class Answerlist;
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
class RecordList{
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
class Answerlist{
	public:
		void answer(char *question,RecordList &chatRecord){
		    bool f=0;
			for(int i=0;i<=num1;i++)
			{
				if(strcmp(question,ques[i])==0)
				{
					char tmp[1000]={0};
					sprintf(tmp,"Renge: %s\n",ans[i]);
					chatRecord.add(tmp);
					f=1;
				}
			}
			int t=strlen(question);
			if(f==0)
			{
				int max=0,where=0;
				for(int i=0;i<=num2;i++)
				{
					int sum=0,count=0;
					for(int j=0;j<strlen(ques[i]);j++)
					{
						if(count>=t) break;
						if(question[count]==ques[i][j])
							sum++;
						else if(question[count]!=ques[i][j])
							break;
						count++;
					}
					if(sum>max)
					{
						max=sum;
						where=i;
					}
				}
				char tmp[1000]={0};
			if(max!=0) sprintf(tmp,"Renge: %s\n",ans[where]);
			else if(max==0) sprintf(tmp,"Renge: 我听不懂你在瞎说个啥\n");
				chatRecord.add(tmp);
			}
		}
		void init(Config user){
			sprintf(ques[0],"你好");
			sprintf(ans[0],"%s你好",user.name);
			sprintf(ques[1],"我们玩点什么啊");
			sprintf(ans[1],"%s我们交配吧",user.name);
		   for(int i=0;;i++)
		   {
				if(strlen(ques[i])!=0) num1++;
			    else break;
		   }
		   num2=num1;
		}
		void teach(char *question,char *answer,Config user){
                num2++;
				sprintf(ques[num2],"%s",question);
				sprintf(ans[num2],"%s",answer);
		}
		void output(){
			char tmp1[1000],tmp2[1000];
			ofstream answerout("answer.tze");
			for(int i=num1+1;i<=num2;i++)
			{
				encrypt(tmp1,ques[i]);
				encrypt(tmp2,ans[i]);
                answerout<<tmp1<<"\n";
				answerout<<tmp2<<"\n";
				cout << ques[i] << " " << tmp1 << "\n";
		    }
			answerout.close();
		}
		void input(){
			char tmp1[1000],tmp2[1000];
			ifstream answerin("answer.tze");
            while(!answerin.eof())
			{
				num2=num1;
				num2++;
				answerin.getline(tmp1,1000,'\n');
				decrypt(ques[num2],tmp1);
				answerin.getline(tmp2,1000,'\n');
				decrypt(ans[num2],tmp2);
			}
			answerin.close();
		}
	private:
		char ques[1000][100]={{0}},ans[1000][100]={{0}};
		int num1=-1,num2=-1;
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
    cout << "    莲酱0.3 by Koooyf & Catsworld & Crackpot from 208\n";
    cout << "--------------------------------------------------------------------\n";
}
