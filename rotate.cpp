#include <iostream>
#include <vector>
using namespace std;

class Rotate{
public:
	void reverse(vector<int>& nums,int begin,int end){
		if(end<=begin){
			return;
		}
		int len = (end-begin+1)/2;
		int i = 0;
		int temp;
		for(i=0;i<len;i++){
			temp = nums[i+begin];
			nums[i+begin] = nums[end-i];
			nums[end-i] = temp;
		}
	}
	void rotate(vector<int>& nums,int k){
		int mv = nums.size() - k%nums.size();
		reverse(nums,0,mv-1);
		reverse(nums,mv,nums.size()-1);
		reverse(nums,0,nums.size()-1);

	}
};
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	Rotate r;
	r.rotate(nums,5);
	vector<int>::iterator iter;
	for(iter=nums.begin();iter!=nums.end();iter++){
		cout<<*iter<<endl;
	}
	return 0;

}
