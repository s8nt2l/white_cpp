#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{	
    int q;
	cin >> q;
	vector<char> queue;
	string cmd;
	int k = 0;
	while(q){
		cin >> cmd;
		if(cmd == "WORRY_COUNT"){		
			int count = 0;
			for(auto i : queue){
				if(i == 'w'){
					count++;
                    }
			}
			cout << count << endl;			
		}
        		else{
			cin >> k;
			if(cmd == "COME"){			
				// метод resize может как уменьшать размер вектора, так и увеличивать,
        		// поэтому специально рассматривать случаи с положительным
        		// и отрицательным person_count не нужно
				queue.resize(queue.size()+k, 'q');
			}
			else if(cmd == "WORRY")
			{
				queue[k] = 'w';
			}
			else if(cmd == "QUIET")
			{
				queue[k] = 'q';
			}
		}
		--q;
	}
	system("pause");
	return 0;}
