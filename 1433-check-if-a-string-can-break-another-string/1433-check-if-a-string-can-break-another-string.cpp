class Solution {
private:
	bool Help(vector<int> cnt1, vector<int> cnt2){
		int sum = 0;
		for (int i = 0; i < 26;++i){
			sum += cnt1[i] - cnt2[i];
			if(sum > 0)
				return false;
		}
		return true;
	}
public:
    bool checkIfCanBreak(const string& s1, const string& s2) {
		vector<int> cnt1(26, 0), cnt2(26, 0);
		for(auto c : s1)
			++cnt1[c - 'a'];
		for(auto c : s2)
			++cnt2[c - 'a'];
		return Help(cnt1, cnt2) || Help(cnt2, cnt1);
	}
};