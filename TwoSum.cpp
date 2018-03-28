class Solution {
public:
    void merge_array(vector<int>&nums, int start, int mid, int end, vector<int> &temp){

	int left = start,right = mid+1,count = start;
	while(count <= end){
		// cout << "left is "<< left << "right is " << right << endl;
		if(nums[left]<= nums[right]){
			if(left <= mid){
				temp[count] = nums[left];
				left++;

			}else{
				temp[count] = nums[right];
				right++;
			}
		}else{
			if(right <= end){
				temp[count] = nums[right];
				right++;
			}else{
				temp[count] = nums[left];
				left++;				
			}
		}
		count++;
	}
	// for(int i = start; i<= end;i++){
	// 	nums[i] = temp[i];
	// }

}



void merge_sort(vector<int>&nums, int start, int end, vector<int> &temp){

	if(start == end){
		return;
	}

	int mid = (start+end)/2;
	if(mid != start){
		merge_sort(nums,start,mid,temp);
		merge_sort(nums,mid+1,end,temp);
	}
	merge_array(nums,start,mid,end,temp);
}
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<int> ordered_nums;
        for(int i = 0; i < nums.size();i++){
            ordered_nums.push_back(nums[i]);
        }
        merge_sort(nums,0,nums.size()-1,ordered_nums);
        
        
        
        int left = 0,right = ordered_nums.size()-1;
        for(int i = 0; i < ordered_nums.size();i++){
            temp.push_back(target-ordered_nums.at(i));
        }
        while(left<=right){
            if(ordered_nums.at(left) == temp.at(right)){
                break;
            }else{
                if(ordered_nums.at(left)>=temp.at(right)){
                    right--;
                }else{
                    left++;
                }
            }
        }
        
        for(int i = 0; i< nums.size();i++){
            if(nums[i] == ordered_nums[left]){
                left = i;
            }
            if(nums[i] == ordered_nums[right]){
                right = i;
            }
        }
        
        vector<int> result;
        if(left!=right){
            result.push_back(left<=right?left:right);
            result.push_back(right<=left?left:right);
        }else{
            result.push_back(left<=right?left:right);
            result.push_back(left<=right?left:right);
            
        }
         
        // result.push_back(left<right?left:right);
        // result.push_back(left<right?right:left);
        return result;
        
    }
};