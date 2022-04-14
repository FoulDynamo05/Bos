#include <iostream>
#include <time.h>
using namespace std;

//maksimum 2500 kisiye kadar ogrencilerin cevap anahtarlari otomatik olusturuluyor ve girilen cevap anahtariyla ogrencilerin cevap anahtari kiyaslaniyor ardindan puanlama yapiliyor
//tum ad ve soyadlar ad ve soyad havuzundan alinip rastgele ve unique olacak sekilde olusturuluyor
//ardindan kullanicinin secimine gore ogrenciler siralanarak ekrana yazdiriliyor

//Dizi tanimlarinda kullanilmak uzere sabitler olusturuluyor
const int cevapAnahtariBoyut = 10;
const int adBoyut = 50;
const int soyadBoyut = 50;

//Verileri tutmak daha kolay olsun diye insan tipinde bir struct olusturuluyor
struct Insan
{
	string ad;
	string soyad;
	short puan = 0;
	short yas = 0;
	bool* cevaplar = new bool[cevapAnahtariBoyut];

	//Her yeni bir obje olustugunda objenin cevap anahtari dolduruluyor
	Insan()
	{
		for (int i = 0; i < cevapAnahtariBoyut; i++)
		{
			cevaplar[i] = rand() % 2;
		}
	}

	//Objenin cevap anahtari ile parametre gelen cevap anahtari kiyaslaniyor her eslesen veri icin 10 puan ekleniyor ve ekrana yazdiriliyor
	void cevapKiyasla(bool cevapAnahtari[])
	{
		for (int i = 0; i < cevapAnahtariBoyut; i++)
		{
			if (cevaplar[i] == cevapAnahtari[i])
			{
				puan += 10;
				cout << "D ";
			}
			else
			{
				cout << "Y ";
			}
		}
		cout << ad << " " << soyad << " kisisinin cevap anahtari" << endl;
	}
};

//Fonksiyonlarin imzalari tanimlaniyor
void cevapAnahtariGiris(bool cevapAnahtari[], int size);
bool doesExist(Insan arr[], int size, string ad, string soyad);
void insanlariYazdir(Insan arr[], int size);
void selectionSort(Insan arr[], int size, short tip);
void insanlariDoldur(Insan insanlar[], int size, string ad[], string soyad[]);

int main(void)
{
	srand(time(NULL));

	//Degisken tanimlari
	int size;
	short tip = 0;
	bool cevapAnahtari[cevapAnahtariBoyut];
	string ad[adBoyut] = { "Ramiz","Ezel","Kamil","Tevfik","Omer","Eysan","Sebnem","Ali","Cengiz","Kenan","Temmuz","Ocak","Mayis","Selim","Can","Mumtaz","Mert","Hamide","Serdar","Utku","Enes","Baris","Berat","Ozgur","Yucel","Kerem","Vedat","Mesut","Isil","Tarik","Atakan","Hakan","Ozan","Emirhan","Ibrahim","Yagiz","Umut","Ilker","Eren","Tugce","Melek","Sena","Huma","Aleyna","Furkan","Huseyin","Yusuf","Erkan","Yamac","Bakilir" };
	string soyad[soyadBoyut] = { "Sasi", "Karaeski","Bayraktar","Koc","ozabim","Ucar","Tezcan","Zaim","Kirgiz","Atay","Birkan","Kocaoglu","Temmuzoglu","Temmuzkardesi","Arabayigetir","Atmay","Ucmaz","Gazeteci","Omerim","Yakisikli","Bakilsin","Altinay","Demir","Bakir","Metin","Ozcetin","Omer","Firat","Andak","Citak","Demirhan","Cimen","Kirac","Hakman","Ozman","Sivriburun","Korkmaz","Gunaydin","Arslan","Kanur","Keklik","Gumusay","Ozer","Bisirici","Okur","Zulaboss","Yutu","Ekran","Kocovali","Bakicaz" };
	Insan* insanlar;

	//Kullanicidan cevap anahtari aliniyor
	cevapAnahtariGiris(cevapAnahtari, cevapAnahtariBoyut);

	//Kullanicidan programin kac kisilik olacagi bilgisi aliniyor
	cout << "Programin kac kisilik olmasini istiyorsunuz 1 ile " << adBoyut * soyadBoyut << " arasinda bir sayi girin: ";
	cin >> size;
	insanlar = new Insan[size];

	//Insanlar dizisinin degerleri giriliyor
	insanlariDoldur(insanlar, size, ad, soyad);

	//Konsolda guzel gozukmesi icin atilmis bir bosluk
	cout << endl;

	//insanlarin cevap anahtarlarini kiyaslayarak puanlamalarini yapan kod
	for (int i = 0; i < size; i++)
	{
		insanlar[i].cevapKiyasla(cevapAnahtari);
	}

	cout << "\nNeye gore siralamak istersiniz Ad(1) Soyad(2) Yas(3) Puan(4) Siralama Yapma(5): ";
	cin >> tip;

	//Secilen siralama tipine gore dizi siralaniyor
	selectionSort(insanlar, size, tip);

	//Dizi yazdiriliyor
	insanlariYazdir(insanlar, size);

	return 0;
}

//gelen ad soyad dizide var mi diye kontrol eden fonksiyon
bool doesExist(Insan arr[], int size, string ad, string soyad)
{
	for (int i = size; i >= 0; i--)
	{
		if (arr[i].ad == ad && arr[i].soyad == soyad)
		{
			return true;
		}
	}
	return false;
}

//Cevap anahtarini hazirlayan fonksiyon
void cevapAnahtariGiris(bool cevapAnahtari[], int size)
{
	char giris;
	cout << "Dogru icin D yanlis icin Y seklinde cevap anahtarini giriniz: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Cevabinizi girin: ";
		cin >> giris;
		while (giris != 'D' && giris != 'Y' && giris != 'd' && giris != 'y')
		{
			cout << "Lutfen cevabinizi D veya Y seklinde giriniz: ";
			cin >> giris;
		}

		if (giris == 'D' || giris == 'd') cevapAnahtari[i] = 1;
		else cevapAnahtari[i] = 0;
	}
	cout << endl;
}

void insanlariDoldur(Insan insanlar[], int size, string ad[], string soyad[])
{
	string nameRandom;
	string lastNameRandom;
	short ageRandom;
	short randomVar = 0;
	short randomCount;
	int count = 0;

	//Degerler giriliyor
	for (int i = 0; i < size; i++)
	{
		//Random icin kullanilan degiskenler
		nameRandom = ad[rand() % 50];
		lastNameRandom = soyad[rand() % 50];
		ageRandom = rand() % 43 + 18;

		randomVar = rand() % 50;
		randomCount = 0;

		//Ayni isim soyismin bir daha kullanilmamasi icin calisan kod

		//doesExist fonksiyonu Insan tipinde bir dizi, bir sayac, ad ve soyad aliyor akabinde aldigi ad ve soyadi dizide aratiyor eger eslesen veri varsa true donuyor
		while (doesExist(insanlar, count, nameRandom, lastNameRandom))
		{
			//Dizilerin maximum indisi 49 oldugu icin uzerine cikarsa baslangic degerini 0 liyoruz
			if (randomVar > 49) randomVar = 0;

			//randomVar yukarida random bir degerden basliyor eger o soyad alinmissa bir fazlasini deniyor o da varsa ayni islemi tekrarliyor
			//en nihayetinde hic bosta soyad bulamazsa isim degistiriyoruz
			lastNameRandom = soyad[randomVar++];

			//randomCount kac kere soyad degistirme islemi yapildigina bakiyor eger 49 u gecerse o ismin alabilecegi soyad kalmamistir farkli bir isme geciyoruz
			randomCount++;
			if (randomCount > 49)
			{
				nameRandom = ad[rand() % 50];
				randomCount = 0;
			}
		}

		//Deger atamalari yapiliyor
		insanlar[i].ad = nameRandom;
		insanlar[i].soyad = lastNameRandom;
		insanlar[i].yas = ageRandom;

		//bu sayac doesExist fonksiyonunu kullandigimizda o ana kadar kac eleman girildigini sayiyor, onu parametre olarak gondererek
		//dizide gezecegimiz zamani azaltiyoruz ve o indexte eleman yok hatasi almiyoruz
		count++;
	}
}

//Gelen insan dizisini yazdiran fonksiyon
void insanlariYazdir(Insan arr[], int size)
{
	cout << endl;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		cout << "Ad soyad: " << arr[i].ad << " " << arr[i].soyad << " Yas: " << arr[i].yas << " Puan: " << arr[i].puan << endl;
		count++;
	}
	cout << "kisi sayisi: " << count << endl;
}

//Siralama islemini yapan fonksiyon
void selectionSort(Insan arr[], int size, short tip)
{
	//Degiskenler tanimlaniyor
	Insan temp;
	int max = 0;
	short letter = 0;
	short lengthFirst = 0;
	short lengthSecond = 0;

	for (int i = 0; i < size; i++)
	{
		max = i;
		for (int j = i; j < size; j++)
		{
			if (tip == 1)
			{
				//letter degiskeni kacinci harflerini kiyasladigimizi belirtiyor
				letter = 0;

				//eger ahmet ve adnan ornegindeki gibi ilk harfleri ayniysa bir sonraki harflerini kiyaslamak icin bu iki ismi donguye aliyoruz
				if (arr[j].ad[letter] == arr[max].ad[letter])
				{
					//o anki kiyaslanan adlarin boyutlarini aliyoruz ki harf sayisi ismin uzunlugunu gecerse donguyu kirmak icin
					//bir eksigini almamizin sebebi letter in 0 dan baslamasi
					lengthFirst = arr[j].ad.length() - 1;
					lengthSecond = arr[max].ad.length() - 1;
					while (true)
					{
						if (arr[j].ad[letter] < arr[max].ad[letter])
						{
							max = j;
							break;
						}
						else if (arr[j].ad[letter] != arr[max].ad[letter])
						{
							break;
						}

						//eger harf sayisi iki isimden birinin boyutuna esit olursa donguyu kiriyoruz
						if (letter == lengthFirst || letter == lengthSecond)
						{
							break;
						}

						letter++;
					}
				}
				else
				{
					//burada char degerleri kiyaslaniyor ornek olarak A harfi ascii de 65 e denk geliyor B harfi 66 ya kucuk olan alfabede
					//once geldigi icin daha buyuk oldugu anlamina geliyor
					if (arr[j].ad[letter] < arr[max].ad[letter])
					{
						max = j;
					}
				}
			}

			//soyada gore siralama ad ile ayni sadece ad yerine soyada bakiyor
			if (tip == 2)
			{
				letter = 0;
				if (arr[j].soyad[letter] == arr[max].soyad[letter])
				{
					while (true)
					{
						lengthFirst = arr[j].soyad.length() - 1;
						lengthSecond = arr[max].soyad.length() - 1;
						if (arr[j].soyad[letter] < arr[max].soyad[letter])
						{
							max = j;
							break;
						}
						else if (arr[j].soyad[letter] != arr[max].soyad[letter])
						{
							break;
						}

						if (letter == lengthFirst || letter == lengthSecond)
						{
							break;
						}

						letter++;
					}
				}
				else
				{
					if (arr[j].soyad[letter] < arr[max].soyad[letter])
					{
						max = j;
					}
				}
			}

			//yasa gore siralama
			if (tip == 3)
			{
				if (arr[j].yas > arr[max].yas)
				{
					max = j;
				}
			}

			//puana gore siralama
			if (tip == 4)
			{
				if (arr[j].puan > arr[max].puan)
				{
					max = j;
				}
			}

		}

		//secmeli siralama yaptigimiz icin en buyuk degeri bulup en basa koyuyoruz(buyukten kucuge siraladim)
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}

	//tip 5 siralama yapma demek oldugu icin bos fonksiyon donduruyoruz
	if (tip == 5)
	{
		return;
	}

}
