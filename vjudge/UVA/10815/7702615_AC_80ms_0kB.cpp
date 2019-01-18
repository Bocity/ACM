#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
string s[10000001];
long long k;
string str;
bool cmp(string x,string y)
{return x<y;}
int main()
{
	k=0;
	while (cin>>str)
	{
		for (long long i=0;i<=str.length()-1;i++)
		if (!isalpha(str[i])) str[i]=' ';
		istringstream my(str);
		while (my >> s[k])
        {
         for (long long i=0;i<=s[k].length()-1;i++)
            if (s[k][i]>='A'&&s[k][i]<='Z') s[k][i]=s[k][i]-'A'+'a';
         k++;
        }
	}
	sort(s,s+k,cmp);
	cout<<s[0]<<"\n";
	for (long long i=1;i<=k-1;i++)
	{if (s[i]!=s[i-1])cout<<s[i]<<"\n";}
	return 0;
}
