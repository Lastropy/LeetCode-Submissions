class Solution {
public:
    int poorPigs(int b, int mtd, int mtt) {
        int num_of_tests = (mtt / mtd) + 1;
        return ceil(log(b) / log(num_of_tests));
    }
};