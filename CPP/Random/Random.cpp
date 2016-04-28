//+_+_+_+_+_+_+__+__+__+__+__+_+_
//_+__+_By: "Sir" Arthur_+__+__+_
//+_+_+_+_+_+_+__+__+__+__+__+_+_

#include <iostream>
#include <cstdlib>
#include <ctime>

#define LEN 5

using namespace std;
int 
main()
{
  
    srand((unsigned)time(0));
    int m[LEN][LEN];

    for(int i = 0; i < LEN; i++)
        for(int j = 0; j < LEN;j++)
            {
                m[i][j] = (rand()%99);
            }
    for(int i = 0; i < LEN; i++)
    {
        cout << "\n";
            for(int j = 0; j < LEN;j++)
            {
                cout << " ";
                cout << m[i][j];
            }
    }

	return 0;
}
