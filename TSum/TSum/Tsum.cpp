#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class FindT {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> nummap;
		int i = nums.size();
		while (i--) {//这种方法忽略了两项完全相同的数字
			nummap[nums.at(i)] = i;
		}
		//be careful ! after all these ops , i will be -1!
		i++;

		for (; i < nums.size(); i++) {
			int the = nums.at(i);
			int yu = target - the;
			int num = 0;
			if (nummap.find(yu) != nummap.end() && nummap[yu]!=i) {
				num = nummap[yu];
				vector<int>v;
				v.push_back(i);
				v.push_back(num);
				return v;
			}	
		}
	}
};
int main() {
	vector<int>v;
	int tmp;
	cin >> tmp;
	while (tmp) {
		v.push_back(tmp);
		cin >> tmp;
	}
	cout << "cin done" << endl;
	int target = v[v.size()-1];
	v.pop_back();
	FindT f;
	vector<int>res=f.twoSum(v, target);
	cout << res.at(0) << endl << res.at(1) << endl;
}