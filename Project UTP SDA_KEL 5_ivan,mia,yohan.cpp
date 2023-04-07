#include <iostream>
using namespace std;

struct Antrian {
   int nomor;
   Antrian* next;
};

void enqueue(Antrian*& head, Antrian*& tail, int nomor) {
   Antrian* node = new Antrian;
   node->nomor = nomor;
   node->next = NULL;
   
   if (tail == NULL) {
      head = node;
      tail = node;
   } else {
      tail->next = node;
      tail = tail->next;
   }
   cout << "Pelanggan dengan nomor " << nomor << " masuk antrian" << endl;
}

void dequeue(Antrian*& head, Antrian*& tail) {
   if (head == NULL) {
      cout << "Antrian kosong" << endl;
      return;
   }
   Antrian* node = head;
   head = head->next;
   cout << "Pelanggan dengan nomor " << node->nomor << " keluar dari antrian" << endl;
   delete node;
}

void display(Antrian* head) {
   if (head == NULL) {
      cout << "Antrian kosong" << endl;
      return;
   }
   Antrian* node = head;
   cout << "Isi antrian: ";
   while (node != NULL) {
      cout << node->nomor << " ";
      node = node->next;
   }
   cout << endl;
}

int main() {
   Antrian* head = NULL;
   Antrian* tail = NULL;
   int pilihan, nomor;
   do {
      cout << "Antrian Bank" << endl;
      cout << "1. Masukkan pelanggan" << endl;
      cout << "2. Keluarkan pelanggan" << endl;
      cout << "3. Lihat antrian" << endl;
      cout << "4. Keluar" << endl;
      cout << "Pilihan Anda: ";
      cin >> pilihan;
      
      switch(pilihan) {
         case 1:
            cout << "Nomor pelanggan: ";
            cin >> nomor;
            enqueue(head, tail, nomor);
            break;
         case 2:
            dequeue(head, tail);
            break;
         case 3:
            display(head);
            break;
         case 4:
            cout << "Terima kasih" << endl;
            break;
         default:
            cout << "Pilihan salah" << endl;
      }
   } while (pilihan != 4);
   
   return 0;
}

