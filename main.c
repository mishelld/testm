
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

int findin(char c){
    int len = sizeof(abc);
    char toreturn = 1;
    for(int i = 0 ; i < len ; i++ ){
        if(c == abc[i]){
         toreturn = 0;
    }
}
return toreturn;
}

int flow(char c){
    int len = sizeof(abc);
    char toreturn = 0;
    for(int i = 0 ; i < len ; i++ ){
        if(c == abc[i]){
         toreturn++;
    }
}
return toreturn;
}

void Q1(char word[WORD], char text[TXT]){
    int temp = 0;
    for(int a =0;word[a] != '\0';a++){
        int num = 0;
        int i = 0;
        int flag = 0;
        int b = findin(word[a]);
        while(i < 26 && flag == 0){
            if(word[a]  == abc[i]){
                num = i + 1;
                flag = 1;
                b = 1;
            }
            else if(word[a]  == (abc[i] - 32)){
                num = i + 1;
                flag = 1;
                b = 1;
            }
            i++;
        }
        temp = temp + num;
    }
    int s = temp;
    int live = 0;
    for (int k = 0;text[k] != '\0';k++){
        int temp = 0;
        int m = k;
        if ((text[k] >= 97 && text[k] <= 122)){
            while (temp < s && text[m] != '\0' ){
                int check = flow(text[k]);
                if (text[m] >= 97 && text[m] <= 122 && check >= 0){
                    temp = temp + text[m] - 97 + 1;
                }
                else if (text[m] >= 65 && text[m] <= 90 && check >= 0){
                    temp = temp + text[m] - 65 + 1;
                }
                ++m;
            }
            --m;
            if (temp == s){
                p(live,m,k,text);
                ++live;
            }
        }
        else if(text[k] >= 65 && text[k] <= 90){
            while (temp < s && text[m] != '\0'){
                int check1 = flow(text[k]);
                if (text[m] >= 97 && text[m] <= 122 && check1 >= 0){
                    temp = temp + text[m] - 97 + 1;
                }
                else if (text[m] >= 65 && text[m] <= 90 && check1 >= 0){
                    temp = temp + text[m] - 65 + 1;
                }
                ++m;
            }
            --m;
            if (temp == s){
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
int plz(char arr[WORD]){
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] != -1)return 0;
    }
    return 1;
}
void AnagramSequences(char word[WORD], char text[TXT]){
    int b = 1;
    int r = 0;
    //passed
    while(text[r] != '\0'){
        if(text[r] != ' '){
            int f1 = 1;
            //past
            strcpy(c, word);
            for(int v = r; f1 && text[v] != '\0' ; v++){
                if(text[v] != ' '){
                    //past
                    int k = -1;
                    int f = 0;
                    //passed
                    while(c[f] != '\0'){
                        if(c[f] == text[v]){
                            k=f;
                        }
                        f++;
                    }
                    if(k != -1){
                        c[k] = -1;
                    }
                    else{
                        f1 = 0;
                    }
                }
                if(plz(c)){
                    if(!b){
                        printf("~");
                    }
                    else{
                        b = 0;
                    }
                    // passed
                    int g = r;
                    while(g <= v){
                        printf("%c", text[g]);

                        g++;
                    }
                    f1 = 0;
                }
            }
        }
        r++;
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
    AnagramSequences(word, text);

    return 0;
}