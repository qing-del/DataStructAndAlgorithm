#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int nums[n];
    
    for(int i = 0;i < n;i++)
    {
        cin >> nums[i];
    }

    for (int r1 = 1; r1 <= nums[0]; r1++)
    {
        if (r1 != 0 && r1 % k == 0 && n == 1)
        {
            cout << r1 << " " << endl;
        } else 
        {
            for (int r2 = 1; r2 <= nums[1]; r2++)
            {
                if (r1 + r2 != 0 && (r1 + r2) % k == 0 && n == 2)
                {
                    cout << r1 << " " << r2 << " " << endl;
                }else
                {
                    for (int r3 = 1; r3 <= nums[2]; r3++)
                    {
                        if (r1 + r2 + r3 != 0 && (r1 + r2 + r3) % k == 0 && n == 3)
                        {
                           cout << r1 << " " << r2 << " " << r3 << " " << endl;
                        } else
                        {
                            for (int r4 = 1; r4 <= nums[3]; r4++)
                            {
                                if (r1 + r2 + r3 + r4 != 0 && (r1 + r2 + r3 + r4) % k == 0 && n == 4)
                                {
                                    cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << endl;
                                }else
                                {
                                    for (int r5 = 1; r5 <= nums[4]; r5++)
                                    {
                                        if (r1 + r2 + r3 + r4 + r5 != 0 && (r1 + r2 + r3 + r4 + r5) % k == 0 && n == 5)
                                        {
                                            cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << endl;
                                        }else
                                        {
                                            for (int r6 = 1; r6 <= nums[5]; r6++)
                                            {
                                                if (r1 + r2 + r3 + r4 + r5 + r6 != 0 && (r1 + r2 + r3 + r4 + r5 + r6) % k == 0 && n == 6)
                                                {
                                                    cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << r6 << " " << endl;
                                                }else
                                                {
                                                    for (int r7 = 1; r7 <= nums[6]; r7++)
                                                    {
                                                        if (r1 + r2 + r3 + r4 + r5 + r6 + r7 != 0 && (r1 + r2 + r3 + r4 + r5 + r6 + r7) % k == 0 && n == 7)
                                                        {
                                                            cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << r6 << " " << r7 << " " << endl;
                                                        }else
                                                        {
                                                            for (int r8 = 1; r8 <= nums[7]; r8++)
                                                            {
                                                                if (r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8 != 0 && (r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8) % k == 0 && n == 8)
                                                                {
                                                                    cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << r6 << " " << r7 << " " << endl;
                                                                }
                                                            }                                                           
                                                        }
                                                    }                                                    
                                                }
                                            }                                            
                                        }
                                    }                                    
                                }
                            }                      
                        }                    
                    }   
                }        
            } 
        } 
    }

    system("pause");
    return 0;
}