#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define int long long

typedef struct{
    int top;
    int data[5000];
}Stack;

Stack chg, res;

/*
( : 40 -> -1
) : 41 -> -2
* : 42 -> -4
/ : 47 -> -5
% : 37 -> -6
+ : 43 -> -9
- : 45 -> -10
num >= 48
*/

void init(Stack* S){
    S->top = -1;
}

void push(Stack* S, long long val){
    (S->top)++;
    S->data[S->top] = val;
}

int pop(Stack* S){
    (S->top)--;
    return S->data[(S->top)+1];
}

int top(Stack* S){
    return S->data[S->top];
}

bool empty(Stack* S){
    return (S->top<=-1);
}

void print_opt(int o){
    if(o==-10) putchar('-');
    else if(o==-9) putchar('+');
    else if(o==-6) putchar('%');
    else if(o==-5) putchar('/');
    else if(o==-4) putchar('*');
}

int convert(int o){
    if(o==42) return -4;
    if(o==47) return -5;
    if(o==37) return -6;
    if(o==43) return -9;
    if(o==45) return -10;
}

int compute(int a, int b, int o){
    if(o==-10) return a-b;
    if(o==-9) return a+b;
    if(o==-6) return a%b;
    if(o==-5) return a/b;
    if(o==-4) return a*b;
}

int pri(int o){
    if(o>-3) return 0;
    if(o>-8) return 2;
    return 1;
}

// operator < 0
void output(int o){
    if(o>=0) {
        printf("%lld", o);
        push(&res, o);
    }else{
        print_opt(o);
        int b = pop(&res);
        int a = pop(&res);
        push(&res, compute(a, b, o));
    }
}

void in_to_post(char req[]){
    int len = strlen(req);
    long long num=-1;
    for(int i=0; i<len; ++i){
        long long opt = req[i];
        if(opt >= 48){
            if(num==-1) num = opt-48;
            else num = num*10 + opt-48;
        }else{
            if(num!=-1) {output(num); num=-1;}
            if(opt == 40){
                push(&chg, -1);
            }else if(opt == 41){
                while(!empty(&chg) && top(&chg)!=-1){
                    output(pop(&chg));
                }
                pop(&chg);
            }else{
                opt = convert(opt);
                while(!empty(&chg) && pri(top(&chg))>=pri(opt)){
                    output(pop(&chg));
                }
                push(&chg, opt);
            }
        }
    }
    if(num>=0) output(num);
    while(!empty(&chg)){
        output(pop(&chg));
    }
    
}

signed main(){
    char req[4005];
    int temp;
    while(scanf("%s", req)!=EOF){
        init(&chg); init(&res);
        in_to_post(req);
        printf("=%lld\n", top(&res));
    }
}