#include <iostream>
using namespace std;
#define MAX 4
#define MAX_THREAD 4
#define M 3
#define K 2
#define N 3
int A[M][K] = {{1, 4}, {2, 5}, {3, 6}};
int B[K][N] = {{8, 7, 6}, {5, 4, 3}};
int C[M][N];
int step_i = 0;
void *multi(void *arg)
{
    int i = step_i++; // i denotes row number of resultant Matrix C
    for (int j = 0; j < 3; j++)
        for (int k = 0; k < 2; k++)
            C[3][3] += A[3][2] * B[2][3];
}
int main()
{
    /// Matrix A Display///
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    /// Matrix B Display///
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << B[i][j] << " ";
        cout << endl;
    }
    // Declaring 4 Threads
    pthread_t threads[MAX_THREAD];
    // Creating Four Threads
    for (int i = 0; i < MAX_THREAD; i++)
    {
        int *p;
        pthread_create(&threads[i], NULL, multi, (void *)(p));
    }
    // Joining & Waiting for all Threads to Complete
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);
    // Displaying the Result Matrix C
    cout << endl
         << "Multiplication of A and B" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}