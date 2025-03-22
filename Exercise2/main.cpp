#include<fstream>		//gestisce i file in input/output
#include<iostream>	
#include<iomanip>

double traslation(double x)			
{	double t = (3.0/4.0) * x - 7.0/4.0;		//formula che manda i punti da [1,5] a [-1,2]
	return t;
}	

int main()
{	
	std::ifstream file("./data.txt");		//apro il file in modalità lettura
	if(file.fail())		//vado a verificare se il file esiste o meno e se si può aprire
	{	
		std::cerr <<"Non è possibile aprire il file" << std::endl;	//stampa dell'errore
		return 1;		// 1 = True e 0 = False. Ritorna 1 se non è possibile aprire il file
	}
	
	
	double val;
	double sum = 0;		//inizializzo la somma
	int i = 1;	//inizializzo il contatore
	
	std::ofstream results("./results.txt");		//apro il file in modalità scrittura
	results << "# N Mean" << std::endl;		//stampo l'intestazione
	if (results.is_open())		//verifico che l'apertura del file sia riuscita
	{	while(file >> val)		//leggo un valore alla volta del file in lettura
		{	double new_val = traslation(val);	//faccio la traslazione del valore letto
			sum += new_val;		//aggiorno la somma dei valori traslati
			double media = sum/i;		//calcolo la media
			results << i << " " << std::scientific << std::setprecision(16) << media << std::endl;		//scrivo la media nel file in scrittura
			i++;		//incremento il contatore
		}
	}
	results.close();		//chiudo il file che ho riempito
    return 0;
}
