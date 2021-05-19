// A simple CPP program to introduce
// a linked list
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class segmentMemorie {
public:
	string indentificator_tip;
	//secunda la care incepe procesul/gaura in memore
	int adresa_inceput;
	int dimensiune;
	segmentMemorie* next;
};

// Function to allocate memory to 
// blocks as per First fit algorithm
void firstFit(int blockSize[], int m, int processSize[], int n)
{
    // Stores block id of the 
    // block allocated to a process
    int allocation[10];

    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                // allocate block j to p[i] process
                allocation[i] = j;

                // Reduce available memory in this block.
                blockSize[j] -= processSize[i];

                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"
            << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
	segmentMemorie* head = NULL;
	segmentMemorie* second = NULL;
	segmentMemorie* third = NULL;

	// allocate 3 nodes in the heap
	head = new segmentMemorie();
	second = new segmentMemorie();
	third = new segmentMemorie();

	head->indentificator_tip = "P";
	head->adresa_inceput = 1;
	head->dimensiune = 150;
	// Link first node with
	head->next = second;

	second->indentificator_tip = "H";
	second->adresa_inceput = 4;
	second->dimensiune = 220;
	// Link second node with the third node
	second->next = third;

	third->indentificator_tip = "H";
	third->adresa_inceput = 4;
	third->dimensiune = 400;
	// marcheaza nodul 3 ca ultimul nod
	third->next = NULL;

    int blockSize[] = { 600 };
    int processSize[] = { head->dimensiune, second->dimensiune, third->dimensiune };

    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    firstFit(blockSize, m, processSize, n);

	return 0;
}

// This code is contributed by rathbhupendra
