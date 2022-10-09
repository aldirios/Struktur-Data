#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;


typedef char typeinfo;
typedef struct typequeue *type;
struct data{
	string nama;
	int noHp,dm,id;
	string nickname;
};

struct histori{
	string nama;
	int noHp,dm,id;
	string nickname;
};

struct typequeue{
	type next;
	type prev;
	data info;
	histori info2;
};
type head,tail,head1,tail1;
int No=0, nohistori=0;
string namaHapus;



	void newqueue(){  // constructor di C++
        head=(typequeue *)malloc(sizeof(typequeue));  // data pembeli
        head = NULL;
        tail=head;
        
		head1=(typequeue *)malloc(sizeof(typequeue));  //histori
        head1 = NULL;
        tail1=head1;
    }

	int queuekosong(){
		if(head==NULL){
			return(true);
		}else
			return(false);
	}

	void enqueue(string nama1,int noHp1, int dm1,int id1, string nickname1){
		type newData;
		newData=(typequeue *)malloc(sizeof(typequeue));
		newData->info.nama=nama1;
		newData->info.noHp=noHp1;
		newData->info.dm=dm1;
		newData->info.id=id1;
		newData->info.nickname=nickname1;
		if (head == NULL){
			head=newData;
		}else
		tail->next=newData;
		tail=newData;
		tail->next=NULL;
	} 
	
	void dequeue(){
		type hapus;
		if(queuekosong()){
			cout<<"Data Masih Kosong!!";
		}else{
			hapus=head;
			head=hapus->next;
			{
				type newData;
				newData=(typequeue *)malloc(sizeof(typequeue));
				newData->info2.nama=hapus->info.nama;
				newData->info2.noHp=hapus->info.noHp;
				newData->info2.dm=hapus->info.dm;
				newData->info2.id=hapus->info.id;
				newData->info2.nickname=hapus->info.nickname;	
				if (head1 == NULL)
					head1 = newData;
				else
					tail->next = newData;
					tail1 = newData;
					tail1->next = NULL;
				nohistori++;
			}
			free(hapus);//menghapus nilai dari alokasi maloc
			No--;
			cout<<"Diamond Berhasil Dikirimkan\n";
			cout<<"NAMA           : " <<tail1->info2.nama<<endl;
			cout<<"ID GAME        : " <<tail1->info2.id<<endl;
			cout<<"NICKNAME       : " <<tail1->info2.nickname<<endl;
			cout<<"JUMLAH DIAMOND : " <<tail1->info2.dm<<endl;
		}
	}
	
	void cetakqueue(){
		type bantu;
		int i=0;
		bantu = head;
		cout << "DAFTAR PEMBELI";
		cout << setw(4)<< "No"<<setw(10) << "Nama"<<setw(20)<<"Id Game"<<setw(30)<<"Nickname"<<setw(40)<<"Jumlah Diamond"<<endl;
		do{
			i++;
			cout << setw(4)<< "i"<<setw(10) << bantu->info.nama<<setw(20)<<bantu->info.id<<setw(30)<<bantu->info.nickname<<setw(40)<<bantu->info.dm<<endl;
			bantu=bantu->next;
		}while(bantu != NULL && i != No);
		cout<<"\nJumlah Antrian : "<<No<<endl<<endl;
	}
	
	void cetakqueueriwayat(){
		type bantu;
		int i=0;
		bantu = head;
		cout << "DAFTAR PEMBELI";
		cout << setw(4)<< "No"<<setw(10) << "Nama"<<setw(20)<<"Id Game"<<setw(30)<<"Nickname"<<setw(40)<<"Jumlah Diamond"<<endl;
		do{
			i++;
			cout << setw(4)<< "i"<<setw(10) << bantu->info2.nama<<setw(20)<<bantu->info2.id<<setw(30)<<bantu->info2.nickname<<setw(40)<<bantu->info2.dm<<endl;
			bantu=bantu->next;
		}while(bantu != NULL && i != No);
		cout<<"\nJumlah Antrian : "<<No<<endl<<endl;
	}
	
	void batal(){
		type hapus;
		if(queuekosong()){
			cout<<"Data Masih Kosong";
		}else{
			hapus=tail;
			if(hapus==head){
				free(hapus);
				head=tail=NULL;
			}else{
				tail=hapus->prev;
				free(hapus);
				tail->next=NULL;
			}No--;
		}
	}

main(){
	LinkedList* ll = new LinkedList;
	int menu,no,noHp1,dm1,id1;
	string nama1,nickname1,ulang;
	atas:
	do{
	cout<<"---------- MOBILE LEGENDS DIAMOND ----------";
	cout<<"\nMENU\n";
	cout<<"1. Top Up\n2. Daftar Pembeli\n3. Pembatalan Pembelian\n4. Proses Pengiriman\n5. Riwayat pengiriman\n6. Keluar\n";
	cout<<"Pilih Menu .....";
	cin>>menu;
	switch(menu){
	case 1 :{
		No++;
		cout<<"Top Up diamond ML\n";
		cout<<"Input Data\n";
		cout<<"Nama\t\t:";cin>>nama1;
		cout<<"No Hp\t:";cin>>noHp1;
		cout<<"Jumlah Diamond :";cin>>dm1;
		cout<<"ID Game :";cin>>id1;
		cout<<"Nickname Game :";cin>>nickname1;
		ll->nambah(nama1,noHp1,dm1,id1,nickname1);
		}break;
	case 2:{
		if(!ll->kosong()){
			cetakqueue();
		}else{
			cout<<"Tidak ada pembeli!!\n";
		}
		}goto atas;
		break;
	case 3:{
		if(!queuekosong()){
			batal();
			cout<<"Tidak jadi membeli!!\n";
		}else
			cout<<"Belum ada pembeli!!\n";
		}goto atas;
		break;
	case 4:{
		if(!queuekosong()){
			dequeue();
		}else
			cout<<"Tidak ada pembeli!!\n";
		}goto atas;
		break;
	case 5:{
		if(nohistori!=0){
			cetakqueueriwayat();
		}else{
			cout<<"Belum ada pembeli!!\n";
		}
		}goto atas;
		break;
	case 6:
		exit(0);
		break;
	default:
		cout<<"input salah"<<endl;
		break;
		}cout<<"ingin kembali kemenu";cin>>ulang;
	}while(ulang=="y");
}
