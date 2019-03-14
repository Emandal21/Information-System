#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;


/************************************************   PREDMET   ************************************************/

class Predmet {
public:
    Predmet();
    Predmet(string name, int mark);
    Predmet(const Predmet& p);
    void postaviNaziv(string naziv);
    void postaviOcjenu(int mark);
    int getOcjenu() const;
    string getNaziv() const;

private:
    string naziv;
    int ocjena;
};



/************************************************   STUDENT   ************************************************/

class Student {
public:
    Student(); //implementiraj
    Student(string name, string fname, int jmbg, int godina);
    ~Student();
    Student(const Student& kopija);
    Student& operator =(const Student& desni);
    void ispisi() const;
    virtual void postaviGodinu(int x) = 0;
    virtual double vratiProsjek() const = 0;
    void ocijeni(string predmet, int ocjena);
    void dodajPredmet(string predmet);
    Predmet vratiPredmet(int j) const;

    void ispis() {
        for(int i=0; i<brojPredmeta; i++) {
            cout << i+1 << ". " << predmeti[i].getNaziv() << " " << predmeti[i].getOcjenu() << endl;
        }
    }

protected:
    int JMBG, index, godina, brojPredmeta;
    string ime, prezime;
    static int brojIndeksa;
    Predmet* predmeti;
};


/********************************************   STUDENT1CIKLUSA   ********************************************/

class StudentICiklusa : public Student {
public:
    StudentICiklusa();
    StudentICiklusa(string name, string fname, int jmbg, int sem);
    ~StudentICiklusa();
    StudentICiklusa(const StudentICiklusa& kopija);
    StudentICiklusa& operator =(const StudentICiklusa& desni);
    friend ostream& operator<<(ostream& Ispis, const StudentICiklusa& s);
    void postaviGodinu(int x);
    double vratiProsjek() const;
    void dodajPredmet();
    int vratiSemestar() const;
    void postaviSemestar(int s);
    void upisiOcjene();

protected:
    int semestar;
};

/********************************************   STUDENT2CIKLUSA   ********************************************/


class StudentIICiklusa : public StudentICiklusa {
public:
    StudentIICiklusa();
    StudentIICiklusa(string name, string fname, int jmbg, int sem, string tD, int oD);
    ~StudentIICiklusa();
    StudentIICiklusa(const StudentIICiklusa& kopija);
    StudentIICiklusa& operator =(const StudentIICiklusa& desni);
    friend ostream& operator<<(ostream& Ispis, const StudentIICiklusa& s);
    void postaviGodinu(int x);
    double vratiProsjek() const; //doradi implementaciju
    void OcijeniDiplomski(int x);

protected:
    string tema_diplomskog;
    int ocjena_diplomskog;
};


/********************************************   STUDENT3CIKLUSA   ********************************************/


class StudentIIICiklusa : public StudentIICiklusa {
	public:
		StudentIIICiklusa();
    	StudentIIICiklusa(string name, string fname, int jmbg, int sem, string tD, int oD, string tM, int oM);
    	~StudentIIICiklusa();
    	StudentIIICiklusa(const StudentIIICiklusa& kopija);
    	StudentIIICiklusa& operator =(const StudentIIICiklusa& desni);
    	friend ostream& operator<<(ostream& Ispis, const StudentIIICiklusa& s);
    	void postaviGodinu(int x);
    	//double vratiProsjek() const;
    	void OcijeniMagistarski(int x);

    private:
    	string tema_magistarskog;
    	int ocjena_magistarskog;
};

#endif // STUDENT_H_INCLUDED



