class Solution {
private:

void merge(vector<int>& nums , int s , int e){
    
    int mid = s+(e-s) /2 ;
    int len1 = mid - s+1 ;
    int len2 = e -mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int mainarrayindex= s ;


   for(int i = 0 ; i< len1 ;i++){
       first[i] = nums[mainarrayindex++];
   }
   mainarrayindex = mid +1 ;
   

   for(int i = 0 ; i< len2 ;i++){
       second[i] = nums[mainarrayindex++];
   }

   int i1 = 0 , i2 =0;
mainarrayindex= s ;

    while(i1< len1 && i2 < len2){

        if(first[i1]< second[i2]){
            nums[mainarrayindex++] = first[i1++];
        }
        else{
              nums[mainarrayindex++] = second[i2++];
        }

    }
    while(i1<len1){
         nums[mainarrayindex++] = first[i1++];
    }
    while(i2<len2){
         nums[mainarrayindex++] = second[i2++];
    }
   
}

void mergesort(vector<int>& nums , int s , int e){
    if(s>=e){
        return ;
    }

    int mid = s+ (e-s)/2 ;

    mergesort(nums, s ,mid);
    mergesort(nums,mid+1 ,e);
    
    merge(nums ,s ,e);


}

public:
    vector<int> sortArray(vector<int>& nums) {
        // we will use quick sort
        
       int n = nums.size()-1;
       mergesort(nums,0 ,n);
return nums;

    }
};