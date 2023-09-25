
#include<iostream>
#include<string>
 using namespace std;
class document
{
	string titre;
	float prix;
	int code;

	public:
	static int cpt;
		document(string titre, float prix)
		{
			this->titre=titre;
			this->prix=prix;
			code=++cpt;
		}
		string get_titre(){return titre;}
		float getprix(){ return prix;}
		int getcode(){ return code;}
		int operator==(document d)
		{
			if(code==d.code)
			return 1;
			else
			return 0;
		}
		int operator<(document d)
		{
			if(prix>d.prix)
			return 1;
			else if(prix<d.prix)
			return -1;
			else
			return 0;
		}
		float solder(float pr)
		{
			float solde=0;
			solde=prix-prix*( pr/100);
			return solde;

		}
		friend ostream& operator<<(ostream& o , const document& d);
};
int document::cpt=0;

ostream& operator<<(ostream& o , const document& d)
{
	o<<"le code du document: "<<d.code<<endl ;
	o<<"le titre du document: "<<d.titre<<endl  ;
	o<<"le prix du document: "<<d.prix<<endl  ;
	return o;
}
//partie2//
class livre:public document
{
	string noma;
	int nbr_page;
	public:
		livre(string t,float p,string noma,int nbr_page):document(t,p)
		{
			this->noma=noma;
			this->nbr_page=nbr_page;
		}
		friend ostream& operator<<(ostream& o ,livre& l);
};
ostream& operator<<(ostream& o ,livre& l)
{
	o<<"le livre sous le format suivant:";
	o<<(document)l;
	o<<l.noma<<"  ";
	o<<l.nbr_page<<"pages";
	return o;
}
class dictionnaire:private document
{
	string lang;
	int nbr_tome;
	public:
		dictionnaire(string t,float p,string lang ,int nbr_tome):document(t,p)
		{
			this->lang=lang;
			this->nbr_tome=nbr_tome;
		}
		float solder(float prctg)
		{
		document::solder(prctg);
		}
		friend ostream& operator<<(ostream& o ,dictionnaire& d);
};
ostream& operator<<(ostream& o ,dictionnaire& d)
{
	o<<"le livre sous le format suivant:";
	o<<(document)d;
	o<<d.lang<<"  "<<endl;
	o<<d.nbr_tome<<"tomes";
	return o;
}
main()
{
	document d1("titre1",350.0);
	document d2("titre2",300.0);
	livre l1("titre1",350.0,"auteur1",45);
    dictionnaire dic1("titre1",350.0,"fr",13);
	cout<<"le premier document est :"<<"||"<<d1;
	cout<<"le deuxieme document est :"<<"||"<<d2;
	cout<<"la comparaison entre le doc 1 et 2: "<<endl;
    if(d1<d2)
	cout<<"le prix du doc1 est inferieure du doc2"<<endl;
	cout<<"le premier livre:"<<"||"<<l1<<endl;
cout<<"le solde est :"<<d1.solder(20)<<endl;
cout<<"le solde du livre est: "<<l1.solder(10)<<endl;
cout<<"le solde du dictionnaire est: "<<dic1.solder(15);
}
