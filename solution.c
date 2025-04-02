#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    long long top;
    long long data[5000];
}Stack;

void init(Stack* S){
    S->top = -1;
}

void push(Stack* S, long long val){
    (S->top)++;
    S->data[S->top] = val;
}

long long pop(Stack* S){
    (S->top)--;
    return S->data[(S->top)+1];
}

long long top(Stack* S){
    return S->data[S->top];
}

bool empty(Stack* S){
    return (S->top <= -1);
}

void print_opt(long long o){
    printf("%c", (char) (o+48));
}

long long convert_opt(long long o){
    return (o-48);
}

long long compute(long long a, long long b, long long o){
    if(o == -1) return a / b;
    if(o == -6) return a * b;
    if(o == -11) return a % b;
    if(o == -3) return a - b;
    if(o == -5) return a + b;
}

long long priority(long long o){
    if(o == -8) return 0;
    if(o == -3 || o == -5) return 1;
    else return 2;
}

// operator < 0
void output(Stack* res, long long o){
    if(o>=0) {
        printf("%lld", o);
        push(res, o);
    }else{
        print_opt(o);

        long long b = pop(res);
        long long a = pop(res);
        push(res, compute(a, b, o));
    }
}

void in_to_post(Stack* chg, Stack* res, char req[]){
    long long len = strlen(req);
    long long num = -1;

    for(int i=0; i<len; ++i){
        long long token = req[i];

        if(token >= 48){
            if(num==-1)
                num = token - 48;
            else
                num = num*10 + token - 48;
        }else{
            if(num!=-1) {
                output(res, num);
                num = -1;
            }

            if(token == 40){ // '('
                push(chg, convert_opt(token));
            }else if(token == 41){ // ')'
                while(!empty(chg) && top(chg)!=-8){
                    output(res, pop(chg));
                }

                pop(chg);
            }else{
                token = convert_opt(token);
                while(!empty(chg) && priority(top(chg))>=priority(token)){
                    output(res, pop(chg));
                }
                push(chg, token);
            }
        }
    }

    if(num >= 0) output(res, num);

    while(!empty(chg)){
        output(res, pop(chg));
    }
    
}

int main(){
    char req[4005];

    while(scanf("%s", req)!=EOF){
        Stack* chg = (Stack*) malloc(sizeof(Stack));
        init(chg);
        Stack* res = (Stack*) malloc(sizeof(Stack));
        init(res);

        in_to_post(chg, res, req);

        printf("=%lld\n", top(res));
    }

    return 0;
}