#include <iostream>
using namespace std;

int pilihan,angka;

struct Node{
    int data;
    struct Node* next;  // deklarasi node selanjutnya
};

class LinkedList{
    public: // access permission-nya (di bawah class ini public semua)
    Node* head;  // deklarasi head linked list
    LinkedList(){  // constructor di C++
        head = NULL;
    }

    void nambah(int data){
        system("CLS");
        Node* newData = new Node;
        newData->data = data; 
        if(head == NULL){
		head = newData;
        newData->next = head;
        }else{
            Node* oldData = head;
            while(oldData->next!=head){oldData = oldData->next;}  // bakal ambil data sampai linked list paling ujung
            oldData->next = newData;
        	newData->next = head;
        }
        cout<<"Data Berhasil Ditambahkan\n\n\n";
    }
    void tampil(){
        system("CLS");
        if(head==NULL){
        	cout<<"Linked List Kosong\n\n\n";
    	}
		else{
	        cout << "Menampilkan Data" << endl;
    	    Node* liat = head;
        	int i = 0;
        	while(liat->next!=head){
            	i++;
            	cout << "Data ke-" << i << ": " << liat->data << endl;
            	liat = liat->next;
        	}
        	i++;
            cout << "Data ke-" << i << ": " << liat->data << endl<<endl<<endl;
		}
    }
    void ubah(){
    	int no,baru;
		if(head==NULL){
        	cout<<"Linked List Kosong\n\n\n";
    	}
		else{
	    	cout<<"\nMasukkan No Data Yang Ingin Diubah = ";
	    	cin>>no;
	    	no=no-1;
	    	cout<<"\nMasukkan Data Yang Baru(angka) = ";
	    	cin>>baru;
	    	Node* ubah=head;
			while(no!=0){
				no--;
	    		ubah=ubah->next;
			}
	    	ubah->data=baru;
			cout<<"\nData Berhasil Diubah\n\n\n";
		}
	}
};
int main(){
	LinkedList* ll = new LinkedList;
    abc:
	cout<<"1. INPUT DATA\n"<<"2. UBAH DATA\n"<<"3. TAMPILKAN DATA\n"<<"4. EXIT\n";
	cout<<"Masukkan Pilihan Anda = ";
	cin>>pilihan;
	cout<<"\n\n";
	if (pilihan==1){
		cout<<"Masukkan Data(angka) = ";
		cin>>angka;
		ll->nambah(angka);
		goto abc;
	}
	else if (pilihan==2){
    	system("CLS");
		ll->tampil();
    	ll->ubah();
		goto abc;
	}
	else if(pilihan==3){		
    	ll->tampil();
    	goto abc;
	}
	else if(pilihan==4){
	}
	else{
		goto abc;
	}
    return 0;
}
