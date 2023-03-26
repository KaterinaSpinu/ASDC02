#include <iostream>
#include <fstream>
#include <string>
const int size = 49;
using namespace std;
struct base
{
    char name[20];
    char description[25];
    double price;
    int count;
    char unit[5];
    long long int id;
};

void bubbleSort(struct base b[], int length)
{
    base temp;
    int i;
    int index;
    for (i = 1; i < length; i++)
    {
        for (index = 0; index < length - i; index++)
            if (b[index].unit > b[index + 1].unit)
            {
                temp = b[index];
                b[index] = b[index + 1];
                b[index + 1] = temp;
            }
    }
}


void qs(struct base b[], int left, int right)
{

    register int i, j;
    char* x;
    struct base temp;

    i = left; j = right;
    x = b[(left + right) / 2].name;

    do {
        while ((strcmp(b[i].name, x) < 0) && (i < right)) i++;
        while ((strcmp(b[j].name, x) > 0) && (j > left)) j--;
        if (i <= j) {
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(b, left, j);
    if (i < right) qs(b, i, right);
}

void quickSort(struct base items[], int count)
{
    qs(items, 0, count - 1);
}

void countingSort(struct base b[], int sz) {
    int i, j, k;
    int index;
    int idx = 0;
    int min, max;
    min = max =0;
    for (i = 1; i < sz; i++) {
        min = (b[i].count < min) ? b[i].count : min;
        max = (b[i].count > max) ? b[i].count : max;
    }
    k = max - min + 1;
    int* B = new int[k];
    for (i = 0; i < k; i++) B[i] = 0;

    for (index = 0; i < sz; i++) B[b[i].count - min]++;
    for (index = min; i <= max; i++)
        for (j = 0; j < B[i - min]; j++) b[idx++].count = i;
    delete[] B;
}

int main()
{
    base b[50];
    ifstream fin("mebeli1.txt");
    int i = 0;
    if (fin)
    {
        for (i = 0; i < 50; i++){
            fin >> b[i].name >> b[i].description >> b[i].price >> b[i].count >> b[i].unit >> b[i].id;
        }
        fin.close();
    }
    else
        cout << "Error!" << endl;

    void bubbleSort(struct base b[], int size);
    void quickSort(struct base b[], int size); 
    void countingSort(struct base b[], int size);
    system("pause");
    return 0;
    cout <<"count of if, perestanovok: " <<ifc<<endl;
    cout <<"Count of comparisons(sravnenii): " << iter <<endl;
    cout <<"Count of itterations: " << iter <<endl;
    cout <<"Count of if: " <<ifc <<endl; 
}
