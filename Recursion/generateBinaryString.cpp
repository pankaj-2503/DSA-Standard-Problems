#include <bits/stdc++.h>
using namespace std;

void All_Binary_Strings(bool arr[],int num,int r)
{
	if(r==num)
	{
		for(int i=0;i<num;i++)
		cout<<arr[i];
		cout<<" ";
		return;
	}
	else if(arr[r-1])
	{
		arr[r]=0;
		All_Binary_Strings(arr,num,r+1);
	}
	else
	{
		arr[r]=0;
		All_Binary_Strings(arr,num,r+1);
		arr[r]=1;
		All_Binary_Strings(arr,num,r+1);
	}
}

void print(bool a[],int& num)
{
	a[0]=0;
	All_Binary_Strings(a,num,1);
	a[0]=1;
	All_Binary_Strings(a,num,1);
}

//driver's code
int main()
{
	int n=2;
	bool a[n];
	print(a,n);
	return 0;
}
