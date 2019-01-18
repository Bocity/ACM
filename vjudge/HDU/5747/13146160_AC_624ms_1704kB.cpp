/* ***********************************************
Author        :Bocity
Created Time  :2018年03月20日 星期二 20时53分07秒
File Name     :A.cpp
************************************************ */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   	int t;
	int n,m;
	int tmp = 0;
	cin >> t;
	while(t--){
		tmp = 0;
		cin >> n  >> m;
		int sum1 = 0;
		int mm = m;
		int sum2 = 0;
		int nn = n;
		while (nn > 0){
			sum2 ++;
			nn >>= 1;
		}
		int ans = 0;
		if (m >= sum2){
			nn = n;
			while (nn >0){
				ans += nn&1;
				nn >>=1;
			}
			cout << ans << endl;
		}else{
			m = mm;
			mm = 1;
			for(int i = 0 ; i < m; ++i ){
				mm <<= 1;
			}
			int tt = n / mm;
			n -= tt * mm;
			while (n > 0){
				ans += n & 1;
				n >>= 1;
			}
			//cout << ans << " " << sum1 << " " << tt << endl;
			cout << ans+ tt  << endl; 
		}
	}
    return 0;
}


