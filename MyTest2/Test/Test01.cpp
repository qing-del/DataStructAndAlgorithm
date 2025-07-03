#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct fen
{
	int zi;
	int mu;	
};

int zzxcf(int num1, int num2)
{
	int da = num1 > num2 ? num1:num2;
	int xiao = num1 <= num2 ? num1:num2;
	while(da % xiao != 0)
	{
		int temp = da % xiao;
		da = xiao;
		xiao = temp;
	}
    if(xiao == 0) return 1;
	return xiao;
}

int become_zi(string ct)
{
    int size = ct.size();
    string process;
    for (int i = 0; i < size; i++)
    {
        if(ct[i] == '/')
        {
            break;
        }
        process += ct[i];
    }
    int num = stoi(process);
    return num;
}

int become_mu(string ct)
{
    int size = ct.size();
    string process;
    int index;
    for (int i = 0; i < size; i++)
    {
        if(ct[i] == '/')
        {
            index = i;
        }
        if(i > index)
        {
            process += ct[i];
        }
    }
    int num = stoi(process);
    if(num == 0)
    {
        num = 1;
    }
    return num;
}

fen addfen(fen a, fen b)
{
	fen new_fen;
	new_fen.zi = (a.zi * b.mu) + (b.zi * a.mu);
	new_fen.mu = a.mu * b.mu;
    if(new_fen.mu < 0)
    {
        new_fen.zi = -new_fen.zi;
        new_fen.mu = -new_fen.mu;
    }
	return new_fen;
}

int main() {
	int N;
	cin >> N;
	string input;
	vector<string> arr(N);
	vector<fen> fens(N + 1);
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
		fens[i + 1].zi = become_zi(arr[i]);
		fens[i + 1].mu = become_mu(arr[i]);
	}
	
	fens[0] = fens[1];
	for(int i = 2; i < N + 1; i++)
	{
		fens[0] = addfen(fens[0], fens[i]);
	}
	
	int biggest_num = zzxcf(fens[0].zi , fens[0].mu);
	fens[0].zi /= biggest_num;
	fens[0].mu /= biggest_num;
	int zheng = fens[0].zi / fens[0].mu;
	int new_zi = fens[0].zi % fens[0].mu;
	
	if(zheng == 0)
    {
        cout << new_zi << "/" << fens[0].mu << endl;
    }else if (new_zi == 0)
    {
        cout << zheng << endl;
    } else
    {
        cout << zheng << " " << new_zi << "/" << fens[0].mu << endl;
    }
	
	return 0;
}