#include <stdio.h>

#define ElementType int

typedef struct{
    ElementType Data;
    int Parent;
}SetType;

int Find( SetType S[], ElementType X);
void Union(SetType S[], ElementType X1, ElementType X2);

int main(){
    int N;
    scanf("%d", &N);
    SetType S[N];
    for(int i=0; i<N; ++i){
        S[i].Data = i+1;
        S[i].Parent = -1;
    }
    while(1){
        char op;
        ElementType c1, c2;
        scanf(" %c", &op);
        if(op=='S'){
            int cnt = 0;
            for(int i=0; i<N; ++i){
                if(S[i].Parent<0) ++cnt;
            }
            if(cnt>1) printf("There are %d components.\n", cnt);
            else printf("The network is connected.\n");
            break;
        }
        scanf("%d %d", &c1, &c2);
        if(op=='C'){
            if(Find(S, c1) == Find(S, c2)) printf("yes\n");
            else printf("no\n");
        }else if(op=='I'){
            Union(S, c1, c2);
        }
    }
    return 0;
}

int Find( SetType S[], ElementType X){
//  int i;
//  for(i=0; i<N && S[i].Data!=X; ++i);
    int i = X-1;
    for( ; S[i].Parent>=0; i=S[i].Parent);
    return i;
}

void Union(SetType S[], ElementType X1, ElementType X2){
    int Root1, Root2;
    Root1 = Find(S, X1);
    Root2 = Find(S, X2);
//  S[Root2].Parent = Root1;
    if(S[Root1].Parent<S[Root2].Parent){
        S[Root1].Parent += S[Root2].Parent;
        S[Root2].Parent = Root1;
    }
    else{
        S[Root2].Parent += S[Root1].Parent;
        S[Root1].Parent = Root2;
    }
}
