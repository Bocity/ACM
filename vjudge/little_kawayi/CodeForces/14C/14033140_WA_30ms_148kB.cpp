#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

double dis(double x1,double x2,double y1,double y2){
	return (sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}

int main(){
	double a[4];
	double x1[4],x2[4],y1[4],y2[4];
	for(int i=0;i<4;i++){
	    cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
	    a[i]=dis(x1[i],x2[i],y1[i],y2[i]);
	}
	int f=0;
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			if(x1[i]==x1[j]&&y1[i]==y1[j]&&x2[i]==x2[j]&&y2[i]==y2[j]){
				f=1;
			}
		}
	}
	sort(a,a+3);
	if(a[1]+a[3]==a[2]+a[0]&&f==0){
		cout<<"YES"<<endl; 
	}
	else cout<<"NO"<<endl;
	return 0; 
	
}