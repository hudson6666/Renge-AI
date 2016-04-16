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
void inName(char *out,char *in,Config user);
bool strhead(char *full,char *sub);
class Config{
	public:
		char name[50];
		void changeName(char *newName){
			sprintf(name,"%s",newName);
			output();
		}
        void input(){
			char tmp[50];
			ifstream configin("config.tze");
			configin >> tmp;
            decrypt(tmp,tmp);
            sprintf(name,"%s",tmp);
			configin.close();
        }
	private:
		void output(){
			char tmp[50];
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
	private:
		const int total=15;
		char rec[20][200];
		int num=-1;
};
class Answerlist{
	public:
		void answer(char *question,RecordList &chatRecord){
			for(int i=0;i<=num2;i++)
			{
				if(strcmp(question,ques[i])==0)
				{
					char tmp[1000];
					sprintf(tmp,"Renge: %s\n",ans[i]);
					chatRecord.add(tmp);
					return;
				}
			}
			int t=strlen(question);
				int max=0,where=0;
				for(int i=0;i<=num2;i++)
				{
					int sum=0,count=0;
					/*for(int j=0;j<strlen(ques[i]);j++)
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
					}*/
					if(strstr(question,ques[i])!=NULL){
						if(strlen(ques[i])>max){
							max=strlen(ques[i]);
							where=i;
						}
					}
				}
				char tmp[1000];
			if(max!=0) sprintf(tmp,"Renge: %s\n",ans[where]);
			else if(max==0) sprintf(tmp,"Renge: ……嗯？\n");
				chatRecord.add(tmp);
		}
		void init(){
			defaultList();
			num2=num1;
			input();
		}
		void initadd(char *question,char *answer){
			num1++;
			sprintf(ques[num1],"%s",question);
			sprintf(ans[num1],"%s",answer);
		}
		void teach(char *question,char *answer){
			if(strlen(question)==0||strlen(answer)==0) return;
            num2++;
			sprintf(ques[num2],"%s",question);
			sprintf(ans[num2],"%s",answer);
		}
		void output(){
			char tmp[1000];
			ofstream answerout("answer.tze");
			for(int i=num1+1;i<num2;i++)
			{
				if(strlen(ques[i])==0||strlen(ans[i])==0) continue;
				encrypt(tmp,ques[i]);
                answerout << tmp << "\n";
				encrypt(tmp,ans[i]);
				answerout << tmp << "\n";
		    }
			if(num1<num2){
				encrypt(tmp,ques[num2]);
				answerout << tmp << "\n";
				encrypt(tmp,ans[num2]);
				answerout << tmp;
			}
			answerout.close();
		}
		void input(){
			char tmp[1000];
			ifstream answerin("answer.tze");
			if(!answerin) return;
            while(!answerin.eof())
			{
				answerin.getline(tmp,1000,'\n');
				if(strlen(tmp)==0) continue;
				if(answerin.eof()) break;
				num2++;
				decrypt(ques[num2],tmp);
				answerin.getline(tmp,1000,'\n');
				decrypt(ans[num2],tmp);
			}
			answerin.close();
		}
		int debug1(){
			return num1;
		}
		int debug2(){
			return num2;
		}
	private:
		char ques[1000][100],ans[1000][100];
		int num1=-1,num2;
		void defaultList();
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
void inName(char *in,char *out,Config user)
{
	int t=strlen(user.name);
	int p=strlen(out);
	int i;
	for(i=0;out[i]!='\n';i++)
	{
		if(out[i]=='%'&&out[i+1]=='n')
		{
			int tot=0;
			for(int j=i;j<=i+t-1;j++)
			{
				in[j]=user.name[tot];
				tot++;
			}
			 i=i+t-1;	
		}
		else
		{
			in[i]=out[i];
		}
	}
	in[i]='\n';
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
    cout << "    莲酱1.0 by Koooyf & Catsworld & Crackpot from 208\n";
    cout << "--------------------------------------------------------------------\n";
}
bool strhead(char *full,char *sub){
	if(strstr(full,sub)==full) return true;
	return false;
}
