#include<cstring>
using namespace std;
void encrypt(char *out,char *in);
void decrypt(char *out,char *in);
extern const char password[];
void encrypt(char *out,char *in){
	// Some conflicts may occur
    int t[6666]={0};
    int k=1;
    for(int i = 0; i < strlen(in); i++) {
        k = (k + 65535) % strlen(password);
    }
	printf(out,"%s",tmp);
}
void decrypt(char *out,char *in){
    char tmp[5000000000000000]={0};
    int k=0;
    for(int i=0;i<strlen(in);i++){
        tmp[i]=in[i]-password[k]+'a';
        k=(k+1)%strlen(password);
    }
	sprintf(out,"%s",tmp);
}
