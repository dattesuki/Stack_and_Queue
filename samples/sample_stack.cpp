// Тестирование стека

#include <iostream>
#include "stack_queue.h"

using namespace std;

//---------------------------------------------------------------------------
bool IsOpenBracket(char t){
    if (t=='(' or t=='[' or t=='{') return 1;
    return 0;
}

bool IsCloseBracket(char t){
    if (t==')' or t==']' or t=='}') return 1;
    return 0;
}

char GetOpenBracket(char t){
    if (t==')') return '(';
    if (t==']') return '[';
    if (t=='}') return '{';
    return 0;
}

int main(int argc, const char * argv[]) {
    string Expression;
    cin>>Expression;
    Stack<char> stack;
    int flag=0;
    
    for(int i=0;i<Expression.length();i++){
        if (IsOpenBracket(Expression[i])){
            stack.push_back(Expression[i]);
        }
        if(IsCloseBracket(Expression[i])){
            if (stack.IsEmpty()) flag++;
            else{
                if (stack.back()!=GetOpenBracket(Expression[i]))flag++;
                else{
                    if (stack.IsEmpty() == 0) (stack.pop_back());
                    else flag++;
                }}}}
          
    if(stack.IsEmpty()!=1) flag++;
    if (flag==0) cout<<"\nВсе хорошо!";
    else cout<<"\nГде-то ошибка(";
    return 0;
}
//---------------------------------------------------------------------------
