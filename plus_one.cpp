//考虑几个边界情况，使用reverse_iterator
class Solution {
        public:
                vector<int> plusOne(vector<int>& digits) {
                        vector<int>::reverse_iterator iter;
                        vector<int> ret;
                        for (iter = digits.rbegin();iter != digits.rend();iter ++) {
                                if (*iter==9) {
                                        ret.insert(ret.begin(), 0);
                                        continue;
                                }
                                ret.insert(ret.begin(), *iter + 1);
                                break;
                        }
                        if (iter == digits.rend()) {
                                if (*(--iter)==9) {
                                        ret.insert(ret.begin(), 1);
                                } 
                        } else {
                                iter ++;
                                for(;iter != digits.rend();iter ++){
                                        ret.insert(ret.begin(), *iter);
                                }
                        }
                        return ret;

                }
};
