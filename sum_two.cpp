class Solution {
        public:
                vector<int> twoSum(vector<int>& nums, int target) {
                        map<int,vector<int> > index_map;
                        map<int,vector<int> >::iterator target_iter;
                        map<int,vector<int> >::iterator map_iter;
                        vector<int>::iterator i;
                        vector<int> ret;
                        int index = 0;
                        for(i = nums.begin(); i != nums.end(); i++) {
                                index_map[*i].push_back(index);
                                index++;
                        }
                        for (map_iter=index_map.begin();map_iter != index_map.end(); map_iter++) {
                                if(map_iter->first == (target - map_iter->first)) {
                                        if(map_iter->second.size() == 2) {
                                                return map_iter->second;
                                        }
                                }
                                int another = target - map_iter->first;
                                target_iter = index_map.find(another);
                                if(target_iter !=  index_map.end()) {
                                        int target_value = target_iter->second[0];
                                        map_iter->second.push_back(target_value);
                                        return map_iter->second;
                                }
                        }
                        ret.push_back(-1);
                        ret.push_back(-1);
                        return ret;
                }
};
