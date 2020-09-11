#include<iostream>
#include<string>
using namespace std;

bool pallindrome(string num)
{
    for (int i = 0; i < 7/2; i++)
    {
        if(num[i] == num[7-i]){
            return true;
        }
        else return false;
    }
    return;
}

int MakeNumber(int n1, int n2){
    int count = 0;
    if(n1 - n2 > 10)    return 0;
    int d = 0, hh = 0, mm =0, ss = 0;
    int start = n1*1000000, end = n2*1000000 + 235959;
    for(int i = start; i <= end; i++){
        if(pallindrome(to_string(i)) == true)
            count++;
    }
    return count;
}
int main(){
    int n1, n2;
    cin >> n1 >> n2;
    cout << MakeNumber(n1, n2);
    return 0;
}