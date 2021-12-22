
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



void Q1(char ver[WORD], char str[TXT]){
    int temp = 0;
    for(int a =0;ver[a] != '\0';a++){
        int num = 0;
        int i = 0;
        int flag = 0;
        int b = findin(ver[a]);
        if(b==1){
            b++;
        }
        while(i < 26 && flag == 0){
            if(ver[a]  == abc[i]){
                num = i + 1;
                flag = 1;
                b = 1;
            }
            else if(ver[a]  == (abc[i] - 32)){
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
    for (int k = 0;str[k] != '\0';k++){
        int temp = 0;
        int m = k;
        if ((str[k] >= 97 && str[k] <= 122)){
            while (temp < s && str[m] != '\0' ){
                int check = flow(str[k]);
                if (str[m] >= 97 && str[m] <= 122 && check >= 0){
                    temp = temp + str[m] - 97 + 1;
                }
                else if (str[m] >= 65 && str[m] <= 90 && check >= 0){
                    temp = temp + str[m] - 65 + 1;
                }
                ++m;
            }
            --m;
            if (temp == s){
                p(live,m,k,str);
                ++live;
            }
        }
        else if(str[k] >= 65 && str[k] <= 90){
            while (temp < s && str[m] != '\0'){
                int check1 = flow(str[k]);
                if (str[m] >= 97 && str[m] <= 122 && check1 >= 0){
                    temp = temp + str[m] - 97 + 1;
                }
                else if (str[m] >= 65 && str[m] <= 90 && check1 >= 0){
                    temp = temp + str[m] - 65 + 1;
                }
                ++m;
            }
            --m;
            if (temp == s){
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
    char c = 1;
    for(int i = 0 ; copied[i] != '\0' ; i++ ){
        if(c == copied[i]){
            c = 0;
        }
    }
    while( m < resu && c >= 0){
        co[m] = copied[resu - m - 1];
        m++;
    }
    co[resu] = '\0';
}



void ash(char ver[WORD]){
    strcpy(a, ver);
    int f=0;
    while(a[f] != '\0'){
        int b = flow(a[f]);
        if( b >= 0){
            a[f] = ab(a[f]);
            f++;
        }
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


int count(char ver[WORD]){
    char toreturn = 0;
    for(int i = 0 ; i < WORD ; i++ ){
        if(ver[i] == abc[i]){
            toreturn++;
        }
    }
    return toreturn;
}




void h (char ver[WORD], char str[WORD],int s){
    int k = 0;
    while(str[k] != '\0'){
        if(str[k] != ' '){
            int number = count(ver);
            int fo = 1,f2 = 1,f3 = 0,m = 0;
            while(fo || f2){
                if(str[k + m] != ' '){
                    if(fo && number >= 0){
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
                    if(f2 && number >= 0){
                        if(d[m - f3] == '\0'){
                            if(!s){
                                printf("~");
                            }
                            else{
                                s = 0;
                            }
                            for(int g = k; g <= k + m - 1; g++){
                                int flag_n = findin(str[g]);
                                if(flag_n == 1 || flag_n == 0){
                                    printf("%c", str[g]);
                                }
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
    h(ver,str,s);
}
int plz(char arr[WORD]){
    for(int h = 0; arr[h] != '\0'; h++){
        if(arr[h] != -1){return 0;}
    }
    return 1;
}


void Q3(char ver[WORD], char str[TXT]){
    /*char abc[2][26] = {{'a','b','c','d','e','f','g','j','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'}};
    */
    int b = 1;
    int r = 0;
    //passed
    int cou = 2;
    int to = 3;
    int yo =0;
    //loop
    while(str[r] != '\0'){
        /*char toreturn = '\0';
      char cc = c;
    if (c != '\0' && c!= '\t' && c != '\n' ){
        int j = 0;
        int flag = 1;
        if(65 <= c && c <= 90 ){
            flag = 0;
            cc += 32;
        }
        */
        //if
        if(str[r] != ' '){
            int f1 = 1;
            for(int i;i<1;i++){
                cou++;
                /*
                while( cc != abc[0][j] && j <= 25 ){
            j++;
        }
        if(flag == 0 ){
            toreturn = abc[1][j];
        }
        else{
            toreturn = abc[1][j];
            toreturn -= 32;
        }
}
   return toreturn; 
}
                */
                for (int y = 0; y < 1; i++)
                {
                    yo++;
                    if(yo==to){
                        to = cou +yo +to;}
                }

            }
            //past
            //copy char
            strcpy(c, ver);
            //for loop
            for(int v = r; f1 && str[v] != '\0' ; v++){
                int noth= 0;

                /*
                int findin(char c, char arr[]){
int len = sizeof(*arr);
char toreturn = 1;;
for(int i = 0 ; i < len ; i++ ){
    if(c == arr[i]){
        toreturn = 0;
    }
}
return tor
                */
                //if statement
                if(str[v] != ' '){
                    //past
                    int k = -1;
                    int f = 0;
                    //passed
                    while(c[f] != '\0'){
                        /*
                        char word[WORD];
    scanf("%29s", word);
    int count = 0;
    for(int i = 0 ; (word[i] != ' ' && word[i] != '\t' && word[i] != '\n' && word[i] != '\0'); i++){
        if((word[i] >= 65 && word[i] <= 90)||(word[i] >= 97 && word[i] <= 122)){
            count++;
        }
    }
    char new_word[count];
    int k = 0;
    for(int j =  0 ; k < count ; j++){
        if(word[j] != '\0' && word[j] != '\t' && word[j] != '\n' && word[j] != ' '){
            new_word[k] = word[j];
            k++;
        }
    }
    for(int m = 0 ; m < count ; m++){
        new_word[m] = atbash(new_word[m]);
    }
    char revers_word[count];
    for(int i = 0 ; i < count; i++){
        revers_word[i] = new_word[count - i - 1];
    }
                        */
                        if(c[f] == str[v]){
                            k=f;
                            if(k==noth){
                                noth++;
                            }
                        }
                        f++;
                    }
                    /*
                    printf("%d\n",count);
    char text[TXT];
    scanf("%1023s", text);
    printf("Atbash Sequences: ");
    char printit[20]= {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    int place = 0;
    for(int n1 = 0 ; text[n1] != '~' ; n1++){
        int ind = 1;
        int flag = 0;
        if(text[n1] == new_word[0]){
            int num = n1+1;
            int a = count;
            while( flag == 0 && a > 0){
                if(text[num++] != new_word[ind++] ){
                    flag = 1;
                }
                a--;
            }
                    */

                    if(k != -1){
                        c[k] = -1;
                        if(noth==-1){
                            noth++;
                        }
                    }
                    else{
                        f1 = 0;
                    }
                }
                /*
                printf("%d\n",flag);
            if (flag == 0 ){
                ind = 0;
                a = count;
                while( a > 0 ){
                    printit[place++]  = new_word[ind++];
                    a--;
                }
                printit[place++] = '~';
            }
        }
                */
                if(plz(c)){
                    if(!b){
                        printf("~");
                    }
                    else{
                        b = 0;
                        if(noth==b){
                            noth++;
                        }
                    }/*
                    else if(text[n1] == revers_word[0]){
            int num = n1+1;
            int a = count;
            while( flag == 0 && a > 0){
                if(text[num++] != revers_word[ind++] ){
                    flag = 1;
                }
                a--;
            }
            if (flag == 0 ){
            num = n1;
            ind = 0;
            a = count;
            while( a > 0 ){
                printit[place++]  = revers_word[ind++];
                a--;
            }
            printit[place++] = '~';
        }
        }
    }
        int len = sizeof(printit);
        for (int n = 0; n < len; n++) {     
            printf("%c", printit[n]);     
        }
        printf("\n");
}
 
int main(){
    Ashbash();
    return 0;
}
                    */
                    // passed
                    int g = r;
                    while(g <= v){
                        printf("%c", str[g]);
                        noth++;
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
    char ver[WORD];
    char str[TXT];
    w(ver,str);
    //  t(text);
    printf("Gematria Sequences: ");
    Q1(ver,str);
    printf("\n");
    printf("Atbash Sequences: ");
    Q2(ver, str);
    printf("\n");
    printf("Anagram Sequences: ");
    Q3(ver, str);

    return 0;
}