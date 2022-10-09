// 07 - adi surya darma
// 31 - fira agustina
// 33 - fariz fahrian
// 38 - aldi rio setiawan
// 50 - maevelia azaline
#include<iostream>
using namespace std;

int array[8]={12,34,54,2,30,5,2,48};
int n=sizeof(array)/sizeof(array[0]);

int shellsort(int array[]){
	int fase=1;
	int gap=int(n/2/fase);
	while (gap>0){//proses sorting
		for(int i=0;i<n;i++){
			cout<<array[i]<<" ";
		}//menampilkan proses
		cout<<endl;
		for(int i=gap;i<n;i++){
			int temp=array[i];//simpan titik awal
			int j=i;
			if (temp<array[j-gap]){
				array[j]=array[j-gap];
				j-=gap;
			}
			array[j]=temp;
		}
		fase+=1;
		gap=int(n/2/fase);
	}
}

main(){
	cout<<"Sebelum Sorting\n";
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}//menampilkan array sebelum sorting
	cout<<endl;
	cout<<"\n\nProses Sorting\n";
	shellsort(array);
	cout<<"\n\nSetelah Sorting\n";
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}//menampilkan array setelah sorting
}
