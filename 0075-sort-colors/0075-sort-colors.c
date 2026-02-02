void sortColors(int* nums, int numsSize) {
    int count1=0,count2=0,count3=0;
    int j=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0){
            count1++;
        }
        if(nums[i]==1){
            count2++;
        }
        if(nums[i]==2){
            count3++;
        }
    }
    while(count1>0){

        nums[j]=0;
        j++;
        count1--;
    }
    while(count2>0){
        nums[j]=1;
        j++;
        count2--;
    }
    while(count3>0){
        nums[j]=2;
        j++;
        count3--;
    }
}