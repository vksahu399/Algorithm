# include<iostream>
# include<vector>
# include<bits/stdc++.h>

int Binary_Search(std::vector<int> v,int target){
	int low=0,high=v.size()-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(v[mid]==target){
			return mid;
		}
		else if(v[mid]>target){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return -1;
}

int main(){
	std::vector<int> v;
	v={1,-5,8,10,5};
	int target=5;
	std::cout<<Binary_Search(v,target);
}