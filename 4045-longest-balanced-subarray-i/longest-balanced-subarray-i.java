class Solution {
    public int longestBalanced(int[] nums) {
        int len=0;
        for(int i=0;i<nums.length;i++){
            HashMap<Integer,Integer> odd=new HashMap<>();
            HashMap<Integer,Integer> even=new HashMap<>();
            for(int j=i;j<nums.length;j++){
                if(nums[j]%2==0){
                    even.put(nums[j],0);
                }
                else{
                    odd.put(nums[j],0);
                }
                if(odd.size()==even.size()){
                    len=Integer.max(len,j-i+1);
                }
            }
        }
        return len;
    }
}