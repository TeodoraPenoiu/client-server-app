#include <iostream>
using namespace std;

//cu ajutorul clasei asteia se creeaza lista inlantuita pentru fiecare proces in parte
class segmentMemorie {
public:
	string indentificator_tip;
	//secunda la care incepe procesul/gaura in memore
	int adresa_inceput;
	int dimensiune;
	segmentMemorie* next;
};

//functie care aloca loc in memorie fiecarui proces cu ajutorul algoritmului First fit
void firstFit(int blockSize, int m, int processSize[], int n, string identificatori[]){
    //pastreaza id-ul proceselor
    int allocation[10];

	//populez allocation cu -1 (o sa ma ajute sa afisez care intrari au fost alocate si care nu)
    memset(allocation, -1, sizeof(allocation));

	int isprocess[10];
	memset(isprocess, -1, sizeof(isprocess));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
			string x = "P";
			//daca intrarea este un proces, atunci incercam sa o adaugam in blocul de memorie
			if (identificatori[i] == x) {
				if (blockSize >= processSize[i])
				{
					allocation[i] = i;

					//redu memoria libera din blocul de memorie
					blockSize = blockSize - processSize[i];

					isprocess[i] = i;

					break;
				}
				else {
					isprocess[i] = i;
				}
			}
			else {
				break;
			}
        }
    }

    cout << "\nIntrarea Nr.\tMarime intrare\tProces\t\tBlocul de memorie\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"<< processSize[i] << "\t\t";
		if (isprocess[i] != -1) {
			cout << "Da" << "\t\t";
		}
		else {
			cout << "Nu" << "\t\t";
		}
		if (allocation[i] != -1) {
			cout << "Alocat";
		}
		else {
			cout << "Nu a fost alocat";
		}
        cout << endl;
    }
}

int main()
{
	segmentMemorie* head = NULL;
	segmentMemorie* second = NULL;
	segmentMemorie* third = NULL;
	segmentMemorie* fourth = NULL;
	segmentMemorie* fifth = NULL;

	//aplicatia noastra va aloca memorie pentru 5 intrari
	head = new segmentMemorie();
	second = new segmentMemorie();
	third = new segmentMemorie();
	fourth = new segmentMemorie();
	fifth = new segmentMemorie();

	//intrarea 1
	head->indentificator_tip = "H";
	head->adresa_inceput = 1;
	head->dimensiune = 200;
	// Link first node with
	head->next = second;

	//intrarea 2
	second->indentificator_tip = "P";
	second->adresa_inceput = 4;
	second->dimensiune = 100;
	// Link second node with the third node
	second->next = third;

	//intrarea 3
	third->indentificator_tip = "H";
	third->adresa_inceput = 5;
	third->dimensiune = 400;
	// marcheaza nodul 3 ca ultimul nod
	third->next = fourth;

	//intrarea 4
	fourth->indentificator_tip = "P";
	fourth->adresa_inceput = 6;
	fourth->dimensiune = 250;
	// marcheaza nodul 3 ca ultimul nod
	fourth->next = fifth;

	//intrarea 5
	fifth->indentificator_tip = "P";
	fifth->adresa_inceput = 9;
	fifth->dimensiune = 200;
	// marcheaza nodul 3 ca ultimul nod
	fifth->next = NULL;

	//marimea blocului de memorie
    int blockSize = 1000;
	//in acest array retinem dimensiunea fiecarei intrari (cat loc ar ocupa ea in blocul de memorie)
    int processSize[] = { head->dimensiune, second->dimensiune, third->dimensiune, fourth->dimensiune, fifth->dimensiune };
	//aici se retin tipul de identificator al fiecarei intrari (daca este proces sau spatiu - spatiile nu se adauga in bloc)
	string indentificatori[] = { head->indentificator_tip , second->indentificator_tip , third->indentificator_tip , fourth->indentificator_tip , fifth->indentificator_tip };

    int m = 1;
	//cate intrari sunt in lista
    int n = sizeof(processSize) / sizeof(processSize[0]);

	//apelam functia firstFit
    firstFit(blockSize, m, processSize, n, indentificatori);

	return 0;
}

// This code is contributed by rathbhupendra
