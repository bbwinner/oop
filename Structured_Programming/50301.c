# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
 
int main(){
    char s[5005];
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int slen, nlen, status=-1;
    slen = strlen(s);
    nlen = slen;
    // printf("%s: %d\n", s, strlen(s));
    char now[5005];
    strcpy(now, s);
    for(int i=1; i<n; ++i){
        char opt[2];
        scanf("%s", opt);
        char o = opt[0];
        if(o=='+' || o=='-'){
            if(status!=-1){ //merge
                if(status){ // +
                    strcat(s, now);
                    slen += nlen;
                }else{ // -
                    if(!strcmp(&(s[slen-nlen]), &now[0])){
                        s[slen-nlen] = '\0';
                        slen -= nlen;
                    }
                }
                // printf("s: %s, %d\n", s, slen);
            }else{
                strcpy(s, now);
                slen = nlen;
            }
            scanf("%s", now);
            nlen = strlen(now);
            status = (o=='+');
        }else if(o=='*'){
            char strnum[5];
            scanf("%s", strnum);
            int num = atoi(&strnum[0]);
            char s2[5005];
            strcpy(s2, now);
            nlen *= num;
            for(int j=0; j<nlen; ++j){
                now[j]=s2[j/num];
            }
            now[nlen] = '\0';
        }else if(o=='/'){
            // char strnum[5];
            // scanf("%s", strnum);
            int num;
            scanf("%d", &num);
            // int num = atoi(&strnum[0]);
            char s2[5005];
            strcpy(s2, now);
            nlen = (nlen-1)/num +1;
            for(int j=0; j<nlen; ++j){
                now[j]=s2[j*num];
            }
            now[nlen] = '\0';
        }
        // printf("%s: %d\n", now, nlen);
 
    }
    if(status==-1){
        puts(now);
    }else if(status){ // +
        strcat(s, now);
        slen += nlen;
        puts(s);
    }else if(!status){ // -
        bool flag = 1;
        for(int j=0; j<nlen; ++j){
            if(now[j]!=s[slen-nlen+j]) flag=0;
        }
        if(flag){
            s[slen-nlen] = '\0';
            slen -= nlen;
        }
        puts(s);
    }
 
}