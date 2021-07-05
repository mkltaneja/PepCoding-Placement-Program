#include<iostream>
#include<vector>
using namespace std;

void encodings(int i, string ans, string &s)
{
    if(i == s.size())
    {
        cout<<ans<<endl;
        return;
    }
    if(s[i] == '0')
        return;
    
    encodings(i+1, ans+ (char)(s[i]-'1'+'a'), s);
    if(i < s.size() - 1 && ((s[i]-'0')*10 + (s[i+1]-'0')) <= 26)
        encodings(i+2, ans+(char)(((s[i]-'0')*10 + (s[i+1]-'0')) - 1 + 'a'), s);
}

int main()
{
    string s;
    cin>>s;
    encodings(0, "", s);
}