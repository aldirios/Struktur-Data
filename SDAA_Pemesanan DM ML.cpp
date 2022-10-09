#include <iostream>
#include <iomanip>
using namespace std;

int pilihan,angka;
int No=0, nohistori=0;

struct data{
	string nama;
    int dm,id;
    string nn;
	struct Node* next;
	struct Node* prev;
};


struct Node{
	string nama;
    int dm,id;
    string nn;
	struct Node* next;
	data data1;
};




class LinkedList{
    public: // access permission-nya (di bawah class ini public semua)
    Node* head;  // deklarasi head linked list
    Node* head1;
    LinkedList(){  // constructor di C++
        head = NULL;
        head1 = NULL;
    }

    void enqueu(string nama1,int dm1,int id1,string nn1){
        system("CLS");
        Node* newData = new Node;
        newData->data1.nama = nama1;
        newData->data1.dm = dm1;
        newData->data1.id = id1;
        newData->data1.nn = nn1;
        newData->data1.next = NULL;
        newData->data1.prev = NULL;  
        if(head == NULL){
			head = newData;
        }else{
            Node* oldData = head;
            while(oldData->data1.next){oldData = oldData->data1.next;}  // bakal ambil data sampai linked list paling ujung
            oldData->data1.next = newData;
        	newData->data1.next = NULL;
        	newData->data1.prev = oldData;
        }
        cout<<"Data Berhasil Ditambahkan\n\n\n";
    }
    
    int kosong(){
		if(head==NULL){
			return(true);
		}else
			return(false);
	}
	
	void dequeue(){
		Node* oldData;
		Node* hapus;
		if(head==NULL){
			cout<<"Data Masih Kosong!!";
		}else{
			nohistori++;
			hapus=head;
			head=hapus->data1.next;
			Node* newData = new Node;
	        newData->nama = hapus->data1.nama;
    	    newData->dm = hapus->data1.dm;
        	newData->id = hapus->data1.id;
      		newData->nn = hapus->data1.nn;
      	  	newData->next = NULL;
        	if(head1 == NULL){
				head1 = newData;
     	   }else{
        	    Node* oldData = head1;
            	while(oldData->next){oldData = oldData->next;}  // bakal ambil data sampai linked list paling ujung
            	oldData->next = newData;
        		newData->next = NULL;
			}
			cout<<"NAMA           : " <<hapus->data1.nama<<endl;
			cout<<"ID GAME        : " <<hapus->data1.id<<endl;
			cout<<"NICKNAME       : " <<hapus->data1.nn<<endl;
			cout<<"JUMLAH DIAMOND : " <<hapus->data1.dm<<endl;
			No--;
			delete hapus;
			cout<<"Pesanan Telah Terkirim\n";
		}
	}
	void cetakqueue(){
		Node* bantu;
		int i=0;
		bantu = head;
		cout << "DAFTAR PEMBELI\n";
		cout << setw(4)<< "No"<<setw(10) << "Nama"<<setw(20)<<"Id Game"<<setw(30)<<"Nickname"<<setw(40)<<"Jumlah Diamond"<<endl;
		do{
			i++;
			cout << setw(4)<< i<<setw(10) << bantu->data1.nama<<setw(20)<<bantu->data1.id<<setw(30)<<bantu->data1.nn<<setw(40)<<bantu->data1.dm<<endl;
			bantu=bantu->data1.next;
		}while(bantu != NULL && i != No);
		cout<<"\nJumlah Antrian : "<<No<<endl<<endl;
	}
	
	void cetakriwayat(){
		Node* bantu;
		int i=0;
		bantu = head1;
		cout << "RIWAYAT PEMBELI\n";
		cout << setw(4)<< "No"<<setw(10) << "Nama"<<setw(20)<<"Id Game"<<setw(30)<<"Nickname"<<setw(40)<<"Jumlah Diamond"<<endl;
		do{
			i++;
			cout << setw(4)<< i<<setw(10) << bantu->nama<<setw(20)<<bantu->id<<setw(30)<<bantu->nn<<setw(40)<<bantu->dm<<endl;
			bantu=bantu->next;
		}while(bantu != NULL && i != nohistori);
		cout<<"\nJumlah Pembeli : "<<nohistori<<endl<<endl;
	}
	
	
	void swap(Node* bantu1, Node* bantu2){
	
		int temp1 = bantu2->dm;
		int temp2 = bantu2->id;
		string temp3 = bantu2->nama;
		string temp4 = bantu2->nn;
		
		bantu2->dm=bantu1->dm;
		bantu2->id=bantu1->id;
		bantu2->nama=bantu1->nama;
		bantu2->nn=bantu1->nn;
		
		bantu1->dm=temp1;
		bantu1->id=temp2;
		bantu1->nama=temp3;
		bantu1->nn=temp4;
	}
	
	void bubbleSort(){
		int swapped;
		Node* b1;
		Node* b2;
		Node* right;
		right=NULL;
		do{
			swapped=0;
			b1=head1;
			while(b1->next != right){
				b2=b1->next;
				if(b1->id > b2->id){
					swap(b1,b2);
					swapped = 1;
				}
				b1 = b1->next;
			}
			right=b1;
		}while(swapped);
	}
	/*void swapp(Node* q, Node* q1){
		Node* temp=q1->next;
		Node* bantu=q->prev;
		q1->next=q;
		q1->prev=bantu;
		q->next=temp;
		q->prev=q1;
    }
	
	void bubbleSort(){
		Node* q;
		Node* q1;
		Node* end=NULL;
		int swap=0;
		do{
			q=head1;
			q1=q->next;
			while(q->next!=end){
				if(q->id>q1->id){
					swapp(q,q1);
					swap++;
				}
				q->next;
			}
			if(swap==0);
				break;
			end=q;
		}while(swap > 0);
	}*/
	
	Node* middle(Node* start, Node* last){
		Node* slow;
		Node* fast;
		if(start == NULL){
			return NULL;
		}
		slow = start;
		fast = start->next;
		while(fast != last){
			fast = fast->next;
			if (fast!=last){
				slow = slow->next;
				fast = fast->next;
			}
		}
		return slow;
	}
	
	int binarysearch(int value){
		Node* start =head1;
		Node* last = NULL;
		do{
			Node* mid=middle(start,last);
			if(mid == NULL)
				return 0;
			if(mid->id==value)
				return 1;
			else if(mid->id<value)
				start = mid->next;
			else
				last=mid;
		}while(last==NULL || last!=start);
		return 0;
	}
	
};

int main(){
	LinkedList* ll = new LinkedList;
	int menu,no,dm1,id1,nilai;
	string nama1,nn1,ulang;
	do{
	cout<<"---------- APLIKASI PEMESANAN DIAMOND MOBILE LEGENDS ----------";
	cout<<"\nMENU\n";
	cout<<"1. Top Up\n2. Daftar Pembeli\n3. Proses Pengiriman\n4. cari Riwayat pengiriman\n5. Keluar\n";
	cout<<"Pilih Menu .....";
	cin>>menu;
	switch(menu){
	case 1 :{
		No++;
		cout<<"Top Up diamond ML\n\n";
		cout<<"Input Data\n\n";
		cout<<"Nama\t\t:";cin>>nama1;
		cout<<"Jumlah Diamond :";cin>>dm1;
		cout<<"ID Game :";cin>>id1;
		cout<<"Nickname Game :";cin>>nn1;
		ll->enqueu(nama1,dm1,id1,nn1);
		}break;
		
	case 2:{
		if(!ll->kosong()){
			ll->cetakqueue();
		}else cout<<"Tidak ada pembeli!!\n";
		}break;
	
	case 3:{
		if(!ll->kosong()){
			ll->dequeue();
		}else cout<<"Tidak ada pembeli!!\n";
		}break;
	
	case 4:{
		if(nohistori!=0){
			cout<<"masukkan id game yang ingin dicari";cin>>nilai;
			ll->cetakriwayat();
			if (ll->binarysearch(nilai)==0){
				cout<<"data tidak ditemukan";
			}
			else if(ll->binarysearch(nilai)==1){
				cout<<"data ditemukan";	
			}
			ll->bubbleSort();
			ll->cetakriwayat();
			if (ll->binarysearch(nilai)==0){
				cout<<"data tidak ditemukan";
			}
			else if(ll->binarysearch(nilai)==1){
				cout<<"data ditemukan";	
			}
		}else cout<<"Belum ada pembeli!!\n";
		}break;
	case 5:
		exit(0);
		break;
	default:{
		break;
		cout<<"input salah"<<endl;
		}break;
		}cout<<"ingin kembali kemenu (Y|y) : }";cin>>ulang;
		system("cls");
	}while(ulang=="y" or ulang=="Y");
}
