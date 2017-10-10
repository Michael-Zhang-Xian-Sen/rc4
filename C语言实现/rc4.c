#include<stdio.h>
#include<string.h>

int main(){
    char key[256],plain_text[256];
    printf("请输入加密密钥：");
    scanf("%s",key);
    printf("请输入待加密明文：");
    scanf("%s",plain_text);
}

void rc4_init(char *sBox,char *key){
    int len = strlen(key);
    char k[255] = {0};
    char tmp = 0;
    for(int i=0;i<256;i++){
        sBox[i] = i;
        k[i] = key[i%len];
    }
    for(int j=0, i=0;i<256;i++){
        j = (j+sBox[i]+k[i])%256;
        tmp = sBox[i];
        sBox[i] = sBox[j];
        sBox[j] = tmp;
    }
}

void rc4_crypt(char *sBox,char *data){
    int len = strlen(data);
    int i = 0,j = 0,tmp = 0,t = 0;
    for(int k=0;k<len;k++){
        i = (i+1)%256;
        j = (j+sBox[i])%256;
        tmp = sBox[i];
        sBox[i] = sBox[j];
        sBox[j] = tmp;
        t = (sBox[i]+sBox[j])%256;
        data^=sBox[t];
    }
}
