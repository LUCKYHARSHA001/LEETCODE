void merge(int *A,int l,int m,int h)
{
    int i=l,j=m+1,k=0;
    int result[h-l+1];
    while(i<=m&&j<=h)
    {
        if(A[i]<=A[j])
        {
            result[k]=A[i];
            i++;
            k++;
        }
        else{
            result[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        result[k]=A[i];
        i++;
        k++;
    }
    while(j<=h)
    {
        result[k]=A[j];
        j++;
        k++;
    }
    k=0;
    for(i=l;i<=h;i++)
    {
        A[i]=result[k];
        k++;
    }
}
void sort(int *A,int l,int h)
{
    if(l<h){
        int m=(l+h)/2;
        sort(A,l,m);
        sort(A,m+1,h);
        merge(A,l,m,h);
    }
}
int maximumProduct(int* nums, int numsSize) {
    sort(nums,0,numsSize-1);
    int ans1=(nums[numsSize-1])*(nums[numsSize-2])*(nums[numsSize-3]);
    int ans2=(nums[numsSize-1])*(nums[0])*(nums[1]);
    if(ans1>ans2)
    {
        return ans1;
    }
    return ans2;
}