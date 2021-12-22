#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TXT 1024
#define WORD 30



char c[WORD];
char a[WORD];
char atbashWord[WORD];
char reversedAtbash[WORD];
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

void p(int isPrint, int j,int i,char text[TXT]){
    if (isPrint)
    {
        printf("~");
    }
    int k = i;
    while (k <= j)
    {
        printf("%c", text[k]);
        k++;
    }
}

void gematriaSequences(char word[WORD],char text[TXT])
{
    int sum = 0;
    //past
    for(int i =0;word[i] != '\0';i++){
        sum = sum + gematria(word[i]);
    }
    //int need = sum;
    int wordGematria = sum;
    int isPrint = 0;
    //passed
    for (int i = 0;text[i] != '\0';i++)
    {
        int sum = 0;
        int j = i;
        if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
        {
            while (text[j] != '\0' && sum < wordGematria)
            {
                if (text[j] >= 97 && text[j] <= 122)
                {
                    sum += text[j] - 97 + 1;
                }
                else if (text[j] >= 65 && text[j] <= 90)
                {
                    sum += text[j] - 65 + 1;
                }
                ++j;
            }
            --j;
            if (sum == wordGematria)
            {
                p(isPrint,j,i,text);
                ++isPrint;
            }
        }

    }
}

void reverse(char from[WORD], char to[WORD]){
    int count = 0;
    int i = 0;
    while( from[i] != '\0'){
        count++;
        i++;
    }
    int j = 0;
    while( j < count){
        to[j] = from[count - j - 1];
        j++;
    }
    to[count] = '\0';
}


void ash(char word[WORD]){
    strcpy(a, word);
    int f=0;
    while(a[f] != '\0'){
        a[f] = ab(a[f]);
        f++;
    }
}
void q(int keep1,int skip,int i,int j,char text[WORD],int firstPrint){
    if(keep1){
        if(atbashWord[j - skip] == '\0'){
            if(!firstPrint){
                printf("~");
            }
            else{
                firstPrint = 0;
            }
            int g = i;
            while(g <= i + j - 1){
                printf("%c", text[g]);
                g++;
            }

            keep1 = 0;
        }
        else if(text[i + j] != atbashWord[j - skip]){
            keep1 = 0;
        }
    }

}
void h (char word[WORD], char text[WORD],int firstPrint){
    int i = 0;
    while(text[i] != '\0'){
        if(text[i] != ' '){
            int keep1 = 1,keep2 = 1,skip = 0,j = 0;
            while(keep1 || keep2){
                if(text[i + j] != ' '){
                    if(keep1){
                        if(a[j - skip] == '\0'){
                            if(!firstPrint){
                                printf("~");
                            }
                            else{
                                firstPrint = 0;
                            }
                            int g = i;
                            while(g <= i + j - 1){
                                printf("%c", text[g]);
                                g++;
                            }

                            keep1 = 0;
                        }
                        else if(text[i + j] != a[j - skip]){
                            keep1 = 0;
                        }
                    }
                    if(keep2){
                        if(reversedAtbash[j - skip] == '\0'){
                            if(!firstPrint){
                                printf("~");
                            }
                            else{
                                firstPrint = 0;
                            }
                            for(int g = i; g <= i + j - 1; g++){
                                printf("%c", text[g]);
                            }
                            keep2 = 0;
                        }
                        else if(text[i + j] != reversedAtbash[j - skip]){
                            keep2 = 0;
                        }
                    }
                }
                else{
                    skip++;
                }
                j++;
            }
        }
        i++;
    }

}
void AtbashSequences(char word[WORD], char text[TXT]){
    ash(word);
    reverse(a, reversedAtbash);
    int firstPrint = 1;
    h(word, text,firstPrint);
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
    gematriaSequences(word,text);
    printf("\n");
    printf("Atbash Sequences: ");
    AtbashSequences(word, text);
    printf("Anagram Sequences: ");
    AnagramSequences(word, text);

    return 0;
}