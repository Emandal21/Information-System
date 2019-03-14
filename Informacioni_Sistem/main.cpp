#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <string>
#include "student.h"
using namespace std;

string toStr(int x) {
    string rjesenje = "";
    if(x==5) rjesenje="5";
    if(x==6) rjesenje="6";
    if(x==7) rjesenje="7";
    if(x==8) rjesenje="8";
    if(x==9) rjesenje="9";
    if(x==10) rjesenje="10";
    return rjesenje;
}

void sistemOcjenjivanja() {
    cout << "Dobrodosli na ISSS." << endl;
    cout << "Ulogujte se:\n1.Admin\n2.Student" << endl << endl;
}

/************************************************ ADMIN ************************************************/

void admin(string& student) {

    Sleep(1500); system("cls");
    cout<<"Izaberite studenta: "<<endl;

    ifstream izbori;
    vector<string> studenti;
    izbori.open("studenti.txt", ios::app);
    string nesto;
    while(!(izbori.eof())){
        getline(izbori, nesto);
        studenti.push_back(nesto);
    }

    for(int i=0; i<studenti.size(); i++) {
        cout << i+1 << ". " << studenti[i] << endl;
    }

    int izbor;
    cin>>izbor;
    while(izbor<1 || izbor>studenti.size()){
        cout<<"Pogresan izbor! Probajte ponovo."<<endl;
        Sleep(1500);
        system("cls");
        for(int i=0; i<studenti.size(); i++) {
            cout << i+1 << ". " << studenti[i] << endl;
        }
        cin>>izbor;
    }
    izbori.close();
    nesto = studenti[izbor-1];

    student = nesto+".txt";
}

/************************************************ MAIN ************************************************/

int main()
{
    sistemOcjenjivanja();
    int izbor; cin >> izbor;
    while(izbor!=1 && izbor!=2) {
        cout<<"Pogresan unos! Probajte ponovo" << endl;
        Sleep(1500); system("cls");
        cout << "Ulogujte se:\n1.Admin\n2.Student" << endl << endl;
        cin>>izbor;
    }
    string student="";

    /** Logovanje **/
    if(izbor == 1) {

        system("cls");
        cout << "Unesite password: " << endl;
        string pasvord = "jasamAdmin123";
        string novi_pass = "";
        cin >> novi_pass;

        /** Provjera pw **/
        while(novi_pass != pasvord) {
            cout << "Neispravan unos! Probajte ponovo: " << endl << endl;
            Sleep(1500); system("cls");
            cout << "Unesite password: " << endl;
            cin >> novi_pass;
        }

        admin(student);

        /***/
        string ime="", prezime="";

        int indeks=0;
        for(int i=0; i<student.length(); i++) {
            if(student[i] == ' ') {
                indeks = i;
                break;
            }
        }

        for(int i=0; i<indeks; i++) {
            ime += student[i];
            }

        for(int i=indeks+1; i<student.length()-4; i++) { /** Ide do -4 jer odbijam .txt **/
            prezime += student[i];
            }

        cout << ime << " " <<  prezime << endl << endl;
        /***/

        ifstream ispis;

        ispis.open(student.c_str()); /** Mora primati cstring **/
        vector<string> podaci;

        while(!(ispis.eof())) {
            getline(ispis, student);
            podaci.push_back(student);
        }
        ispis.close();
        ofstream nesto;
        string fajl = ime+" "+prezime+".txt";
        nesto.open(fajl.c_str());
        nesto.clear();
        nesto.close();

//        for(int j=0; j<podaci.size(); j++) {
//            cout << podaci[j] << endl;
//        }

        StudentICiklusa objekat(ime, prezime, 222, 1);
        int semest=1;

        while(semest<7){
            /*objekat.postaviSemestar(semest);
            objekat=objekat;
            cout<<objekat.vratiSemestar()<<endl;
            objekat.upisiOcjene();*/
            StudentICiklusa objekat(ime, prezime, 222, semest);
            bool polozioSemestar = true;
            int brojac=5;

            if(semest==3 or semest==4 or semest==6) brojac=6;

            for(int i=0; i<brojac; i++) {
                    if((objekat.vratiPredmet(i)).getOcjenu() == 5) {
                        polozioSemestar = false;
                    }
                }

            while(polozioSemestar == false){
                for(int i=0; i<brojac; i++) {
                    if((objekat.vratiPredmet(i)).getOcjenu() <= 5) {
                        cout<<"Unesite novu ocjenu za predmet: "<<objekat.vratiPredmet(i).getNaziv()<<endl;
                        int ocjena;
                        cin>>ocjena;
                        string pr=objekat.vratiPredmet(i).getNaziv();
                        objekat.ocijeni(pr, ocjena);
                    }
                }

                cout<<objekat.vratiPredmet(0).getOcjenu();

                polozioSemestar = true;

                for(int i=0; i<brojac; i++) {
                    if((objekat.vratiPredmet(i)).getOcjenu() == 5) {
                        polozioSemestar = false;
                        break;
                    }
                }
            }

            cout<<"STUDENT JE USPJESNO ZAVRSIO "<<semest<<". SEMSTAR!"<<endl;
            Sleep(1500); system("cls");
            semest++;
            ofstream unos;
            string fajl = ime+" "+prezime+".txt";
            unos.open(fajl.c_str(), ios_base::app);

            vector<string> upisi_predmete;
            vector<int> upisi_ocjene;

            for(int i=0; i<brojac; i++){
                upisi_predmete.push_back(objekat.vratiPredmet(i).getNaziv());
                upisi_ocjene.push_back(objekat.vratiPredmet(i).getOcjenu());
            }

            for(int i=0; i<brojac; i++){
                string ispis="\n"+upisi_predmete[i]+" "+toStr(upisi_ocjene[i]);
                unos<<ispis;
            }

            unos.close();
        } // prekida while na 135

        cout<<"Student je uspjesno zavrsio prvi ciklus studranja."<<endl;
        cout<<"Tema diplomskog: ";
        string tD;
        cin >> tD;
        cout<<"Ocjena diplomskog rada: ";
        int oD;
        cin>>oD;
        cout<<"Da li je student upisao drugi ciklus?"<<endl;
        char izbor;
        cin>>izbor;
        while(izbor!='n' and izbor!='d'){
            cout<<"Pogresan unos! Unosite novi odgovor: ";
            cin>>izbor;
        }
        if(izbor=='n'){
            cout<<"Student je zavrsio studij  na ovom fakultetu."<<endl;
            exit(1);
        }
        else{
            StudentIICiklusa objekat(ime, prezime, 222, 7, tD, 5);
            objekat.OcijeniDiplomski(oD);
        }
    }

    else if(izbor == 2) {
        /** Kako je ovo samo simulacija to cemo imati za ovo samo tri studenta **/
        cout << "Ulogovali ste se kao student. Odaberite: " << endl;
        admin(student);
        string pomoc= "";
        ifstream unos;
        unos.open(student.c_str());
        vector<string> podaci;

        while(!(unos.eof())) {
            getline(unos, pomoc);
            podaci.push_back(pomoc);
        }

        cout << "Vasi podaci: " << endl;
        for(int i=0; i<podaci.size(); i++) {
            cout << podaci[i] << endl;
        }
        unos.close();
    }
    return 0;
}
