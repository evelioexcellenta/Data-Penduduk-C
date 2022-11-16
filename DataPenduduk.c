#include <stdio.h>
#include <stdlib.h>

struct pdk{ //definisi variabel untuk struct
char nik[20]; char gender[20]; char alamat[20]; char nama[20]; char usia[3]; char status[20]; char agama[20]; //variabel variabel dalam struct
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu,balik; //variabel untuk menu dan kembali
int x; //variabel untuk perhitungan / memilih data keberapa dalam function
int j; //variabel data total, variabel ini tidak direset dalam penggunaanya
int i; //varibel untuk looping for
int jumlah=0; //variabel jumlah data yang diinput
struct pdk *ptr; //definisi pointer ptr ke struct

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tambah(){ //function menambah data
	//int jumlah=0; //variabel jumlah data yang diinput
	i=0; //variabel looping for
	
	system ("cls");
	printf("================= MENU PENAMBAHAN DATA PENDUDUK =================\n\n");
	printf("Masukkan Jumlah Penduduk Yang Akan Didata : "); //jumlah data yang diinput
	scanf("%d",&jumlah);
	printf( "_________________________________________________________________\n");
	
	
	for(i=0;i<jumlah;i++){  //loop input data
		printf("\n\nDATA PENDUDUK NOMOR URUT KE-%d",j+1);
		printf("\n\tMasukkan NIK	: ");scanf(" %[^\n]%*c",(ptr+j)->nik);
		printf("\tMasukkan Nama   : ");scanf(" %[^\n]%*c",(ptr+j)->nama);
		printf("\tMasukkan Usia   : ");scanf(" %[^\n]%*c",(ptr+j)->usia);
		printf("\tMasukkan Gender : ");scanf(" %[^\n]%*c",(ptr+j)->gender);
		printf("\tMasukkan Alamat : ");scanf(" %[^\n]%*c",(ptr+j)->alamat);
		printf("\tMasukkan Status : ");scanf(" %[^\n]%*c",(ptr+j)->status);
		printf("\tMasukkan Agama  : ");scanf(" %[^\n]%*c",(ptr+j)->agama);
		j++; //menambah 1 pada variabel j, yang artinya jumlah data / address bertambah 1 setiap loop
}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tampil(){ //function menampilkan data
	x=0; //mereset variabel x
	
	system("cls");
	printf("Data Keseluruhan Penduduk : ");
	
	for(x=0;x<j;x++){ //loop menampilkan seluruh data
		printf("\n\nPenduduk %d",x+1);
		printf("\nNIK	:%s ",(ptr+x)->nik);
		printf("\nNama    :%s ",(ptr+x)->nama);
		printf("\nUsia    :%s ",(ptr+x)->usia);
		printf("\nGender  :%s ",(ptr+x)->gender);
		printf("\nAlamat  :%s ",(ptr+x)->alamat);
		printf("\nStatus  :%s ",(ptr+x)->status);
		printf("\nAgama   :%s ",(ptr+x)->agama);	
}
printf ("\n\nTekan angka berapa saja untuk kembali ke menu : "); //kembali ke menu
scanf("%d",&balik);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cari(){ //function menampilkan data spesifik
	x=0; //mereset variabel x
	
	system("cls");
	printf("Masukkan nomor data yang ingin dicari : "); //memilih data
	scanf("%d",&x);
	
	if (x>j||x==0||x<=0){
		printf("\nData tidak tersedia, Silahkan mencari sesuai data yang ada dan tidak negatif atau nol\n",j-1); //bila user memasukkan angka yang tidak tersedia 
	}
	else {
		printf("\n\nPenduduk %d",x);
		printf("\nNIK 	:%s ",(ptr+x-1)->nik);
		printf("\nNama    :%s ",(ptr+x-1)->nama);
		printf("\nUsia    :%s ",(ptr+x-1)->usia);
		printf("\nGender  :%s ",(ptr+x-1)->gender);
		printf("\nAlamat  :%s ",(ptr+x-1)->alamat);
		printf("\nStatus  :%s ",(ptr+x-1)->status);
		printf("\nAgama   :%s ",(ptr+x-1)->agama);
	}

	printf ("\n\nTekan angka berapa saja untuk kembali ke menu :");
	scanf("%d",&balik);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void hapus(){ //function menghapus data
	int del; //variabel untuk delete
	i=0; //mereset variabel i
	x=0;//mereset variabel x
	
	system("cls");
	printf("Nomor urut data yang dinginkan untuk dihapus : "); //memilih data
	scanf("%d",&x);
	
	if (x>j||x==0||x<=0){
		printf("\nData tidak tersedia, Silahkan mencari sesuai data yang ada dan tidak negatif atau nol\n"); //bila user memasukkan angka yang tidak tersedia 
	}
	else {
	printf("\n\ndata yang dihapus : %d",x);  //menampilkan data yang akan dihapus
	printf("\nNIK	:%s ",(ptr+x-1)->nik);
	printf("\nNama    :%s ",(ptr+x-1)->nama);
	printf("\nUsia    :%s ",(ptr+x-1)->usia);
	printf("\nGender  :%s ",(ptr+x-1)->gender);
	printf("\nAlamat  :%s ",(ptr+x-1)->alamat);
	printf("\nStatus  :%s ",(ptr+x-1)->status);
	printf("\nAgama   :%s ",(ptr+x-1)->agama);
	printf ("\n\nMasukkan angka 1 untuk mengkonfirmasi / angka lainnya untuk cancel : "); scanf("%d",&del); //kofirmasi delete
	
	if (del==1){ //penghapusan data
		for(i=x;i<j;i++){
			*(ptr+i-1)=*(ptr+i);
		}
		j=j-1;
		printf("\nData telah dihapus\n");
	}
	
	else { //data tidak jadi dihapus
		printf("\nData tidak akan dihapus\n");
	}
}
	printf ("\n\nMasukkan angka berapa saja untuk kembali ke menu :"); //kembali ke menu
	scanf("%d",&balik);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main (){ //main menu
	int exit; //variabel keluar program
	j=0; //variabel j dijadikan 1 agar perhitungan data mulai dari 1 bukan 0
	
	ptr=(struct pdk *)malloc(100*sizeof(struct pdk)); // Alokasi memori
	
	
	while(menu!=5){ //looping program
	system("cls");
 	printf(" ---------------- PROGRAM PENDATAAN PENDUDUK DAERAH ---------------"); //menampilkan menu
    printf( " \n\nMENU UTAMA :\n");
    printf( "___________________________________________________________________\n\n");
    printf( " 1. Menambah Data Penduduk\n\n");
    printf( " 2. Menampilkan seluruh Data Penduduk\n\n");
    printf( " 3. mencari Data Penduduk\n\n");
    printf( " 4. menghapus Data Penduduk\n\n");
    printf( " 5. Keluar\n\n");
    printf( " _____________________________\n\n");
    printf( " Masukan Pilihan Anda (1-5) : "); scanf ("%d", &menu); //memilih menu
    
    if (menu==1){ //menambah data
    	tambah();
   	}
   	
   	else if (menu==2){ //menampilkan data keseluruhan
   	 	tampil();
	  }
	
	else if (menu==3){ //menampiklan data spesifik
	cari();
	}
	else if (menu==4){ //menghapus data
	hapus();
	}
	else if (menu==5){
		printf("Apakah anda benar ingin keluar? [1 untuk keluar / angka lain untuk cancel] : ");
		scanf ("%d",&exit);
		
		if (exit!=1){
			menu=0;
		}
	}
	else {
		system("cls");
		printf ("Input yang anda masukkan tidak tersedia pada menu, silahkan gunakan angka 1-5 untuk memilih\n");
		printf ("\n\nMasukkan angka berapa saja untuk kembali memilih :");
		scanf("%d",&balik);
	}
}

system("cls");
printf ("============ Terimakasih telah menggunakan program pendataan penduduk kami ============");

free(ptr); //clear memory dari pointer
}



