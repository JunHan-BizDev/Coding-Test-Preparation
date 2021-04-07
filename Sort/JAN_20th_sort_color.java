
public class JAN_20_21_sort_color {
	    
	    public void sort(int[] nums, int start, int end)
	    {   
	        int temp = -1;
	        int current = start+1;
	        
	        while(current != end)
	        {
	            if(nums[start]  > nums[current])
	            {
	                temp = nums[start];
	                nums[start] = nums[current];
	                nums[current] = temp;
	            }
	            current++;
	        }
	    }
	    public void sortColors(int[] nums) 
	    {
	        
	        int start = 0;
	        int end = nums.length;
	        while(start != end)
	        {
	            sort(nums,start,end);
	            start++;
	        }
	        
	    }
}

