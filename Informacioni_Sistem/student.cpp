#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "student.h"
using namespace std;


/************************************************   PREDMET   ************************************************/

Predmet::Predmet() {
    naziv = ""; ocjena = 5;
}

Predmet::Predmet(string n, int o) {
    naziv = n; ocjena = o;
}

Predmet::Predmet(const Predmet& p) {
    naziv = p.naziv;
    ocjena = p.ocjena;
}

void Predmet::postaviNaziv(string naziv) {
    this->naziv = naziv;
}

void Predmet::postaviOcjenu(int o) {
    ocjena = o;
}

int Predmet::getOcjenu() const {
    return ocjena;
}

string Predmet::getNaziv() const {
    return naziv;
}


/************************************************   STUDENT   ************************************************/

Student::Student(string name, string fname, int jmbg, int godina) {
    ime = name; prezime = fname;
    index = ++brojIndeksa;
    JMBG = jmbg;
    this->godina = godina;
    predmeti = new Predmet[6];
}

Student::Student() {
    ime = ""; prezime = "";
    index = ++brojIndeksa;
    JMBG = 0;
    this->godina = 0;
    predmeti = new Predmet[6];
}

Student::Student(const Student& kopija) {
    JMBG = kopija.JMBG;
    index = kopija.index;
    godina = kopija.godina;
    brojPredmeta = kopija.brojPredmeta;
    ime = kopija.ime;
    prezime = kopija.prezime;
    predmeti = new Predmet[6];

    for(int i=0; i<brojPredmeta; i++) {
        predmeti[i] = kopija.predmeti[i];
    }
}

Student& Student::operator =(const Student& desni) {
    if(this == &desni) return *this;

    delete[] predmeti;
    JMBG = desni.JMBG;
    index = desni.index;
    godina = desni.godina;
    brojPredmeta = desni.brojPredmeta;
    ime = desni.ime;
    prezime = desni.prezime;
    predmeti = new Predmet[6];

    for(int i=0; i<brojPredmeta; i++) {
        predmeti[i] = desni.predmeti[i];
    }

    return *this;
}

Student::~Student() {
    delete[] predmeti;
}


//double Student::vratiProsjek() const {
//    int suma=0, brojac=0;
//    for(int i=0; i<brojPredmeta; i++) {
//            suma += predmeti[i]->getOcjenu();
//            brojac++;
//        }
//    return suma/(brojac*(1.0));
//}

void Student::ocijeni(string predmet, int ocjena) {
    for(int i=0; i<brojPredmeta; i++) {
        if(predmeti[i].getNaziv() == predmet) {
            predmeti[i].postaviOcjenu(ocjena);
        }
    }
}

void Student::dodajPredmet(string predmet) {
    int pomoc=0;
    for(int i=0; i<brojPredmeta; i++) {
        if(predmeti[i].getNaziv() !=  "") {
            pomoc++;
        }
    }
    if(pomoc == 6) return;

    for(int i=0; i<brojPredmeta; i++) {
        if(predmeti[i].getNaziv() == "") {
            predmeti[i].postaviNaziv(predmet);
            predmeti[i].postaviOcjenu(5);
            return;
        }
    }
}

void Student::ispisi() const {
    cout << "Ime i prezime studenta: " << ime << " " << prezime << endl;
    cout << "JMBG: " << JMBG << endl;
    cout << "Broj indeksa: " << index << endl;
    cout << "Godina: " << godina << endl;
}

Predmet Student::vratiPredmet(int j) const {
    return predmeti[j];
}


/********************************************   STUDENT1CIKLUSA   ********************************************/

StudentICiklusa::StudentICiklusa(const StudentICiklusa& kopija) : Student(kopija) {
    semestar = kopija.semestar;
}
StudentICiklusa& StudentICiklusa::operator =(const StudentICiklusa& desni){
    if(this==&desni) return *this;

    delete[] predmeti;
    JMBG = desni.JMBG;
    index = desni.index;
    godina = desni.godina;
    brojPredmeta = desni.brojPredmeta;
    ime = desni.ime;
    prezime = desni.prezime;
    predmeti = new Predmet[6];
    semestar = desni.semestar;

    for(int i=0; i<brojPredmeta; i++) {
        predmeti[i] = desni.predmeti[i];
    }

    return *this;
}


StudentICiklusa::StudentICiklusa(string name, string fname, int jmbg, int sem):
    Student(name, fname, jmbg, 0) {
        semestar = sem;

    switch(semestar) {
    case 1:
        brojPredmeta=5;
        godina = 1;

        predmeti[0].postaviNaziv("Analiza 1");
        predmeti[1].postaviNaziv("Analiticka geometrija");
        predmeti[2].postaviNaziv("Uvod u matematicku logiku");
        predmeti[3].postaviNaziv("Elementarna matematika");
        predmeti[4].postaviNaziv("Uvod u racunarske tehnike");
        break;

    case 2:
        brojPredmeta=5;

        godina = 1;
        predmeti[0].postaviNaziv("Analiza 2");
        predmeti[1].postaviNaziv("Uvod u kompjuterske nauke");
        predmeti[2].postaviNaziv("Uvod u linearnu algebru");
        predmeti[3].postaviNaziv("Elementarna teorija brojeva");
        predmeti[4].postaviNaziv("Racunarski sistemi");
        break;

    case 3:
        brojPredmeta=6;

        godina = 2;
        predmeti[0].postaviNaziv("Analiza 3");
        predmeti[1].postaviNaziv("Uvod u programiranje");
        predmeti[2].postaviNaziv("Linearna algebra");
        predmeti[3].postaviNaziv("Vjerovatnoca i statistika");
        predmeti[4].postaviNaziv("Matematika za kompjuterske nauke");
        cout<<"Izborni predmeti: "<<endl;
        dodajPredmet();
        break;

    case 4:
        brojPredmeta=6;

        godina = 2;
        predmeti[0].postaviNaziv("Analiza i sinteza algoritama");
        predmeti[1].postaviNaziv("Racunarske mreze");
        predmeti[2].postaviNaziv("Objektno orjentirano programiranje");
        predmeti[3].postaviNaziv("Operativni sistemi");
        predmeti[4].postaviNaziv("Diferencijalne jednacine");
        cout<<"Izborni predmeti: "<<endl;
        dodajPredmet();
        break;

    case 5:
        godina = 3;

        brojPredmeta=5;
        predmeti[0].postaviNaziv("Strukture podataka i algoritmi");
        predmeti[1].postaviNaziv("Operaciona istrazivanja");
        predmeti[2].postaviNaziv("Uvod u web dizajn");
        predmeti[3].postaviNaziv("Algebra za kompjuterske nauke");
        cout<<"Izborni predmeti: "<<endl;
        dodajPredmet();
        break;

    case 6:
        brojPredmeta=6;


        godina = 3;
        predmeti[0].postaviNaziv("Projektovanje racunarskih aplikacija");
        predmeti[1].postaviNaziv("Dinamicki web sistemi");
        predmeti[2].postaviNaziv("Teorija grafova");
        predmeti[3].postaviNaziv("Teorija podataka");
        predmeti[4].postaviNaziv("Numericke metode u racunarstvu");
        cout<<"Izborni predmeti: "<<endl;
        dodajPredmet();
        break;

    }
}

StudentICiklusa::StudentICiklusa() : Student(){
    semestar = 1;
}

StudentICiklusa::~StudentICiklusa() {} /** Poziva automatski destruktor bazne klase a ovdje nemamo dodatne implementacije **/

void StudentICiklusa::postaviGodinu(int x) {
    godina = x;
}

double StudentICiklusa::vratiProsjek() const {
    int suma = 0;
    for(int i=0; i<brojPredmeta; i++) {
        if(predmeti[i].getOcjenu() != 5) {
                suma += predmeti[i].getOcjenu();
        }
    }
    return suma/((1.0)*brojPredmeta);
}


void StudentICiklusa::dodajPredmet() {
    int pomoc=0;
    for(int i=0; i<brojPredmeta; i++) {
        if(predmeti[i].getNaziv() !=  "") {
            pomoc++;
        }
    }
    if(pomoc == 6) return;


    ifstream unos;
    if(vratiSemestar() % 2 == 0) {
        unos.open("parni.txt", ios::app);

    }
    else {
        unos.open("neparni.txt", ios::app);
    }

    string pr;
    vector<string> izborni;
    while(!(unos.eof())) {
        getline(unos,pr);
        izborni.push_back(pr);
    }

    for(int i=0; i<izborni.size(); i++) {
       cout << i+1 << ". " << izborni[i] << endl;
    }

    cout << "Odaberite predmet: ";
    int izbor; bool odabir = false;

    while(odabir == false) {
        cin >> izbor;
        if(izbor >= 1 and izbor <= izborni.size()) {
            odabir = true;
        }
    }

    string predmet = izborni[izbor-1];
    Student::dodajPredmet(predmet);
}

int StudentICiklusa::vratiSemestar() const {
    return semestar;
}

void StudentICiklusa::postaviSemestar(int s){
    semestar=s;
}

void StudentICiklusa::upisiOcjene() {
    for(int i=0; i<brojPredmeta; i++) {
        cout << "Upisati ocjenu za predmet: ";
        cout << predmeti[i].getNaziv() << endl;
        int upis;
        cin >> upis;
        predmeti[i].postaviOcjenu(upis);
    }
}

ostream& operator<<(ostream& Ispis, const StudentICiklusa& s){ //dodala
    s.Student::ispisi();
    Ispis << "Ciklus: I" << endl << "Semestar: " << s.vratiSemestar() << endl;
    Ispis << "Predmeti i ocjene: " << endl;

    for(int i=0; i<s.brojPredmeta; i++) {
            Ispis << i+1 << ". " << s.predmeti[i].getNaziv() << " " << s.predmeti[i].getOcjenu() << endl;
        }

    return Ispis;
}

/********************************************   STUDENT2CIKLUSA   ********************************************/

StudentIICiklusa::StudentIICiklusa(): StudentICiklusa() , tema_diplomskog(""), ocjena_diplomskog(5){}

StudentIICiklusa::StudentIICiklusa(string name, string fname, int jmbg, int sem, string tD, int oD): StudentICiklusa(name, fname, jmbg,sem), ocjena_diplomskog(oD), tema_diplomskog(tD){}

StudentIICiklusa::~StudentIICiklusa(){} //automatski poziva onog izvedenog destruktora

StudentIICiklusa::StudentIICiklusa(const StudentIICiklusa& kopija): StudentICiklusa(kopija){
    ocjena_diplomskog = kopija.ocjena_diplomskog;
    tema_diplomskog = kopija.tema_diplomskog;
}

StudentIICiklusa& StudentIICiklusa::operator =(const StudentIICiklusa& desni){
    if(this==&desni) return *this;

    delete[] predmeti;
    JMBG = desni.JMBG;
    index = desni.index;
    godina = desni.godina;
    brojPredmeta = desni.brojPredmeta;
    ime = desni.ime;
    prezime = desni.prezime;
    predmeti = new Predmet[6];
    semestar = desni.semestar;
    ocjena_diplomskog = desni.ocjena_diplomskog;
    tema_diplomskog = desni.tema_diplomskog;

    for(int i=0; i<brojPredmeta; i++) {
        predmeti[i] = desni.predmeti[i];
    }

    return *this;
}


void StudentIICiklusa::postaviGodinu(int x){
    godina =x;
}

double StudentIICiklusa::vratiProsjek() const{}

void StudentIICiklusa::OcijeniDiplomski(int x){
    ocjena_diplomskog = x;
}

ostream& operator<<(ostream& Ispis, const StudentIICiklusa& s){ //dodala
    s.Student::ispisi();
    Ispis<<"Ciklus: II"<<endl<<"Tema diplomskog rada: "<<s.tema_diplomskog<<endl<<"Ocjena iz diplomskog rada "<<s.tema_diplomskog<<" : "<<s.ocjena_diplomskog<<endl;
}

/********************************************   STUDENT3CIKLUSA   ********************************************/

StudentIIICiklusa::StudentIIICiklusa(): StudentIICiklusa() , tema_magistarskog(""), ocjena_magistarskog(5){}

StudentIIICiklusa::StudentIIICiklusa(string name, string fname, int jmbg, int sem, string tD, int oD, string tM, int oM): StudentIICiklusa(name, fname, jmbg,sem, tD, oD), ocjena_magistarskog(oM), tema_magistarskog(tM){}

StudentIIICiklusa::~StudentIIICiklusa(){}

StudentIIICiklusa::StudentIIICiklusa(const StudentIIICiklusa& kopija): StudentIICiklusa(kopija){
    ocjena_magistarskog = kopija.ocjena_magistarskog;
    tema_magistarskog = kopija.tema_magistarskog;
}

StudentIIICiklusa& StudentIIICiklusa::operator =(const StudentIIICiklusa& desni){
    if(this==&desni) return *this;

    delete[] predmeti;
    JMBG = desni.JMBG;
    index = desni.index;
    godina = desni.godina;
    brojPredmeta = desni.brojPredmeta;
    ime = desni.ime;
    prezime = desni.prezime;
    predmeti = new Predmet[6];
    semestar = desni.semestar;
    ocjena_diplomskog = desni.ocjena_diplomskog;
    tema_diplomskog = desni.tema_diplomskog;
    ocjena_magistarskog = desni.ocjena_magistarskog;
    tema_magistarskog = desni.tema_magistarskog;

    for(int i=0; i<brojPredmeta; i++) {
        predmeti[i] = desni.predmeti[i];
    }

    return *this;
}


void StudentIIICiklusa::postaviGodinu(int x){
    godina =x;
}

void StudentIIICiklusa::OcijeniMagistarski(int x){
	ocjena_magistarskog = x;
}

ostream& operator<<(ostream& Ispis, const StudentIIICiklusa& s){
    s.Student::ispisi();
    Ispis<<"Ciklus: III"<<endl;
    Ispis<<"Tema magistarskog rada: "<<s.tema_magistarskog<<endl;
    Ispis<<"Ocjena iz magistarskog rada"<<s.tema_magistarskog<<": "<<s.ocjena_magistarskog<<endl;
}


int Student::brojIndeksa = 1000;

