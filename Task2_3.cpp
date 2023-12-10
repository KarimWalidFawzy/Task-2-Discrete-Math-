#include <iostream>
using namespace std;
class signals{
    public:
        char* name;
        bool value;
        char namecorrespondingtovalue(void);
        signals(char* q);
        void printvalchar();
        char getvalchar();
        void notvalue();
    private:
     char valchar;
};/**The signals class is meant to represent the value of all signals*/
void signals::printvalchar(){
    if (value)
     valchar='T';
    else
     valchar='F';
    if((valchar=='T' && value)|(valchar=='F' && ~value))
    cout<< valchar;
}
void signals::notvalue(){
    value= (value)^1;
}
char signals::getvalchar(){
    if(value)
    valchar='T';
    else
    valchar='F';
    return valchar;
}
signals::signals(char* q)
{
    name=q;
    valchar='X';
}
void AND(signals& X, signals& Y,signals& out){
    out.value=(X.value&Y.value);
}
void OR(signals& X, signals& Y,signals& out){
    out.value=(X.value|Y.value);
}
void printstring(char* x){
    char y[15];
    for(int i=0;*(x+i)!='\0';i++){
        y[i]= *(x+i);
        cout<<y[i];
    }
    cout<<endl;
}
int main(void){
    signals A("A");
    signals B("B");
    signals C("C");
    signals BC("(B&C)");
    signals BorC("(B|C)");
    signals AandB("(A&B)");
    signals AornB("(A|~B)");
    signals Output("Output");
    signals ander("(B|C)&B&C");
    signals v("");
    A.value=true;
    B.value=true;
    C.value=true;
    char p[15];
    cout<<"Our logical circuit describes the boolean function (A&B)|(A&~B)|((B|C)&B&C)"<<endl;
    cout<<"A"<<'\t'<<"B"<<'\t'<<"C"<<"\tB&C"<<"\tB|C"<<'\t'<<"A&B"<<"\t(A|~B)"<<"\tOutput"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                    *(p)=(A.getvalchar());
                    *(p+1)='\t';
                    *(p+2)=B.getvalchar();
                    *(p+3)='\t';
                    *(p+4)=C.getvalchar();
                    *(p+5)='\t';
                    AND(B,C,BC);
                    *(p+6)=BC.getvalchar();
                    *(p+7)='\t';
                    OR(B,C,BorC);
                    AND(BC,BorC,ander);
                    *(p+8)=BorC.getvalchar();
                    *(p+9)='\t';
                    AND(A,B,AandB);
                    *(p+10)=AandB.getvalchar();
                    *(p+11)='\t';
                    OR(A,B,AornB);
                    *(p+12)=AornB.getvalchar();
                    *(p+13)='\t';
                    OR(ander,AornB,v);
                    OR(v,AandB,Output);
                    *(p+14)=Output.getvalchar();
                    *(p+15)='\0';
                    printstring(p);
                    A.notvalue();
                    }
        B.notvalue();
        }
        C.notvalue();
    }
    cout<<"\n"<<"An equivalent statement can be made which will have the exact same truth table is (A|B)"<<endl;
    cout<<"A"<<'\t'<<"B"<<'\t'<<"C"<<"\tA|B"<<endl;
    char al[8];
    A.value=true;
    B.value=true;
    C.value=true;
    signals AorB("A|B");
    for(int alpha=0;alpha<2;alpha++){
        for(int beta=0;beta<2;beta++){
            for(int gamma=0;gamma<2;gamma++){
                    *(al)=(A.getvalchar());
                    *(al+1)='\t';
                    *(al+2)=B.getvalchar();
                    *(al+3)='\t';
                    *(al+4)=C.getvalchar();
                    *(al+5)='\t';
                    OR(A,B,AorB);
                    *(al+6)=AorB.getvalchar();
                    *(al+7)='\0';
                    printstring(al);
                    A.notvalue();
                    }
        B.notvalue();
        }
        C.notvalue();
    }
    cout<< "\n since the last column in both tables are identical, I can safely say that both statements \n are logically equivalent"<<endl;
    return 0;
}
