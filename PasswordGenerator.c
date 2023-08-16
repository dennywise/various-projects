#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
	char tekrar [20];
	do{
	
    srand(time(NULL)); // rastgele sayý oluþturur.
    int uzunluk;
    printf("Sifre uzunlugu girin: "); //þifre uzunluðunu alýr.
    scanf("%d", &uzunluk);
    if(uzunluk < 6) //þifrenin karakter uzunluðu kýsýtlamalarý için if else.
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
    char sifre[uzunluk + 1]; // þifre için dizin oluþturur.
	int i = 0;
    for (i; i < uzunluk; i++) { //þifredeki her karakter int i olarak tanýmlayýp rastgele olasýlýklarla karakter oluþturur.
        int type = rand() % 4; // 0 3 arasi bir sayi secer
        
        switch (type) {
            case 0: //  rastgele küçük karakter
                sifre[i] = 'a' + (rand() % 26);
                break;
            case 1: // rastgele büyük karakter
                sifre[i] = 'A' + (rand() % 26);
                break;
            case 2: // rastgele sayý
                sifre[i] = '0' + (rand() % 10);
                break;
            case 3: // rastegele özel karakter
                sifre[i] = '!' + (rand() % 15);
                break;
        }
    }
    sifre[uzunluk] = '\0'; // parola dizinini sonlandýrýr.
	char kayit;
	
    printf("Sifreniz: %s\neger bu sifreyi pwgen.txt dosyasina kaydetmek isterseniz 1'e, istemezseniz 2'ye basin: ", sifre); // þifreyi ekrana yazdýrýr ve kayýt iþlemi seçimi.
	scanf("%s", &kayit);
		char isim [50];
		FILE * dosya = fopen("pwgen.txt", "a"); // dosyayý 'a'(append(ekleme)) modunda açar ve bu sayede 'w' modunun aksine daha önceki verileri silip yeniden yazmak yerine dosyaya veri ekler.
	switch(kayit)//kayýt iþlemi
	{
		case '1':
			printf("lutfen sifrenize bir isim veriniz: ");
			scanf("%s", &isim);
  		fprintf(dosya, "\n%s %s",  sifre, isim); //fprintf komutu ile dosyaya þifreyi yazar.
  		printf("sifreniz kaydedilmistir.");
  		break;
  		case '2':
  		printf("Sifreniz kaydedilmemistir.");
  		break;
	}
}
		printf("\nprogrami tekrar baslatmak istiyor musunuz? (evet/hayir): "); //do while döngüsü ile tekrar deðiþkeni evet cevabýna yani 0'a eþitse program tekrar baþlar.
		scanf("%s", &tekrar);
}
  		while(strcmp(tekrar,"evet") == 0);
}
