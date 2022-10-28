#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *s;
};

void create(struct stack *st){
    st->top=-1;
    printf("Enter size:");
    scanf("%d",&st->size);
    st->s=(int*)malloc(sizeof(int)*st->size);
}

void push(struct stack *st,int x){
    if(st->top==st->size-1){
        printf("stack overflow\n");
    }
    else{
        st->top++;
        st->s[st->top]=x;
    }
}



void display(struct stack st){
    for(int i=st.top;i>=0;i--){
        printf("%d ",st.s[i]);
        printf("\n");
    }
}

int pop(struct stack *st){
    int x=-1;
    if(st->top==-1){
        return x;
    }
    else{
        x=st->s[st->top];
        st->top--;
        return x;
    }
}

int peek(struct stack st,int pos){
    if(pos<0 || pos>st.top+1){
        printf("INVALID POSIITON \n");
        return -1;
    }
    else{
        int x=st.s[st.top-pos+1];
        return x;
    }
}
int main(){
    struct stack st;
    create(&st);
    push(&st,1);
    push(&st,3);
    push(&st,9);
    push(&st,10);
    display(st);
    pop(&st);
    printf("_____________\n");
    display(st);
    int h=peek(st,2);
    printf("_____________\n");
    printf("%d \n",h);

    



return 0;

}