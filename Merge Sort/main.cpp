#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>


using namespace std;
void Merge(int *a, int low, int high, int mid)
{
	int l, m, n, temp[high-low+1];
	l = low;
	n = 0;
	m = mid + 1;

	while (l <= mid && m <= high)
	{
		if (a[l] < a[m])
		{
			temp[n] = a[l];
			n++;
			l++;
		}
		else
		{
			temp[n] = a[m];
			n++;
			m++;
		}
	}

	while (l <= mid)
	{
		temp[n] = a[l];
		n++;
		l++;
	}

	while (m <= high)
	{
		temp[n] = a[m];
		n++;
		m++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (l = low; l <= high; l++)
	{
		a[l] = temp[l-low];
	}
}

// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}

int main()
{

    char *waktu;
    // declaring argument of time()
	time_t my_time = time(NULL);

	// ctime() used to give the present time
	waktu= ctime(&my_time);
	int nilai, i, c;
	c=1;
	cout<<"\t\t\t******************************\n";
	cout<<"\t\t\t* MERGE SORT FOR RANDOM DATA *\n";
	cout<<"\t\t\t******************************\n";
	cout<<"\nMasukkan banyak elemen data yang ingin di Sorting : ";
	cin>>nilai;
    cout << "Waktu awal = " << waktu << endl;
    srand((unsigned)time(0));
    int randomNumber;
    int lowest=1, highest=500000;
    int range=(highest-lowest)+1;

	int arr[nilai];
	for(i = 0; i < nilai; i++)
	{
	    randomNumber = lowest+int(range*rand()/(RAND_MAX + 1.0));
		arr[i] = randomNumber;
		cout<<"Data ke-"<<i<<" = "<<arr[i]<<"\t";
	}

	MergeSort(arr, 0, nilai-1);

	// Printing the sorted data.
	cout<<"\n----------------------";
	cout<<"\n|| Hasil Sorted Data||\n";
	cout<<"----------------------\n";
	for (i = 0; i < nilai; i++){
        cout<<"Urutan Data ke -> "<<c<<" = "<<arr[i]<<endl;
        c++;}

    cout << "Waktu Akhir = " << ctime(&my_time);
	return 0;


}


