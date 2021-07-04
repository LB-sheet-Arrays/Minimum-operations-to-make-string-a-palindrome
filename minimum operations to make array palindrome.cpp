//we have permission to use only merge operator
//merge means to replace the element by the sum with adjacent element

//Corner elements must be same in palindrome

#include<iostream>                       
#include<cstdlib>       //to dynamically allocate memory

using namespace std;

int main()
{
	int *a,n;
	
	cout<<"\t\t\nHow many elements do you want? => ";
	cin>>n;
	
	//corner cases:
	if(n<0)
	{
		cout<<"\nSize can't be negative!";
	}
	else if(n==0)
	{
		return 0;
	}
	else
	{
		//allocating array dynamically
		a=(int*)malloc(n*sizeof(int));
	
		//feeding the array 
		for(int i=0;i<n;i++)
		{
			cout<<"\n\nElement no "<<i+1<<" ";
			cin>>a[i];
		}
		
		//using 2 pointer approach: check for corner similar elements or else merge
		int left=0;         //left corner pointer
		int right=n-1;     //right corner pointer
		
		int answer=0;     //apna answer
		
		while(left<=right)
		{
			//corner elements are equal, tab koi dikkat nhi. continue further
			if(a[left]==a[right])
			{
				left++;
				right--;
			}
			else if(a[left]>a[right])
			{
				//right wale ko merge karo and then evaluate with left, so i didn't incremented left here
				//right me merge kiya to ek element kam hoga
				right--;
				a[right]=a[right]+a[right+1];
				answer++;
			}
			else if(a[left]<a[right])
			{
				//left wale ko merge karo and then evaluate with right, so i didn't decremented right here
				left++;
				a[left]=a[left]+a[left-1];
				answer++;
			}
		}
		
		cout<<"\nMinimum number of operations to be performed => "<<answer;
			
	}
			
return 0;
}
