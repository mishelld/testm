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
    int x = 0;
    while(text[x] != '\0'){
        if(text[x] != ' '){
           int flagone = 1,flagt = 1,flagtr = 0,v = 0;
            while(flagone || flagt){
                if(text[x + v] != ' '){
                    if(flagone){
                        if(a[v - flagtr] == '\0'){
                            if(!s){
                                printf("~");
                            }
                            else{
                                s = 0;
                            }
                            int q = x;
                            while(q <= x + v - 1){
                                printf("%c", text[q]);
                                q++;
                            }

                            flagone = 0;
                        }
                        else if(text[x + v] != a[v - flagtr]){
                            flagone = 0;
                        }
                    }
                    if(flagt){
                        if(d[v - flagtr] == '\0'){
                            if(!s){
                                printf("~");
                            }
                            else{
                                s = 0;
                            }
                            for(int g = x; g <= x + v - 1; g++){
                                printf("%c", text[g]);
                            }
                            flagt = 0;
                        }
                        else if(text[x + v] != d[v - flagtr]){
                            flagt = 0;
                        }
                    }
                }
                else{
                    flagtr++;
                }
                v++;
            }
        }
        x++;
    }

}
void AtbashSequences(char word[WORD], char text[TXT]){
    ash(word);
    uno(a, d);
    int s = 1;
    h(word, text,s);
    printf("\n");

}
int isEmpty(char arr[WORD]){
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] != -1)return 0;
    }
    return 1;
}
void AnagramSequences(char word[WORD], char text[TXT]){
    int firstPrint = 1;
    int i = 0;
    //passed
    while(text[i] != '\0'){
        if(text[i] != ' '){
            int keep = 1;
            //past
            strcpy(c, word);
            for(int j = i; keep && text[j] != '\0' ; j++){
                if(text[j] != ' '){
                    //past
                    int k = -1;
                    int f = 0;
                    //passed
                    while(c[f] != '\0'){
                        if(c[f] == text[j]){
                            k=f;
                        }
                        f++;
                    }
                    if(k != -1){
                        c[k] = -1;
                    }
                    else{
                        keep = 0;
                    }
                }
                if(isEmpty(c)){
                    if(!firstPrint){
                        printf("~");
                    }
                    else{
                        firstPrint = 0;
                    }
                    // passed
                    int g = i;
                    while(g <= j){
                        printf("%c", text[g]);

                        g++;
                    }
                    keep = 0;
                }
            }
        }
        i++;
    }
}



void o(char word[WORD], char text[TXT]){
    int firstPrint = 1;
    int i = 0;
    //passed
    while(text[i] != '\0'){
        if(text[i] != ' '){
            int keep = 1;
            //past
            ash(word);
            for(int j = i; keep && text[j] != '\0' ; j++){
                if(text[j] != ' '){
                    //past
                    int k = -1;
                    int f = 0;
                    //passed
                    while(a[f] != '\0'){
                        if(a[f] == text[j]){
                            k=f;
                        }
                        f++;
                    }
                    if(k != -1){
                        a[k] = -1;
                    }
                    else{
                        keep = 0;
                    }
                }
                if(isEmpty(a)){
                    if(!firstPrint){
                        printf("~");
                    }
                    else{
                        firstPrint = 0;
                    }
                    // passed
                    int g = i;
                    while(g <= j){
                        printf("%c",text[g]);

                        g++;
                    }
                    keep = 0;
                }
            }
        }
        i++;
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
    AtbashSequences(word, text);
    printf("Anagram Sequences: ");
    AnagramSequences(word, text);

    return 0;
}