# include<iostream>
# include<vector>
# include<bits/stdc++.h>

int Kadan_Algo(std::vector<int> v){
	int max_sum=v[0],sum=v[0];
	for(int i=1;i<v.size();i++){
		if(sum+v[i]<0){
			sum=0;
		}
		else{
			sum+=v[i];
			if(max_sum<sum){
				max_sum=sum;
			}
		}
	}
	return max_sum;
}

int main(){
	std::vector<int> v;
	v={1,-5,8,10,5};
	std::cout<<Kadan_Algo(v);
}