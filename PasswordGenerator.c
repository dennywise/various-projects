#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
	char tekrar [20];
	do{
	
    srand(time(NULL)); // rastgele say� olu�turur.
    int uzunluk;
    printf("Sifre uzunlugu girin: "); //�ifre uzunlu�unu al�r.
    scanf("%d", &uzunluk);
    if(uzunluk < 6) //�ifrenin karakter uzunlu�u k�s�tlamalar� i�in if else.
    {
        printf("Sifreniz 6 karakterden az olamaz.");
        return 0;
    }
    else if (uzunluk >24)
    {
        printf("sifreniz 24 karakterden uzun olamaz.");
        return 0;
    }
    else{
    char sifre[uzunluk + 1]; // �ifre i�in dizin olu�turur.
	int i = 0;
    for (i; i < uzunluk; i++) { //�ifredeki her karakter int i olarak tan�mlay�p rastgele olas�l�klarla karakter olu�turur.
        int type = rand() % 4; // 0 3 arasi bir sayi secer
        
        switch (type) {
            case 0: //  rastgele k���k karakter
                sifre[i] = 'a' + (rand() % 26);
                break;
            case 1: // rastgele b�y�k karakter
                sifre[i] = 'A' + (rand() % 26);
                break;
            case 2: // rastgele say�
                sifre[i] = '0' + (rand() % 10);
                break;
            case 3: // rastegele �zel karakter
                sifre[i] = '!' + (rand() % 15);
                break;
        }
    }
    sifre[uzunluk] = '\0'; // parola dizinini sonland�r�r.
	char kayit;
	
    printf("Sifreniz: %s\neger bu sifreyi pwgen.txt dosyasina kaydetmek isterseniz 1'e, istemezseniz 2'ye basin: ", sifre); // �ifreyi ekrana yazd�r�r ve kay�t i�lemi se�imi.
	scanf("%s", &kayit);
		char isim [50];
		FILE * dosya = fopen("pwgen.txt", "a"); // dosyay� 'a'(append(ekleme)) modunda a�ar ve bu sayede 'w' modunun aksine daha �nceki verileri silip yeniden yazmak yerine dosyaya veri ekler.
	switch(kayit)//kay�t i�lemi
	{
		case '1':
			printf("lutfen sifrenize bir isim veriniz: ");
			scanf("%s", &isim);
  		fprintf(dosya, "\n%s %s",  sifre, isim); //fprintf komutu ile dosyaya �ifreyi yazar.
  		printf("sifreniz kaydedilmistir.");
  		break;
  		case '2':
  		printf("Sifreniz kaydedilmemistir.");
  		break;
	}
}
		printf("\nprogrami tekrar baslatmak istiyor musunuz? (evet/hayir): "); //do while d�ng�s� ile tekrar de�i�keni evet cevab�na yani 0'a e�itse program tekrar ba�lar.
		scanf("%s", &tekrar);
}
  		while(strcmp(tekrar,"evet") == 0);
}
