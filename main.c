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


void w(char word[WORD],char text[TXT]){
    int temp = 0;
    char data;
    scanf("%c", &data);
    while(data != ' ' && data != '\n' && data != '\t'){
        word[temp] = data;
        temp++;
        scanf("%c", &data);
    }
    word[temp] = '\0';
    temp =0;
    while(temp < TXT && data != '~'){
        text[temp] = data;
        temp++;
        scanf("%c", &data);
    }
    text[temp] = '\0';
}

int gematria(char c){
    for(int i = 0 ; i < 26; i++){
        if(c == abc[i] || c == abc[i] - 32){
            return i + 1;
        }
    }
    return 0;
}




void p(int live, int a,int b,char text[TXT]){
    if (live)
    {
        printf("~");
    }
    int k = b;
    while (k <= a)
    {
        printf("%c", text[k]);
        k++;
    }
}

void Q1(char word[WORD], char text[TXT])
{

    int temp = 0;
    //past
    for(int a =0;word[a] != '\0';a++){
        temp = temp + gematria(word[a]);
    }


    //int need = sum;
    int s = temp;
    int live = 0;
    //passed

    for (int k = 0;text[k] != '\0';k++)
    {

        int temp = 0;
        int m = k;
        if ((text[k] >= 97 && text[k] <= 122) || (text[k] >= 65 && text[k] <= 90))
        {
            while (text[m] != '\0' && temp < s)
            {
                if (text[m] >= 97 && text[m] <= 122)
                {
                    temp = temp + text[m] - 97 + 1;
                }
                else if (text[m] >= 65 && text[m] <= 90)
                {
                    temp = temp + text[m] - 65 + 1;
                }
                ++m;
            }
            --m;
            if (temp == s)
            {
                p(live,m,k,text);
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


void ash(char word[WORD]){
    strcpy(a, word);
    int f=0;
    while(a[f] != '\0'){
        a[f] = ab(a[f]);
        f++;
    }
}
void q(int on,int over,int p,int g,char text[WORD],int s){
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
                printf("%c", text[g]);
                g++;
            }
            on = 0;
        }
        else if(text[p + g] != b[g - over]){
            on = 0;
        }
    }
}
void h (char word[WORD], char text[WORD],int s){
    int k = 0;
    while(text[k] != '\0'){
        if(text[k] != ' '){
            int fo = 1,f2 = 1,f3 = 0,m = 0;
            while(fo || f2){
                if(text[k + m] != ' '){
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
                                printf("%c", text[q]);
                                q++;
                            }

                            fo = 0;
                        }
                        else if(text[k + m] != a[m - f3]){
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
                                printf("%c", text[g]);
                            }
                            f2 = 0;
                        }
                        else if(text[k + m] != d[m - f3]){
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
void Q2(char word[WORD], char text[TXT]){
    ash(word);
    uno(a, d);
    int s = 1;
    h(word, text,s);
    printf("\n");

}
int e(char arr[WORD]){
    for(int l = 0; arr[l] != '\0'; l++){
        if(arr[l] != -1) return 0;
    }
    return 1;
}

void Q3(char word[WORD], char text[TXT]){
    int s = 1;
    int q = 0;
    //passed
    while(text[q] != '\0'){
        if(text[q] != ' '){
            int f0 = 1;
            //past
            strcpy(c, word);
            for(int m = q; f0 && text[m] != '\0' ; m++){
                if(text[m] != ' '){
                    //past
                    int k = -1;
                    int x = 0;
                    //passed
                    while(c[x] != '\0'){
                        if(c[x] == text[m]){
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
                        printf("%c", text[b]);

                        b++;
                    }
                    f0 = 0;
                }
            }
        }
        q++;
    }
}



void o(char word[WORD], char text[TXT]){
    int s = 1,t = 0;
    //passed
    while(text[t] != '\0'){
        if(text[t] != ' '){
            int f0 = 1;
            //past
            ash(word);
            for(int d = t; f0 && text[d] != '\0' ; d++){
                if(text[d] != ' '){
                    //past
                    int k = -1;
                    int f = 0;
                    //passed
                    while(a[f] != '\0'){
                        if(a[f] == text[d]){
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
                        printf("%c",text[g]);

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