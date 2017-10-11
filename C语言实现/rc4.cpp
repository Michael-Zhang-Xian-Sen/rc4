#include<stdio.h>
#include<string.h>

typedef unsigned longULONG;

void rc4_init(unsigned char *sBox,unsigned char *key);
void rc4_crypt(unsigned char *sBox,unsigned char *data);

// plainText

int main(){
    char key[256],plainText[256];
    unsigned char sBox[256],sRandomBox[256];
    printf("请输入加密密钥：");
    scanf("%s",key);
    printf("请输入待加密明文：");
    scanf("%s",plainText);
    rc4_init(sBox,(unsigned char *)key);
    printf("已生成流密码。");
    for(int i=0;i<256;i++){
        sRandomBox[i] = sBox[i];
    }
    rc4_crypt(sBox,(unsigned char *)plainText);
    printf("加密后为：%s\n",plainText);

    rc4_crypt(sRandomBox,(unsigned char *)plainText);
    printf("解密后为：%s\n",plainText);
}

void rc4_init(unsigned char *sBox,unsigned char *key){
    unsigned long len = strlen((char *)key);
    char k[255] = {0};
    unsigned char tmp;
    for(int i=0;i<256;i++){
        sBox[i] = i;
        k[i] = key[i%len];
    }
    for(int j=0, i=0;i<256;i++){
        j = (j+sBox[i]+k[i])%256;
	// swap sbox[i],sbox[j];
        tmp = sBox[i];
        sBox[i] = sBox[j];
        sBox[j] = tmp;
    }
}

void rc4_crypt(unsigned char *sBox,unsigned char *data){
    unsigned long len = strlen((char *)data);
    int i = 0,j = 0,t = 0;
    unsigned char tmp;
    for(unsigned long k=0;k<len;k++){
        i = (i+1)%256;
        j = (j+sBox[i])%256;
	// swap sbox[i],sbox[j];
        tmp = sBox[i];
        sBox[i] = sBox[j];
        sBox[j] = tmp;
        t = (sBox[i]+sBox[j])%256;
        data[k] ^= sBox[t];
    }
}
