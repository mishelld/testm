#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TXT 1024
#define WORD 30



char c[WORD];
char a[WORD];
char b[WORD];
char d[WORD];
const int abc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                     's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


const int abd[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i',
                     'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

int ab(char c){
    for(int i=0;i<26;i++){
        if(c==abc[i]){
            return abd[i];
        }
    }

    return -1;


}


void w(char ver[WORD],char str[TXT]){
    int temp = 0;
    char data;
    scanf("%c", &data);
    while(data != ' ' && data != '\n' && data != '\t'){
        ver[temp] = data;
        temp++;
        scanf("%c", &data);
    }
    ver[temp] = '\0';
    temp =0;
    while(temp < TXT && data != '~'){
        str[temp] = data;
        temp++;
        scanf("%c", &data);
    }
    str[temp] = '\0';
}

int gematria(char c){
    for(int i = 0 ; i < 26; i++){
        if(c == abc[i] || c == abc[i] - 32){
            return i + 1;
        }
    }
    return 0;
}


void p(int live, int a,int b,char str[TXT]){
    if (live)
    {
        printf("~");
    }
    int k = b;
    while (k <= a)
    {
        printf("%c", str[k]);
        k++;
    }
}

void Q1(char ver[WORD], char str[TXT])
{

    int temp = 0;
    //past
    for(int a =0;ver[a] != '\0';a++){
        temp = temp + gematria(ver[a]);
    }


    //int need = sum;
    int s = temp;
    int live = 0;
    //passed

    for (int k = 0;str[k] != '\0';k++)
    {

        int temp = 0;
        int m = k;
        if ((str[k] >= 97 && str[k] <= 122) || (str[k] >= 65 && str[k] <= 90))
        {
            while (str[m] != '\0' && temp < s)
            {
                if (str[m] >= 97 && str[m] <= 122)
                {
                    temp = temp + str[m] - 97 + 1;
                }
                else if (str[m] >= 65 && str[m] <= 90)
                {
                    temp = temp + str[m] - 65 + 1;
                }
                ++m;
            }
            --m;
            if (temp == s)
            {
                p(live,m,k,str);
                ++live;
            }
        }

    }
}






void uno(char copied[WORD], char co[WORD]){
    int resu = 0,n = 0, m = 0;;
    while( copied[n] != '\0'){
        resu++;
        n++;
    }
    while( m < resu){
        co[m] = copied[resu - m - 1];
        m++;
    }
    co[resu] = '\0';
}


void ash(char ver[WORD]){
    strcpy(a, ver);
    int f=0;
    while(a[f] != '\0'){
        a[f] = ab(a[f]);
        f++;
    }
}
void q(int on,int over,int p,int g,char str[WORD],int s){
    if(on){
        if(b[g - over] == '\0'){
            if(!s){
                printf("~");
            }
            else{
                s = 0;
            }
            int g = p;
            while(g <= p + g - 1){
                printf("%c", str[g]);
                g++;
            }
            on = 0;
        }
        else if(str[p + g] != b[g - over]){
            on = 0;
        }
    }
}


void h (char ver[WORD], char str[WORD],int s){
    int k = 0;
    while(str[k] != '\0'){
        if(str[k] != ' '){
            int fo = 1,f2 = 1,f3 = 0,m = 0;
            while(fo || f2){
                if(str[k + m] != ' '){
                    if(fo){
                        if(a[m - f3] == '\0'){
                            if(!s){
                                printf("~");
                            }
                            else{
                                s = 0;
                            }
                            int q = k;
                            while(q <= k + m - 1){
                                printf("%c", str[q]);
                                q++;
                            }

                            fo = 0;
                        }
                        else if(str[k + m] != a[m - f3]){
                            fo = 0;
                        }
                    }
                    if(f2){
                        if(d[m - f3] == '\0'){
                            if(!s){
                                printf("~");
                            }
                            else{
                                s = 0;
                            }
                            for(int g = k; g <= k + m - 1; g++){
                                printf("%c", str[g]);
                            }
                            f2 = 0;
                        }
                        else if(str[k + m] != d[m - f3]){
                            f2 = 0;
                        }
                    }
                }
                else{
                    f3++;
                }
                m++;
            }
        }
        k++;
    }
    
}
void Q2(char ver[WORD], char str[TXT]){
    ash(ver);
    uno(a, d);
    int s = 1;
    h(ver, str,s);
    printf("\n");
}

int e(char arr[WORD]){
    for(int l = 0; arr[l] != '\0'; l++){
        if(arr[l] != -1) return 0;
    }
    return 1;
}

void Q3(char ver[WORD], char str[TXT]){
    int s = 1;
    int q = 0;
    //passed
    while(ver[q] != '\0'){
        if(ver[q] != ' '){
            int f0 = 1;
            //past
            strcpy(c, ver);
            for(int m = q; f0 && ver[m] != '\0' ; m++){
                if(ver[m] != ' '){
                    //past
                    int k = -1;
                    int x = 0;
                    //passed
                    while(c[x] != '\0'){
                        if(c[x] == ver[m]){
                            k=x;
                        }
                        x++;
                    }
                    if(k != -1){
                        c[k] = -1;
                    }
                    else{
                        f0 = 0;
                    }
                }
                if(e(c)){
                    if(!s){
                        printf("~");
                    }
                    else{
                        s = 0;
                    }
                    // passed
                    int b = q;
                    while(b <= m){
                        printf("%c", ver[b]);

                        b++;
                    }
                    f0 = 0;
                }
            }
        }
        q++;
    }
}

void o(char ver[WORD], char str[TXT]){
    int s = 1;
    int t = 0;
    //passed
    while(str[t] != '\0'){
        if(str[t] != ' '){
            int f0 = 1;
            //past
            ash(ver);
            for(int d = t; f0 && str[d] != '\0' ; d++){
                if(str[d] != ' '){
                    //past
                    int k = -1;
                    int f = 0;
                    //passed
                    while(a[f] != '\0'){
                        if(a[f] == str[d]){
                            k=f;
                        }
                        f++;
                    }
                    if(k != -1){
                        a[k] = -1;
                    }
                    else{
                        f0 = 0;
                    }
                }
                if(e(a)){
                    if(!s){
                        printf("~");
                    }
                    else{
                        s = 0;
                    }
                    // passed
                    int g = t;
                    while(g <= d){
                        printf("%c",str[g]);

                        g++;
                    }
                    f0 = 0;
                }
            }
        }
        t++;
    }

}




int main(){
    char word[WORD];
    char text[TXT];
    w(word,text);
    //  t(text);
    printf("Gematria Sequences: ");
    Q1(word,text);
    printf("\n");
    printf("Atbash Sequences: ");
    Q2(word, text);
    printf("Anagram Sequences: ");
    Q3(word, text);

    return 0;
}