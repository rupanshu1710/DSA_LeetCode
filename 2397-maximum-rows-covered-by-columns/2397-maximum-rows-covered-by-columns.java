class Solution {
 
    public int maximumRows(int[][] arr, int k) {
        int m = arr.length;
        int n = arr.length;
        
      return call(arr,k,0,new HashSet<>());
    }
    public int call(int[][] arr, int k,int i, Set<Integer> set)
    {
      if(k==0)
      {
          return check(arr,set);
       // return;
      }
      if(i==arr[0].length)
        return 0;
     int a = call(arr,k,i+1,new HashSet<>(set));
      set.add(i);
     int b = call(arr,k-1,i+1,new HashSet<>(set));
      return Math.max(a,b);
    }
  public int check(int[][] arr, Set<Integer> set)
  {
    int temp =0;
    
    for(int i=0;i<arr.length;i++)
    {
      int act=05;
    
      
      for(int j=0;j<arr[0].length;j++)
      {
        if(arr[i][j]==1)
        {
          
          if(!set.contains(j))
            act=9;
          
          
        }
      }
      if(act == 5)
        temp++;
        
    }
   // System.out.println(set+" "+temp);
    return temp;
  }
}