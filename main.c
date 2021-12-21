#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TXT 1024
#define WORD 30

char copy[WORD];

const int abc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 
                     's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void insertWord(char word[WORD]){
    int count = 0;
    char input;
    scanf("%c", &input);
    while(input != ' ' && input != '\n' && input != '\t'){
        word[count] = input;
        count++;
        scanf("%c", &input);
    }
    word[count] = '\0';
}

void insertText(char text[TXT]){
    int count = 0;
    char input;
    scanf("%c", &input);
    while(count < TXT && input != '~'){
        text[count] = input;
        count++;
        scanf("%c", &input);
    }
    text[count] = '\0';
}

int gematria(char c){
    for(int i = 0 ; i < 26; i++){
        if(c == abc[i] || c == abc[i] - 32){ 
            return i + 1;
        }
    }
    return 0;
}


/*void f(int firstPrint ,int need,char text[TXT]){
for(int i = 0; text[i] != '\0'; i++){
        if(gematria(text[i]) > 0){
            int sum = 0;
            int keep = 1;
          for(int j = i; keep; j++){
                sum += gematria(text[j]);
                if(sum == need){
                    if(!firstPrint){
                        printf("~");
                    }
                    else{
                        firstPrint = 0;
                    }
                    for(int g = i; g <= j; g++){
                        printf("%c", text[g]);
                    }
                }
                if(sum >= need || text[j + 1] == '\0'){
                    keep = 0;
                }
            }
        }
            
    }
}

void gematriaSequences(char word[WORD], char text[TXT]){
    int sum = 0;
    //past
    for(int i =0;word[i] != '\0';i++){
        sum += gematria(word[i]);
    }
    int need = sum;
    int firstPrint = 1;
    //past
    f(firstPrint ,need,text);
    printf("\n");
}

void p(int pr, int j,int i){
     if (pr)
                {
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c", txt[k]);
                }
}*/
/*int g(char word[WORD])
{
    int wordGematria = 0;
    int i = 0;
    while (word[i] != '\0')
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            wordGematria += word[i] - 'a' + 1;
        }
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            wordGematria += word[i] - 'A' + 1;
        }
        ++i;
    }
    return wordGematria;
}
void p(int pr, int j,int i,char text[TXT]){
     if (pr)
                {
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c", text[k]);
                }
}
void gematriaSequences(char word[WORD],char text[TXT])
{
     int wordGematria = g(word);
    int pr = 0;
    for (int w = 0;text[w] != '\0';w++)
    {
        int u = 0;
        int l = w;
        if (isalpha(text[w]))
        {
            while (text[l] != '\0' && u < wordGematria)
            { //lower case
               if (text[l] >= 97 && text[l] <= 122)
                {
                    u = u +  text[l] - 97 + 1;
                }
                //upper case
                else if (isupper(text[l]))
                {
                    u = u + text[l] - 65 + 1;
                }
               ++l;
            }
            --l;
            //print the sequances we fuond as equal gimatrcli
            if (u == wordGematria)
            {
                p(pr,l,w,text);
                ++pr;
            }
        }
        
    }
}*/

void p(int isPrint, int j,int i,char text[TXT]){
      if (isPrint)
                {
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c", text[k]);
                }
}

void gematriaSequences(char word[WORD],char text[TXT])
{
    int sum = 0;
    //past
    for(int i =0;word[i] != '\0';i++){
        sum += gematria(word[i]);
    }
    //int need = sum;
    int wordGematria = sum;
    int isPrint = 0;
    int i = 0;
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
    for(int i = 0; from[i] != '\0'; i++){
        count++;
    }
    for(int j = 0; j < count; j++){
        to[j] = from[count - j - 1];
    }
    to[count] = '\0';
}

void atbash(char from[WORD], char to[WORD]){
    int i = 0;
    for(int j = 0; from[j] != '\0'; j++){
        int place = gematria(from[j]) - 1;
        if(abc[place] != from[j]){
            to[j] = abc[26 - 1 - place] - 32;
        }else{
            to[j] = abc[26 - 1 - place];
        }
        i++;
    }
    to[i] = '\0';
}

void AtbashSequences(char word[WORD], char text[TXT]){
    char atbashWord[WORD];
    atbash(word, atbashWord);
    char reversedAtbash[WORD];
    reverse(atbashWord, reversedAtbash);
    int firstPrint = 1;
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] != ' '){
            int keep1 = 1;
            int keep2 = 1;
            int skip = 0;
            for(int j = 0; keep1 || keep2; j++){
                if(text[i + j] != ' '){
                    if(keep1){
                        if(atbashWord[j - skip] == '\0'){
                            if(!firstPrint){
                                printf("~");
                            }
                            else{
                                firstPrint = 0;
                            }
                            for(int g = i; g <= i + j - 1; g++){
                                printf("%c", text[g]);
                            }
                            keep1 = 0;
                        }
                        else if(text[i + j] != atbashWord[j - skip]){
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
            }
        }
    }
    printf("\n");

}



int isEmpty(char arr[WORD]){
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] != -1)return 0;
    }
    return 1;
}
/*void h(int firstPrint ,int i,int j,int keep,char text[TXT]){
    if(isEmpty(copy)){
                    if(!firstPrint){
                        printf("~");
                    }
                    else{
                        firstPrint = 0;
                    }
                    for(int g = i; g <= j; g++){
                        printf("%c", text[g]);
                    }
                    keep = 0;
                }
}*/

void AnagramSequences(char word[WORD], char text[TXT]){
    int firstPrint = 1;
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] != ' '){
            int keep = 1;
            //past
            strcpy(copy, word);
            for(int j = i; keep && text[j] != '\0' ; j++){
                if(text[j] != ' '){
                    //past
                    int k = -1;
                    int f = 0;
                    while(copy[f] != '\0'){
                    if(copy[f] == text[j]){
                     k=f;
                    }
                    f++;
                    }
                    if(k != -1){
                        copy[k] = -1;
                    }
                    else{
                        keep = 0;
                    }
                }
                if(isEmpty(copy)){
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
    }
}

int main(){
    char word[WORD];
    char text[TXT];
    insertWord(word);
    insertText(text);
    printf("Gematria Sequences: ");
    gematriaSequences(word,text);
    printf("\n");
    printf("Atbash Sequences: ");
    AtbashSequences(word, text);
    printf("Anagram Sequences: ");
    AnagramSequences(word, text);
    return 0;
}