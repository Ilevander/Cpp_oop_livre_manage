#include <iostream>
#include<string>

using namespace std;

int main()
{
    class CollectionLivre
{
	livre *cl;
	int n,nl;
	char *res;
	public:
		CollectionLivre(int n)
		{
			this->n=n;
			cl=(livre*)malloc(sizeof(livre)*n);
			res=(char*)malloc(sizeof(char)*n);
			nl=0;
		}
	     int verifiercode(int code)
		{
			for(int i=0;i<nl;i++)
			{
				if(cl[i].getcode()==code)
				{
					return 1;
				}
			}
			return 0;
		}
		int verifierlivre(livre l)
		{
			for(int i=0;i<nl;i++)
			{
				if(cl[i]==l)
				{
					return 1;
				}
			}
			return 0;
		}
		void ajouter(livre l)
		{
			if(verifierlivre(l)==0)
			{
				new(cl+nl)livre(l);
				new(res+nl)char('L');
				nl++;
			}

		}
		livre rechercher(livre l)
		{
			if(verifierlivre(l)==1)
			{
				for(int i=0;i<nl;i++)
				{
					if(cl[i]==l)
					{
						return cl[i];
					}
				}
			}
			else
			{
			    cout<<"\nle livre n'exixte pas"<<endl;
			}
		}
		void reserver(int code)
		{
			if(verifiercode(code)==1)
			{
				for(int i=0;i<nl;i++)
				{
					if(cl[i].getcode()==code)
					{
						if(res[i]=='L')
						{
							res[i]='R';
						}
						else
						{
							cout<<"ce livre est deja reservé"<<endl;
						}
					}
				}
			}
			else
			{
				cout<<"le livre demandé n'exixte pas";
			}
		}
		friend ostream & operator <<(ostream &o,CollectionLivre &cl);
};
ostream & operator <<(ostream &o,CollectionLivre &cl)
{
	for(int i=0;i<cl.nl;i++)
	{
		cout<<cl.cl[i]<<"==>"<<cl.res[i]<<endl;
		return o;
	}
}
    return 0;
}
