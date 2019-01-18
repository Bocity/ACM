#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
string s[100000];
int k;
string str;
bool cmp(string x,string y)
{return x<y;}
int main()
{
	k=0;
	while (getline(cin,str))
	{
		for (int i=0;i<=str.length()-1;i++)
		if (!isalpha(str[i])) str[i]=' ';
		istringstream my(str);
		while (my >> s[k])
		k++;
	}
	sort(s,s+k,cmp);
	cout<<s[0]<<"\n";
	for (int i=1;i<=k-1;i++)
	{if (s[i]!=s[i-1])cout<<s[i]<<"\n";}
	return 0;
}
