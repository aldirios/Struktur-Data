// 07 - adi surya darma
// 31 - fira agustina
// 33 - fariz fahrian
// 38 - aldi rio setiawan
// 50 - maevelia azaline
#include<iostream>
using namespace std;

int array[5] = {5,2,1,8,4};
int n=sizeof(array)/sizeof(array[0]);

int caripivot(int array[],int min, int max){
	int i = min-1;
	int pivot = array[max];
	for (int j=min; j<max; j++){
		if (array[j]<=pivot){//<= untuk ascending,>= untuk descending
			i+=1;
			int temp=array[i];
			array[i]=array[j];
			array[j]=temp;//swap
		}
	}
	int temp=array[i+1];
	array[i+1]=array[max];
	array[max]=temp;//swap
	return i+1;
}

int quicksort(int array[],int min,int max){
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}//menampilkan array sebelum sorting
	cout<<endl;
	if (min<max){
		int pivot=caripivot(array,min,max);
		quicksort(array,min,pivot-1);//mengerjakan bagian kiri
		quicksort(array,pivot+1,max);//mengerjakan bagian kanan
	}
}

main(){
	cout<<"Sebelum Sorting\n";
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}//menampilkan array sebelum sorting
	
	cout<<"\n\nProses Sorting\n";
	quicksort(array,0,n-1);
	
	cout<<"\n\nSetelah Sorting\n";
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}//menampilkan array setelah sorting
	return 0;
}
