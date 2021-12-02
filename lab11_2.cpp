// lab11_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Windows.h"
#include <ctime>
#include "process.h"
#include <stdlib.h>
#include <thread>
#include <iostream>




using namespace std;
DWORD mat[5][5];
CRITICAL_SECTION cs;

unsigned __stdcall one(void* lpParameter)
{
    srand(time(NULL));
    while (1)
    {
        EnterCriticalSection(&cs);
        for (int j = 0; j < 5; j++)
        {
            mat[0][j] =rand() % 999;
            /*Sleep(1000);*/
        }
        LeaveCriticalSection(&cs);
    }


    return 0;
}

unsigned __stdcall two(void* lpParameter)
{
    srand(time(NULL));
    while (1)
    {
        
        EnterCriticalSection(&cs);
        for (int j = 0; j < 5; j++)
        {
          
            mat[1][j] = rand() % 999;
          
        }
        LeaveCriticalSection(&cs);
    }
    return 0;
}

unsigned __stdcall three(void* lpParameter)
{
    srand(time(NULL));
    while (1)
    {
        EnterCriticalSection(&cs);
        for (int j = 0; j < 5; j++)
        {
            mat[2][j] = rand() % 999;
            
            
        }
        LeaveCriticalSection(&cs);
    }
    return 0;
}

unsigned __stdcall four(void* lpParameter)
{
    srand(time(NULL));
    while (1)
    {
        EnterCriticalSection(&cs);
        for (int j = 0; j < 5; j++)
        {
            mat[3][j] = rand() % 999;
            
        }
        LeaveCriticalSection(&cs);
    }
    return 0;
}

unsigned __stdcall five(void* lpParameter)
{
    srand(time(NULL)); //чтобы не выдавал одни и те же значения
    
    while (1)
    {
        EnterCriticalSection(&cs);
        for (int j = 0; j < 5; j++)
        {
            mat[4][j] = rand() % 999;
            
        }
        LeaveCriticalSection(&cs);
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Нажмите ENTER" <<endl;
    
    int k = 0;
    int min = 1000;
    int max = mat[0][0];

    InitializeCriticalSection(&cs);
    unsigned threadID;
    HANDLE hThreads[5];
    
    hThreads[0] = (HANDLE)_beginthreadex(NULL, 0, one, NULL, 0, &threadID);
    hThreads[1] = (HANDLE)_beginthreadex(NULL, 0, two, NULL, 0, &threadID);
    hThreads[2] = (HANDLE)_beginthreadex(NULL, 0, three, NULL, 0, &threadID);
    hThreads[3] = (HANDLE)_beginthreadex(NULL, 0, four, NULL, 0, &threadID);
    hThreads[4] = (HANDLE)_beginthreadex(NULL, 0, five, NULL, 0, &threadID);

    cin.get();



    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mat[i][j] > 4 && mat[i][j] < 100)
            {
                k++;
            }
            if (mat[i][j] > max)
            {
                max = mat[i][j];
            }
            if (min >= mat[i][j])
            {
                min = mat[i][j];
            }
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }


    cout << "Количество двухзначных чисел: " << k << endl;
    cout << "Минимальное: " << min << endl;
    cout << "Максимальное: " << max << endl;
    system("pause");
    system("cls");
   
    return 0;
    
}


