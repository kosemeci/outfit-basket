
//394769-Bayram Alperen Kösemeci
//399719-Ali Aliyev
//365271-Ali YEŞİLYURT

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <fstream> 
#include <conio.h>
using namespace std;

bool check = false;
bool check2 = true;
string hiddenPassword(string& oth) {
    char pass[32];
    int i = 0;
    char a;
    for (i = 0;;)
    {
        a = _getch();
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            pass[i] = a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            cout << "\b \b";
            --i;
        }
        if (a == '\r')
        {
            pass[i] = '\0';
            break;
        }
    }
    oth = pass;
    cout << "\n";
    return oth;
}
string isimKontrol(string& oth) {
    for (int i = 0; i <= oth.length(); i++) {
        if ((oth[i] >= 'a' && oth[i] <= 'z') || (oth[i] >= 'A' && oth[i] <= 'Z') || (oth[i] == ' ') || (oth[i] == '\0')) { continue; }
        else {
            cout << "İsminizde geçersiz karakter kullanıldı!" << endl;
            string k = "gecersiz";
            return k;
        }
    }
    return oth;
}
string numberKontrol(string& oth) {
    string no = "00000";
    if (oth.length() == 11) {
        for (int i = 0; i <= oth.length(); i++) {
            if (oth[i] >= '0' && oth[i] <= '9' || oth[i] == '\0') {
                continue;
            }
            else {
                cout << "Telefon numaranız 11 rakamdan oluşmalı!" << endl;
                return no;
            }
        }
    }
    else { cout << "Telefon numaranız 11 rakamdan oluşmalı!" << endl;  return no; }

    return oth;
}
string dobKontrol(string& oth) {
    string gun, ay, yil;
    bool tarihKontrol = false;
    int gg = 0, aa = 0, yy = 0;
    if (oth.length() == 10) {
        if (oth[2] == '/' && oth[5] == '/') {
            gun = oth.substr(0, 2);
            gg = stoi(gun);
            ay = oth.substr(3, 2);
            aa = stoi(ay);
            yil = oth.substr(6, -1);
            yy = stoi(yil);
        }
        else { cout << "Doğum tarihinizi gg/aa/yıl şeklinde giriniz." << endl;  return gun; }
    }
    else { cout << "Doğum tarihinizi gg/aa/yıl şeklinde giriniz." << endl;  return gun; }

    for (int i = 0; i < 2; i++) {
        if ((gun[i] >= '0' && gun[i] <= '9') && (ay[i] >= '0' && ay[i] <= '9') && (yil[i] >= '0' && yil[i] <= '9' && yil[i + 2] >= '0' && yil[i + 2] <= '9')) { tarihKontrol = false; }
        else { cout << "Geçersiz tarih!" << endl; return yil; }
    }
    if (gg > 0 && gg < 32 && aa > 0 && aa < 13 && yy < 2004) { tarihKontrol = true; }
    else { cout << "Geçersiz tarih!" << endl; return gun; }
    if (tarihKontrol == true) { return oth; }
}
string mailKontrol(string& oth) {
    int position1 = 0;
    int position2 = 0;

    string temp = oth;
    position1 = temp.find('@');
    temp = temp.erase(0, position1 + 1);
    position2 = temp.find('.');
    if (position1 > 0 && position2 > 0) {
        return oth;
    }
    else {
        cout << "Geçersiz mail adresi!" << endl;
        return temp;
    }
}
string sizekontrol(string& oth) {
    string olcu = oth;
    if ( olcu == "s" || olcu == "m" || olcu == "l") {
        return oth;
    }
    else {
        string k = "gecersiz";
        cout << "Geçersiz boyut kullanımı" << endl;
        return k;
    }
}
string renkkontrol(string& oth) {
    string renk = oth;
    if (renk == "sari"|| renk=="siyah" || renk == "mavi" || renk == "beyaz") {
        return oth;
    }
    else {
        string k = "gecersiz";
        cout << "Geçersiz renk kullanımı" << endl;
        return k;
    }
}

class Kisi {
public:
    char* getAdSoyad();
    void setAdSoyad(char* oth);
    char* getTelno();
    void setTelno(char* oth);
private:
    char* adSoyad;
    char* telNo;
};

char* Kisi::getAdSoyad() {
    return adSoyad;
}
void Kisi::setAdSoyad(char* oth) {
    adSoyad = oth;
}
char* Kisi::getTelno() {
    return telNo;
}
void Kisi::setTelno(char* oth) {
    telNo = oth;
}

class Kullanici :public Kisi
{
public:
    //Kullanici();
    char* getKullaniciAdi();
    void setKullaniciAdi(char* oth);
    char* getSifre();
    void setSifre(char* oth);
    char* getMail();
    void setMail(char* oth);
    char* getAdres();
    void setAdres(char* oth);
    char* getDtarihi();
    void setDtarihi(char* oth);
    char* getKod();
    void setKod(char* oth);
    void kullaniciKayit();
    void kullaniciGiris();
    void sifreDegistir();

private:
    char* kullaniciAdi;
    char* sifre;
    char* mail;
    char* adres;
    char* indirimKodu;
    char* dtarihi;
};
Kullanici k11;
string sss;
char* Kullanici::getKullaniciAdi() {
    return kullaniciAdi;
}
void Kullanici::setKullaniciAdi(char* oth) {
    kullaniciAdi = oth;
}
char* Kullanici::getSifre() {
    return sifre;
}
void Kullanici::setSifre(char* oth) {
    sifre = oth;
}
char* Kullanici::getMail() {
    return mail;
}
void Kullanici::setMail(char* oth) {
    mail = oth;
}
char* Kullanici::getAdres() {
    return adres;
}
void Kullanici::setAdres(char* oth) {
    adres = oth;
}
char* Kullanici::getDtarihi() {
    return dtarihi;
}
void Kullanici::setDtarihi(char* oth) {
    dtarihi = oth;
}
char* Kullanici::getKod() {
    return indirimKodu;
}
void Kullanici::setKod(char* oth) {
    indirimKodu = oth;
}

void Kullanici::kullaniciKayit() {
    fstream dosya;
    Kullanici k1;
    string name, surname, username, number, mail, password, temp, temp2, dob, adres, tercih;
    check = false;
    check2 = true;
    cout << "*****************************************" << endl;
    cout << "****************ÜYE KAYDI****************" << endl;
    cout << "*****************************************" << endl;
    cout << "Geri dönmek ister misiniz(e/..)";
    cin >> tercih;
    while (!(tercih == "e" || tercih == "E")) {
    isim:
        cout << "\tAdınız Soyadınız:";
        cin >> name >> surname;
        name = name + " " + surname;
        temp = isimKontrol(name);
        if (temp == name) { k1.setAdSoyad(const_cast<char*>(name.c_str())); }
        else {
            cout << "Geri dönmek ister misiniz(e/..)";
            cin >> tercih;
            if (!(tercih == "e" || tercih == "E")) { goto isim; }
            else { check2 = false; break; }
        }

    kullaniciAdi:
        cout << "\tKullanıcı Adınız:";
        cin >> username;
        if (username.length() > 4 && username.length() < 16) { k1.setKullaniciAdi(const_cast<char*>(username.c_str())); }
        else { 
            cout << "HATA!Kullanıcı adınız 5-15 karakter arasında olmalı." << endl;
            cout << "Geri dönmek ister misiniz(e/..)";
            cin >> tercih;
            if(!(tercih == "e" || tercih == "E")){ goto kullaniciAdi; }
            else { check2 = false; break; }            
        }
    telno:
        cout << "\tTelefon numaranız:";
        cin >> number;
        temp = numberKontrol(number);
        if (temp == number) { k1.setTelno(const_cast<char*>(number.c_str())); }
        else {
            cout << "Geri dönmek ister misiniz(e/..)";
            cin >> tercih;
            if (!(tercih == "e" || tercih == "E")) { goto telno; }
            else { check2 = false; break; }
        }
    dob:
        cout << "\tDoğum tarihiniz:(gg/aa/yıl)";
        cin >> dob;
        temp = dobKontrol(dob);
        if (temp == dob) { k1.setDtarihi(const_cast<char*>(dob.c_str())); }
        else {
            cout << "Geri dönmek ister misiniz(e/..)";
            cin >> tercih;
            if (!(tercih == "e" || tercih == "E")) { goto dob; }
            else { check2 = false; break; }
        }
    mail:
        cout << "\tMail adresiniz:";
        cin >> mail;
        temp = mailKontrol(mail);
        if (temp == mail) { k1.setMail(const_cast<char*>(mail.c_str())); }
        else {
            cout << "Geri dönmek ister misiniz(e/..)";
            cin >> tercih;
            if (!(tercih == "e" || tercih == "E")) { goto mail; }
            else { check2 = false; break; }
        }
    adres:
        cout << "\tAdresiniz:";
        cin >> adres;
        k1.setAdres(const_cast<char*>(adres.c_str()));
    sifre:
        cout << "\tLütfen şifrenizi oluşturun:";
        hiddenPassword(password);
        k1.setSifre(const_cast<char*>(password.c_str()));
        cout << "\tLütfen şifrenizi tekrar girin:";
        hiddenPassword(temp);

        while (password != temp) {
            cout << "Girdiğiniz şifreler uyuşmadı!" << endl;
            cout << "Geri dönmek ister misiniz(e/..)";
            cin >> tercih;
            if (!(tercih == "e" || tercih == "E")) { goto sifre; }
            else { check2 = false; break; }
        }
        if (password == temp) {
            if (temp.length() > 16 || temp.length() < 8)
            {
                cout << "Girdiğiniz şifre 8-16 karakter arasında olmalıdır." << endl;
                cout << "Geri dönmek ister misiniz(e/..)";
                cin >> tercih;
                if (!(tercih == "e" || tercih == "E")) { goto sifre; }
                else { check2 = false; break; }
            }
            bool upUse = false;
            bool lowUse = false;
            bool numUse = false;
            for (int i = 0; i < temp.length(); i++) {
                if (temp[i] >= 'A' && temp[i] <= 'Z') { upUse = true; }
                if (temp[i] >= 'a' && temp[i] <= 'z') { lowUse = true; }
                if (temp[i] >= '0' && temp[i] <= '9') { numUse = true; }
            }
            if (upUse == true && lowUse == true && numUse == true) {

                cout << "!YENİ kullanıcı başarıyla oluşturuldu." << endl;
                dosya.open("kullanicilar.txt", ios::app);
                dosya << "\n" << k1.getAdSoyad() << "," << k1.getKullaniciAdi() << "," << k1.getSifre() << "," << k1.getTelno() << "," << k1.getDtarihi() << "," << k1.getMail() << "," << k1.getAdres();
                dosya.close();
                check = true;
                break;
            }
            else {
                cout << "HATA!Şifrenizde en az bir sayı,bir küçük harf ve bir büyük harf bulundurmalısınız." << endl;
                cout << "Geri dönmek ister misiniz(e/..)";
                cin >> tercih;
                if (!(tercih == "e" || tercih == "E")) { goto sifre; }
                else { check2 = false; break; }
            }
        }
    }
    check2 = false;
}
void Kullanici::kullaniciGiris() {
    int position1, position2;
    string user, sifre, temp, temp2, myText;
    bool kontrol = false;
    check = false;
    cout << "***************************************" << endl;
    cout << "*************MÜŞTERİ GİRİŞİ************" << endl;
    cout << "***************************************" << endl;
    cout << "\tKullanıcı Adınız:";
    cin >> user;
    cout << "\tŞifreniz:";
    hiddenPassword(sifre);
    fstream dosya,log;
    dosya.open("kullanicilar.txt", ios::in);
    while (getline(dosya, myText)) {
        temp = myText;
        position1 = temp.find(",");
        temp = temp.erase(0, position1 + 1);
        position2 = temp.find(",");
        temp2 = temp.substr(0, position2);
        temp = temp.erase(0, position2 + 1);
        if (temp2 == user) {
            position1 = temp.find(',');
            temp2 = temp.substr(0, position1);
            if (temp2 == sifre) { 
                kontrol = true;
                log.open("log.txt", ios::out);
                log << user << endl;
                log.close();
                break; }
            else { continue; }
        }
        else { continue; }
    }
    dosya.close();
    if (kontrol == true) { 
        cout << "!Giriş başarılı" << endl; 
        k11.setKullaniciAdi(const_cast<char*>(user.c_str()));
        k11.setSifre(const_cast<char*>(sifre.c_str()));
        sss= k11.getSifre();
        check = true; 
    }
    else { cout << "HATA!Giriş başarısız" << endl; }
    
}

class Yonetici :public Kisi {
public:
    //Yonetici();
    char* getSifre();
    void setSifre(char* oth);
    void yoneticiEkle();
    void yoneticiGiris();
    void kodTanimlama();

private:
    char* sifre;
};
string userGlobal;
char* Yonetici::getSifre() {
    return sifre;
}
void Yonetici::setSifre(char* oth) {
    sifre = oth;
}

void Yonetici::yoneticiEkle() {
    fstream dosya;
    Yonetici y1;
    string name, surname, number, mail, password, temp, temp2;
    check = false;
    check2 = true;
    cout << "*****************************************" << endl;
    cout << "**************YÖNETİCİ EKLE**************" << endl;
    cout << "*****************************************" << endl;
    cout << "\tAdı Soyadı:";
    cin >> name >> surname;
    name = name + " " + surname;
    temp = isimKontrol(name);
    if (temp == name) { y1.setAdSoyad(const_cast<char*>(name.c_str())); }
    else { check2 = false; }

    if (check2 == true) {
        cout << "\tTelefon Numarası:";
        cin >> number;
        temp = numberKontrol(number);
        if (temp == number) { y1.setTelno(const_cast<char*>(number.c_str())); }
        else { check2 = false; }
        if (check2 == true) {
            cout << "\tLütfen şifre oluşturun:";
            hiddenPassword(password);
            y1.setSifre(const_cast<char*>(password.c_str()));
            cout << "\tLütfen şifreyi tekrar girin:";
            hiddenPassword(temp);

            while (password != temp) {
                cout << "Girdiğiniz şifreler uyuşmadı!" << endl;
                check2 = false;
                break;
            }
            if (password == temp) {
                if (temp.length() > 16 || temp.length() < 8)
                {
                    cout << "Girdiğiniz şifre 8-16 karakter arasında olmalıdır." << endl;
                    check2 = false;
                }
                bool upUse = false;
                bool lowUse = false;
                bool numUse = false;
                for (int i = 0; i < temp.length(); i++) {
                    if (temp[i] >= 'A' && temp[i] <= 'Z') { upUse = true; }
                    if (temp[i] >= 'a' && temp[i] <= 'z') { lowUse = true; }
                    if (temp[i] >= '0' && temp[i] <= '9') { numUse = true; }
                }
                if (upUse == true && lowUse == true && numUse == true) {

                    cout << "!YENİ kullanıcı başarıyla oluşturuldu." << endl;
                    dosya.open("kullanicilar.txt", ios::app);
                    dosya << "\n" << y1.getAdSoyad() << "," << y1.getSifre() << "," << y1.getTelno();
                    dosya.close();
                    check = true;
                }
                else {
                    cout << "HATA!Şifrenizde en az bir sayı,bir küçük harf ve bir büyük harf bulundurmalısınız." << endl;
                    check2 = false;
                }
            }
        }
    }
}
void Yonetici::yoneticiGiris() {
    int position1, position2;
    string name, surname, sifre, temp, temp2, myText, tercih;
    bool kontrol = false;
    check = false;
    cout << "*****************************************" << endl;
    cout << "**************YÖNETİCİ GİRİŞİ************" << endl;
    cout << "*****************************************" << endl;
    cout << "\tAdınız-Soyadınız:";
    cin >> name >> surname;
    name = name + ' ' + surname;
    cout << "\tŞifreniz:";
    hiddenPassword(sifre);
    fstream dosya;
    dosya.open("kullanicilar.txt", ios::in);
    while (getline(dosya, myText)) {
        temp = myText;
        position1 = temp.find(",");
        temp2 = temp.substr(0, position1);
        temp = temp.erase(0, position1 + 1);
        position2 = temp.find(",");
        if (temp2 == name) {
            position1 = temp.find(',');
            temp2 = temp.substr(0, position1);
            if (temp2 == sifre) { kontrol = true; break; }
            else { continue; }
        }
        else { continue; }
    }
    if (kontrol == true) { cout << "!Giriş başarılı" << endl; check = true; }
    else { cout << "HATA!Giriş başarısız" << endl; }
    dosya.close();
}
void Yonetici::kodTanimlama() {
    fstream dosya;
    string myText,temp,user,kod,temp2,temp3;
    int position;
durum12:
    cout << "Tanımlayacağınız kullanıcı adı:";
    cin >> user;
    dosya.open("kullanicilar.txt",ios::in);
    while (getline(dosya, myText)) {
        temp3 +=myText+"\n";
    }
    dosya.close();
    dosya.open("kullanicilar.txt", ios::in);
    while (getline(dosya, myText)) {
        temp = myText;
        temp2 +="\n"+myText;
        position = temp.find(",");
        temp = temp.erase(0, position + 1);
        position = temp.find(",");
        temp = temp.substr(0, position);
        if (user == temp) {
            dosya.close();
            dosya.open("kullanicilar.txt", ios::out);
            cout << "İndirim kodu:";
            cin >> kod;
            temp2 = temp2 + "-" + kod+"\n";
            temp3.erase(0, temp2.find(kod)-1);
            dosya << temp2+temp3;
            dosya.close();
        }
    }

}

class Kiyafet {
public:
    char* getKategori();
    void setKategori(char* oth);
    char* getBoyut();
    void setBoyut(char* oth);
    char* getRenk();
    void setRenk(char* oth);
    double getFiyat();
    void setFiyat(double oth);
    int getKiyafetAdi();
    void setKiyafetAdi(int oth);
    void kiyafet_ekle();
    void show(int oth);
private:
    char* kategori;
    char* boyut;
    char* renk;
    int kiyafet_adi;
    double fiyat;

};

char* Kiyafet::getKategori() {
    return kategori;
}
void Kiyafet::setKategori(char* oth) {
    kategori = oth;
}
char* Kiyafet::getBoyut() {
    return boyut;
}
void Kiyafet::setBoyut(char* oth) {
    boyut = oth;
}
char* Kiyafet::getRenk() {
    return renk;
}
void Kiyafet::setRenk(char* oth) {
    renk = oth;
}
int Kiyafet::getKiyafetAdi() {
    return kiyafet_adi;
}
void Kiyafet::setKiyafetAdi(int oth) {
    kiyafet_adi = oth;

}
double Kiyafet::getFiyat() {
    return fiyat;
}
void Kiyafet::setFiyat(double oth) {
    fiyat = oth;
}

void Kiyafet::kiyafet_ekle() {
    fstream dosya;
    Kiyafet x1;
    string nsize, color,terch, tamb, iss,kate, choose;
    int c;
    double fiat;
    check = false;
    check2 = true;
    durum3:
    cout << "Hangi kategoriye urun ekleyeceksiniz?" << endl;
    cout << "\t1.Elbise\n" << "\t2.Tisort\n" << "\t3.Pantolon\n" << "\t4.Gomlek\n"
        << "\t5.Etek\n" << "\t6.Ayakkabi\n" << endl;
    cout << "Secmek istediginiz kategori:";
    cin >> choose;
    if (choose == "1") {
        kate = "Elbise-";
        x1.setKategori(const_cast<char*>(kate.c_str()));
        dosya.open("kiyafet.txt", ios::app);
        dosya << x1.getKategori();
        dosya.close();
    }
    else if (choose == "2") {
        kate = "Tisort-";
        x1.setKategori(const_cast<char*>(kate.c_str()));
        dosya.open("kiyafet.txt", ios::app);
        dosya << x1.getKategori();
        dosya.close();
    }
    else if (choose == "3") {
        kate = "Pantolon-";
        x1.setKategori(const_cast<char*>(kate.c_str()));
        dosya.open("kiyafet.txt", ios::app);
        dosya << x1.getKategori();
        dosya.close();
    }
    else if (choose == "4") {
        kate = "Gomlek-";
        x1.setKategori(const_cast<char*>(kate.c_str()));
        dosya.open("kiyafet.txt", ios::app);
        dosya << x1.getKategori();
        dosya.close();
    }
    else if (choose == "5") {
        kate = "Etek-";
        x1.setKategori(const_cast<char*>(kate.c_str()));
        dosya.open("kiyafet.txt", ios::app);
        dosya << x1.getKategori();
        dosya.close();
    }
    else if (choose == "6") {
        kate = "Ayakkabi-";
        x1.setKategori(const_cast<char*>(kate.c_str()));
        dosya.open("kiyafet.txt", ios::app);
        dosya << x1.getKategori();
        dosya.close();
    }
    else {
        cout << "Boyle bir kategori bulanamadı." << endl;
        goto durum3;
    }

    
    cout << "Geri dönmek ister misiniz(e/..)";
    cin >> terch;
    while (!(terch == "e" || terch == "E")) {
        renk:
        cout << "Girmek istediginiz kiyafetin rengi:";
        cin >> color;
        tamb = renkkontrol(color);
        if (tamb == color) {
            x1.setRenk(const_cast<char*>(color.c_str()));
        }
        else {
            cout << "Geri dönmek ister misiniz(e/..)";
            cin >> terch;
            if(!(terch == "e" || terch == "E")){ goto renk; }    
            else {
                check2 = false; 
                break;
            }
        }
        size:
        cout << "Girmek istediginiz urunun olcusu:";
        cin >> nsize;
        tamb = sizekontrol(nsize);
        if (tamb == nsize) {
            x1.setBoyut((const_cast<char*>(nsize.c_str())));
        }
        else {
            cout << "Geri dönmek ister misiniz(e/..)";
            cin >> terch;
            if (!(terch == "e" || terch == "E")) { goto size; }
            else {
                check2 = false;
                break;
            }
        }

        cout << "Girmek istediginiz kiyafetin adi:";
        cin >> iss;
        c = stoi(iss);
        x1.setKiyafetAdi(c);
        cout << "Girmek istediginiz kiyafet fiyati:";
        cin >> iss;
        fiat = stod(iss);
        x1.setFiyat(fiat);
        cout << "Yeni kiyafet başarıyla eklendi." << endl;
        dosya.open("kiyafet.txt", ios::app);
        dosya << '\n' << x1.getKiyafetAdi() << "," << x1.getFiyat() << "," << x1.getRenk() << "," << x1.getBoyut() << endl;
        dosya.close();
        check = true;
        break;
    }
    check2 = false;
}

class Kurye : public Kisi
{
public:
    //Kurye
    void kuryeekle();

};

void Kurye::kuryeekle() {
    fstream dosya;
    Kurye m1;
    string name, surname, number, terch, tamb;
    check = false;
    check2 = true;
    cout << "*****************************************" << endl;
    cout << "***************KURYE KAYDI***************" << endl;
    cout << "*****************************************" << endl;
durum2:
    cout << "Geri dönmek ister misiniz(e/..)";
    cin >> terch;
    while (!(terch == "e" || terch == "evet")) {
        cout << "\tAdınız Soyadınız:";
        cin >> name >> surname;
        name = name + " " + surname;
        tamb = isimKontrol(name);
        if (tamb == name) { m1.setAdSoyad(const_cast<char*>(name.c_str())); }
        else { check2 = false; goto durum2; }

        cout << "\tTelefon numaranız:";
        cin >> number;
        tamb = numberKontrol(number);
        if (tamb == number) {
            m1.setTelno(const_cast<char*>(number.c_str()));
            cout << "!YENİ kurye başarıyla oluşturuldu." << endl;
            dosya.open("kullanicilar.txt", ios::app);
            dosya << "\n" << m1.getAdSoyad() << "," << m1.getTelno();
            dosya.close();
            check = true;
            break;

        }
        else { check2 = false; goto durum2; }
    }
    check2 = false;
}
void Kullanici::sifreDegistir() {
    fstream dosya;
    string myText, temp, user, kod, temp2, temp3,temp4,temp5,gecici;
    int position;
    string tercih;
    cout << "*****************************************" << endl;
    cout << "**************ŞİFRE DEĞİŞTİR*************" << endl;
    cout << "*****************************************" << endl;
    cout << "Eski şifrenizi girin:";
    hiddenPassword(tercih);
    if (tercih == sss) {
        dosya.open("kullanicilar.txt", ios::in);
        while (getline(dosya, myText)) {
            temp3 += myText + "\n";
        }
        dosya.close();
        dosya.open("kullanicilar.txt", ios::in);
        while (getline(dosya, myText)) {
            temp = myText;
            position = temp.find(",");
            temp4=temp.substr(0, position+1);
            temp = temp.erase(0, position + 1);
            position = temp.find(",");
            temp4+= temp.substr(0, position+1);
            temp = temp.erase(0, position + 1);
            position = temp.find(",");
            temp5 = temp;
            temp5= temp5.erase(0, position + 1);
            temp = temp.substr(0, position);
            if (tercih == temp) {
                dosya.close();
                dosya.open("kullanicilar.txt", ios::out);
                cout << "Yeni şifre:";
                hiddenPassword(kod);               
                temp3=temp3.erase(0, temp3.find(temp5));
                temp2 = temp2 +"\n"+temp4 + kod + ",";
                dosya << temp2+temp3;
                dosya.close();
                break;
            }
            else {
                temp2 += "\n" + myText;
                temp4 = "";
                temp5 = "";
            }
        }
    }
    else {
        cout << "Eski şifreniz hatalı." << endl;
    }

}
void Kiyafet::show(int x) {
    fstream dosya, dosya2;
    string myText, temp, temp2 = "s", temp3, tercih, choose2;
    int position, position2 = 0, choose;
    check = false;
    bool kontrol = false;
    ofstream myFile("siparis.txt");
    ofstream myFile2("temp.txt");
    fstream siparis, log;
    if (x > 0 && x <= 6) { cout << "\n\tKategori-ID,Fiyat" << endl; }
    dosya.open("kiyafet.txt", ios::in);
    if (x != 7) {
        while (getline(dosya, myText)) {
            temp = myText;
            if (!(temp2 == temp.substr(0, temp.find(",")))) {
                temp2 = temp.substr(0, temp.find(","));
                position = temp.find("0") + 1;
                temp = temp.substr(0, position);
                if (x == 1) {
                    position2 = temp.find("Elbise");
                    if (position2 >= 0) { check = true; cout << "\t" << temp << endl; }
                }
                if (x == 2) {
                    position2 = temp.find("Tisort");
                    if (position2 >= 0) { check = true; cout << "\t" << temp << endl; }
                }
                if (x == 3) {
                    position2 = temp.find("Pantolon");
                    if (position2 >= 0) { check = true; cout << "\t" << temp << endl; }
                }
                if (x == 4) {
                    position2 = temp.find("Gomlek");
                    if (position2 >= 0) { check = true; cout << "\t" << temp << endl; }
                }
                if (x == 5) {
                    position2 = temp.find("Etek");
                    if (position2 >= 0) { check = true; cout << "\t" << temp << endl; }
                }
                if (x == 6) {
                    position2 = temp.find("Ayakkabi");
                    if (position2 >= 0) { check = true; cout << "\t" << temp << endl; }
                }
            }
        }
        dosya.close();
        cout << "Geri donmek ister misiniz?(e/..)";
        cin >> tercih;
        if (tercih == "e" || tercih == "E") { show(x); }
        else {
            cout << "Almak istediğiniz ürünün idsini giriniz:";
            cin >> tercih;
            dosya.open("kiyafet.txt", ios::in);
            while (getline(dosya, myText)) {
                temp = myText;
                temp2 = temp.substr(temp.find("-") + 1, 4);
                if (tercih == temp2) {
                    temp2 = temp;
                    kontrol = true;
                    myFile.open("siparis.txt", ios::out | ios::app);
                    myFile << temp << endl;
                    myFile.close();
                }
            }
            if (kontrol == false) { cout << "!Böyle bir id bulunamadı." << endl; show(x); }
            dosya.close();
        }
        cout << "Hangi renk almak istersiniz?(beyaz-siyah-sari-mavi)";
        cin >> choose2;
        cout << endl;
        if (renkkontrol(choose2) == choose2) {
            dosya2.open("siparis.txt", ios::in);
            cout << "\tKategori-ID,Fiyat,Renk,Beden" << endl;
            while (getline(dosya2, myText)) {
                temp = myText;
                temp2 = temp.substr(temp.find("0") + 2, choose2.length());
                if (choose2 == temp2) {
                    dosya.open("temp.txt", ios::app);
                    dosya << temp << " " << endl;
                    cout << "\t" << temp << endl;
                    dosya.close();
                }
            }
            dosya2.close();
            remove("siparis.txt");
        }
        else { show(x); }
        cout << "Geri donmek ister misiniz?(e/..)";
        cin >> tercih;
        if (tercih == "e" || tercih == "E") { show(x); }
        else {
            cout << "Hangi beden almak istersiniz?";
            cin >> choose2;
        }

        choose2 += " ";
        dosya.open("temp.txt", ios::in);
        string fullname;
        while (getline(dosya, myText)) {
            temp = myText;
            temp2 = temp.substr(temp.find(" ") - 1);
            log.open("log.txt", ios::in);
            getline(log, fullname, '\n');
            if (choose2 == temp2) {
                string y;
                cout << "Geri dönmek için 0'a, Sepete eklemek için 1'i seçiniz..." << endl;
                cin >> y;
                if (y != "0") {
                    cout << "Seçiminiz sepetinize eklendi." << endl;
                    dosya2.open("sepetim.txt", ios::app);
                    dosya2 << "\n" << fullname << "," << temp;
                }

            }
        }
        dosya2.close();
        dosya.close();
        fstream out;
        dosya2.open("sepetim.txt", ios::in);
        out.open("newSepetim.txt", ios::out);

        string readin;
        while (!dosya2.eof())
        {
            getline(dosya2, readin);
            if (readin != "")
            {
                out << readin << endl;
            }
        }
        dosya2.close();
        out.close();
        out.open("newSepetim.txt", ios::in);
        dosya2.open("sepetim.txt", ios::out);
        while (!out.eof())
        {
            getline(out, readin);
            if (readin != "")
            {
                dosya2 << readin << endl;
            }
        }
        dosya2.close();
        out.close();
        remove("newSepetim.txt");
        remove("temp.txt");
    }
    else { check = false; }

}
class Sepet {
public:
    void ozet();
    double total = 0;
private:

};
void Sepet::ozet() {
    string kategori, id, size, color, price, girdi, fullname, tercih, myText, temp4;
    fstream siparis, log, fatura, temp, dosya, temp2, temp5, tempkisi, tempsiparis;
    string name, username, password, number, dob, mail, adres, kod, ikod, temp3;
    int position;
    log.open("log.txt", ios::in);
    getline(log, girdi, '\n');
    log.close();
    double total = 0, inkod = 0;
    cout << "**************************" << endl;
    cout << "**********FATURA**********" << endl;
    cout << "**************************" << endl;
    cout << "Kullanıcı:" << girdi << endl;
    dosya.open("kullanicilar.txt", ios::in);
    tempkisi.open("tempkisi.txt", ios::out);
    while (!dosya.eof()) {
        getline(dosya, temp4, '\n');
        position = temp4.find(girdi);
        if (position >= 0) {
            position = -1;
            tempkisi << temp4 << endl;
        }
    }
    dosya.close();
    tempkisi.close();
    tempkisi.open("tempkisi.txt", ios::in);
    temp2.open("temp2.txt", ios::out);
    temp5.open("temp5.txt", ios::out);
    while (!tempkisi.eof()) {
        getline(tempkisi, temp4, '\n');
        position = temp4.find("-");
        if (position >= 0) {
            position = -1;
            temp2 << temp4 << endl;
            goto cart1;
        }
        else {
            temp5 << temp4 << endl;
            goto cart2;
        }
    }
cart1:
    tempkisi.close();
    temp2.close();
    temp5.close();
    temp2.open("temp2.txt", ios::in);
    tempkisi.open("tempkisi.txt", ios::out);
    while (!temp2.eof()) {
        getline(temp2, name, ',');
        getline(temp2, username, ',');
        getline(temp2, password, ',');
        getline(temp2, number, ',');
        getline(temp2, dob, ',');
        getline(temp2, mail, ',');
        getline(temp2, adres, '-');
        getline(temp2, kod, '\n');
        if (girdi == username) {
            tempkisi << name << "," << number << "," << mail << "," << adres << endl;
            ikod = kod;
            goto cart11;
        }
    }
cart11:
    tempkisi.close();
    temp2.close();
    goto calculate;
cart2:
    temp2.close();
    temp.close();
    temp5.close();
    temp5.open("temp2.txt", ios::in);
    tempkisi.open("tempkisi.txt", ios::out);
    while (!temp2.eof()) {
        getline(temp2, name, ',');
        getline(temp2, username, ',');
        getline(temp2, password, ',');
        getline(temp2, number, ',');
        getline(temp2, dob, ',');
        getline(temp2, mail, ',');
        getline(temp2, adres, '\n');
        if (girdi == username) {
            tempkisi << name << "," << number << "," << mail << "," << adres << endl;
            ikod = "";
            goto cart12;
        }
    }
cart12:
    tempkisi.close();
    temp5.close();
calculate:
    if (ikod == "YENIYIL20") { inkod = 20; }
    if (ikod == "YENIYIL30") { inkod = 30; }
    if (ikod == "YENIYIL40") { inkod = 40; }
    if (ikod == "") { inkod = 0; }

    siparis.open("sepetim.txt", ios::in);
    temp.open("temp.txt", ios::out);
    while (!siparis.eof()) {
        getline(siparis, fullname, ',');
        getline(siparis, kategori, ',');
        getline(siparis, price, ',');
        getline(siparis, color, ',');
        getline(siparis, size, '\n');
        double price_temp = stod(price);
        if (girdi == fullname) {
            total += price_temp + 0.9;
            temp << kategori << "," << size << "," << color << "," << price << endl;
            cout << "\t" << kategori << "-" << size << "|" << color << "|" << price << " TL" << endl;
        }
    }
    total -= inkod;
    temp.close();
    siparis.close();
    cout << "İndirim Tutarınız:" << inkod << "TL" << endl;
    cout << "Fatura Tutarınız:" << total << "TL" << endl;
    cout << "Sepeti onaylamak için lütfen 0'a basınız..." << endl << "Çıkış yapmak için 2'ye basınız..." << endl;
    cin >> tercih;
    if (tercih == "0") {
        siparis.open("sepetim.txt", ios::in);
        tempsiparis.open("tempsiparis.txt", ios::out);
        while (!siparis.eof()) {
            getline(siparis, temp4, '\n');
            position = temp4.find(girdi);
            if (position >= 0) {
                position = -1;
            }
            else {
                tempsiparis << temp4 << endl;
            }
        }
        tempsiparis.close();
        siparis.close();
        siparis.open("sepetim.txt", ios::out);
        tempsiparis.open("tempsiparis.txt", ios::in);
        while (!tempsiparis.eof()) {
            getline(tempsiparis, temp4, '\n');
            siparis << temp4 << endl;
        }
        tempsiparis.close();
        siparis.close();
        remove("tempsiparis.txt");
        tempkisi.open("tempkisi.txt", ios::in);
        fatura.open("fatura.txt", ios::app);
        while (!tempkisi.eof()) {
            getline(tempkisi, myText, '\n');
            fatura << myText << endl;
        }

        fatura.close();
        tempkisi.close();
        temp.open("temp.txt", ios::in);
        fatura.open("fatura.txt", ios::app);
        while (!temp.eof()) {
            getline(temp, myText, '\n');
            fatura << myText << endl;
        }
        fatura << "İndirim Tutarınız:" << inkod << "TL" << endl;
        fatura << "Fatura Tutarınız:" << total << "TL" << endl;
        fatura << "||" << endl;
        fatura.close();
        temp.close();
        remove("tempkisi.txt");
    }
    remove("temp.txt");
    remove("temp2.txt");
    remove("temp5.txt");
}
class Feedback {
public:
    void sikayetOneri();
private:
};
void Feedback::sikayetOneri() {
    string fullname, check;
    string feedback, f1;
    fstream sikayet;
    fstream log;
    log.open("log.txt", ios::in);
    sikayet.open("oneri.txt", ios::app);
    getline(log, fullname, '\n');
    cout << "*****************************************" << endl;
    cout << "*************ŞİKAYET ve ÖNERİ************" << endl;
    cout << "*****************************************" << endl;
    cout << "Geri dönmek için (0), Devam etmek için (1)..." << endl;
    cin >> check;
    if (check != "0") {
        feedback = " ";
        cout << "Lütfen şikayet-önerinizi Yazınız ";
        cin >> feedback;
        getline(cin, f1);

        sikayet << "\n" << fullname << "->";
        sikayet << feedback << f1 << endl;

        log.close();
        sikayet.close();
        cout << "Bildiriminiz için teşekkürler..." << endl;
    }
}

void displayMenu()
{
    Kullanici k2;
    Yonetici y1;
    Kiyafet x1;
    Kurye m1;
    Sepet s1;
    Feedback f1;
    int choose = 0;
    string tercih;
    fstream dosya;
    fstream fatura;
    string temp, myText,name,temp2,kate;
    bool kontrol = false;
    int x, y;
Giris:
    cout << "*****************************************" << endl;
    cout << "***************HOŞGELDİNİZ***************" << endl;
    cout << "*****************************************" << endl;
    cout << "\t1-> Sisteme giriş\n\t2-> Üye kaydı\n\t3-> Çıkış " << endl;
    cout << "*****************************************" << endl;
    cout << "Lütfen yapmak istediğiniz işlemi tuşlayın: ";
    cin >> choose;
    cout << endl;
    switch (choose)
    {
    case 1:
    girisEkrani:
        cout << "*****************************************" << endl;
        cout << "***************GİRİŞ EKRANI**************" << endl;
        cout << "*****************************************" << endl;
        cout << "\t1-> Yönetici Girişi\n\t2-> Müşteri Girişi\n\t3-> Ana Menüye Dön" << endl;
        cout << "*****************************************" << endl;
        cout << "Lütfen yapmak istediğiniz işlemi tuşlayın: ";
        cin >> choose;
        cout << endl;
        switch (choose) {
        case 1:
        yoneticiGiris:
            y1.yoneticiGiris();
            if (check == true) {
            yoneticiEkrani:
                cout << "*****************************************" << endl;
                cout << "**************YÖNETİCİ EKRANI************" << endl;
                cout << "*****************************************" << endl;
                cout << "\t1-> Kıyafet kategorilerinin yer aldığı dosyalara ürün girişi yapma\n"
                    << "\t2-> Sisteme kurye ekleme\n"
                    << "\t3-> Sisteme yeni yönetici ekleme\n"
                    << "\t4-> Yapılan siparişlerin faturalarını görüntüle\n"
                    << "\t5-> Kullanıcıya indirim kodu tanımlama\n"
                    << "\t6-> Şikâyet ve öneri okuma\n"
                    << "\t7-> Giriş ekranına dön" << endl;
                cout << "*****************************************" << endl;
                cout << "Lütfen yapmak istediğiniz işlemi tuşlayın: ";
                cin >> choose;
                switch (choose) {
                case 1:
                    x1.kiyafet_ekle();
                    if (check == true) { goto yoneticiEkrani; }
                    if (check2 == false) { goto yoneticiEkrani; }
                    break;
                case 2:
                kuryeekle:
                    m1.kuryeekle();
                    if (check == true) { goto yoneticiEkrani; }
                    if (check2 == false) { goto yoneticiEkrani; }
                    break;
                case 3:
                yoneticiEkle:
                    y1.yoneticiEkle();
                    if (check2 == false) {
                        cout << "Geri dönmek ister misiniz?(e/..)";
                        cin >> tercih;
                        if (tercih == "e" || tercih == "E") {
                            goto yoneticiEkrani;
                        }
                        else { goto yoneticiEkle; }
                    }
                    if (check == true) { goto yoneticiEkrani; }
                    break;
                case 4:
                    fatura.open("fatura.txt", ios::in);
                    while (!fatura.eof()) {
                        getline(fatura, myText, '\n');
                        cout << myText << endl;
                    }
                    fatura.close();
                    break;
                case 5:
                    y1.kodTanimlama();
                    goto yoneticiEkrani;
                    break;
                case 6:
                    dosya.open("oneri.txt", ios::in);
                    while (!dosya.eof()) {
                        getline(dosya, myText, '\n');
                        cout << myText << endl;
                    }
                    dosya.close();
                    cout << "Geri dönmek ister misiniz?(e/..)";
                    cin >> tercih;
                    if (tercih == "e" || tercih == "E") {
                        goto yoneticiEkrani;
                    }
                    else { goto yoneticiEkle; }
                    break;
                case 7:
                    goto girisEkrani;
                    break;
                }

            }
            else {
                cout << "Geri dönmek ister misiniz?(e/..)";
                cin >> tercih;
                if (tercih == "e" || tercih == "E") { goto girisEkrani; }
                else { goto yoneticiGiris; }
            }
            break;

        case 2:
        kullaniciGiris:
            k2.kullaniciGiris();
            if (check == true) {
            kullaniciEkrani:
                cout << "*****************************************" << endl;
                cout << "*************KULLANICI EKRANI************" << endl;
                cout << "*****************************************" << endl;
                cout << "\t1-> Kıyafet kategorilerinin gösterimi ve ürün seçimi\n"
                    << "\t2-> Sepet Görüntüle\n"
                    << "\t3-> Sipariş Takip\n"
                    << "\t4-> Şikayet / Öneriler(Geri bildirimler)\n"
                    << "\t5-> Şifre Değiştir\n"
                    << "\t6-> Giriş Ekranına Dön\n"
                    << "\t7-> Çıkış" << endl;
                cout << "*****************************************" << endl;
                cout << "Lütfen yapmak istediğiniz işlemi tuşlayın: ";
                cin >> choose;
                switch (choose) {
                case 1:
                kategori:
                    cout << "*****************************************" << endl;
                    cout << "*****************ÜRÜNLER*****************" << endl;
                    cout << "*****************************************" << endl;
                    cout << "\t1-Elbise\n"
                        << "\t2-Tişört\n"
                        << "\t3-Pantolon\n"
                        << "\t4-Gömlek\n"
                        << "\t5-Etek\n"
                        << "\t6-Ayakkabı\n"
                        << "Görüntülemek istediğiniz kategoriyi seçiniz: " << endl;
                    cout << "Geri dönmek ister misiniz?(0)" << endl;
                    cin >> x;
                    if (x == 0) { goto kullaniciEkrani; }
                    x1.show(x);

                    goto kategori;
                    break;
                case 2:
                    s1.ozet();
                    goto kullaniciEkrani;
                    break;
                case 3:
                    break;
                case 4:
                    f1.sikayetOneri();
                    goto kullaniciEkrani;
                    break;
                case 5:
                    k2.sifreDegistir();
                    goto kullaniciEkrani;
                    break;
                case 6:
                    goto girisEkrani;
                    break;
                case 7:
                    remove("log.txt");
                    remove("siparis.txt");
                    exit(0);
                    break;
                }
            }
            else {
                cout << "Geri dönmek ister misiniz?(e/..)";
                cin >> tercih;
                if (tercih == "e" || tercih == "E") { goto girisEkrani; }
                else { goto kullaniciGiris; }
            }
            break;

        case 3:
            displayMenu();
        }
        break;

    case 2:
    kullaniciKayit:
        k2.kullaniciKayit();
        if (check == true) { goto Giris; }
        if (check2 == false) { goto Giris; }
        break;

    case 3:
        remove("log.txt");
        remove("log.txt");
        remove("siparis.txt");
        exit(0);
        break;
    }
}

int main()
{ 
    setlocale(LC_ALL, "Turkish");
    displayMenu();

    return 0;
}