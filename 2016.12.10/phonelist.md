# 字母树,mle? zoj2876  
    #include <algorithm>
    #include <iostream>
    #include <iterator>
    #include <vector>
    #include <cstdio>
    #include <cstring>
    #include <string>
    #include <string.h>
    using namespace std;
    string ss;
    bool t=false;
    int n,k;
    string a[13];
        	    vector<string>s;
    bool cmp(string x,string y)
    {
    	if (x.length()==y.length()) return x<y;
    	return x.length()<y.length();
    }
    
    int main()
    {
    
    
    	while (scanf("%d",&n))
    	{
    
    	    s.clear();
    		for (int i=0;i<n;i++)
    		{
    			cin>>ss;
    			s.push_back(ss);
    		}
    		sort(s.begin(),s.end(),cmp);
    		for (vector<string>::iterator i=s.begin();i!=s.end();i++)
    		{
    		    string sss=*i;
    			if (a[sss.size()].length()==0)
                    a[sss.size()]=sss;
    		}
    		t=false;
    		for (vector<string>::iterator i=s.begin();i!=s.end();i++)
    		{
    		    string q=*i;
    		    vector<string>::iterator j=lower_bound(s.begin(),s.end(),a[q.length()]);
    			for (;j!=s.end();j++)
    			{
                    if (j!=i){
    			    string p=*j;
    				if (p.find(q,0)!=string::npos) {t=true;break;}
                    }
    			}
    			if (t) break;
    		}
    		if (t) cout<<"No\n"; else cout<<"Yes\n";
    		vector<string>().swap(s);
    	}
    	return 0;
    }
