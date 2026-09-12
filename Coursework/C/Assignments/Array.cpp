#include<stdio.h>
int main()
{
int arr[100],n,i,main_choice,choice,element,POS,del;
int j,temp;
int search_elem,found=0,left,right,mid;
{ //Array Creation & Display
printf("Enter the number of elements: ");
scanf("%d", &n);
printf("Enter %d elements ",n);
for(i=0;i<n;i++)
{
	scanf("%d",&arr[i]);
}
printf("Array elements are : \n");
for(i=0;i<n;i++)
{
	printf("%d ",arr[i]);
}
}
{//Main Menu
printf("\n1. Insert element in a particular position \n");
printf("2. Delete element in a particular position \n");
printf("3. Linear Search for an element \n");
printf("4. Binary Search for an element (After sorting) \n");
scanf("%d",&main_choice);
}
if(main_choice==1){//Insertion position menu //
	{ 
	printf("1. Insert at beginning \n");
	printf("2. Insert at mid \n");
	printf("3. Insert at end \n");
	scanf("%d",&choice);
	}
	{ //Element Inserted//
	printf("Enter element to insert \n");
	scanf("%d",&element);
	}
	if(choice==1)
	{
	for(i=n;i>0;i--){
		arr[i]=arr[i-1];
	}
	arr[0]=element;
	n++;
    }
    else if(choice==2)
    {
    	POS=n/2;
    	for(i=n;i>POS;i--)
    	{
    		arr[i]=arr[i-1];
		}
		arr[POS]=element;
		n++;
	}
	else if(choice==3)
	{
		arr[n]=element;
		n++;
	}
	else{printf("Invalid choice \n");
	return 0;
	}
	printf("Resulting Array after insertion: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
else if(main_choice==2){//deletion menu//
	printf("Enter the position you want to delete: ");
	scanf("%d",&del);
	if(del>=1 && del<=n)
	{
		for(i=del-1;i<n-1;i++)
		{
			arr[i]=arr[i+1];
		}
		n--;
		printf("Resulting Array after deletion: \n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
	}
	else{printf("Invalid position \n");
	}
}
else if(main_choice==3){//Linear Search
printf("\nEnter element to search: ");
scanf("%d",&search_elem);
for(i=0;i<n;i++)
{
	if(arr[i]==search_elem){
		printf("Element %d found at index %d (Position %d).\n",search_elem,i,i+1);
		found=1;
		break;
	}
}
if(found==0){
	printf("Element %d not found in the array.\n",search_elem);
 }
}
else if(main_choice==4){//Binary Search
	printf("\nSorting the array using Bubble Sort for Binary Search...\n");
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("Sorted Array is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nEnter element to search: ");
	scanf("%d",&search_elem);
	left=0;
	right=n-1;
	while(left<=right)
	{
		mid=left+(right-left)/2;
		if(arr[mid]==search_elem)
		{
			printf("Element %d found at index %d (Position %d).\n",search_elem,mid,mid+1);
			found=1;
			break;
		}
		else if(arr[mid]<search_elem){left=mid-1;}
		else{right=mid-1;}
	}
	if(found==0)
	{
		printf("Element %d not found in the array.\n",search_elem);
	}
}
else{//Invalid
	printf("Invalid menu choice \n");
	return 0;
}
printf("\n");
return 0;
}
