#include <iostream>
#include <cmath>
using namespace std;
 
class Tree{
	int *p; 
	int j,level=0;
	public:
	Tree(){
			p = new int[100]; // Ʈ�� �迭 �����Ҵ� 
			for(int i=0;i<100;i++) // Ʈ���迭�� ���� -1�� �ʱ�ȭ 
				p[i]=-1;	
		}
		void insert(int tree[],int i){ // Ʈ����忡 ���� �����ϴ� �Լ�  
			j=0;
			while(1){
				if(p[0]==-1){ // ��Ʈ�� ���� 
					p[0]=tree[i];
					level++;
					break;
				}
				else if(p[j]>tree[i]){ // Ʈ������� ������ �����ϴ� ���� ������ ���� �ڽĿ� �����ϴ� ���ǹ� 
					j=2*j+1; // �����ڽ��� ����Ű�� �ε��� 
					if(p[j]==-1){ // �����ڽ��� ��������� ���԰��� Ʈ����忡 ���� 
						p[j]=tree[i];
						if(j<=pow(2,level+1)-2&&j>=pow(2,level)-1) // Ʈ���� ���̸� ���ϴ� ���ǹ� 
							level++;
						break;
					}
				}
				else{ // Ʈ������� ������ �����ϴ� ���� ũ�� ������ �ڽĿ� �����ϴ� ���ǹ� 
					j=2*j+2; // �������ڽ��� ����Ű�� �ε��� 
					if(p[j]==-1){ // ������ �ڽ��� ��������� ���԰��� Ʈ����忡 ���� 
						p[j]=tree[i];
						if(j<=pow(2,level+1)-2&&j>=pow(2,level)-1) // Ʈ���� ���̸� ���ϴ� ���ǹ�
							level++;
						break;
					}	
				}
			}
		}
		int search(int search){ // Ʈ����忡�� ���ϴ� ���� ã�� �Լ� 
			j=0;
			while(1){
				if(p[j]==search) // Ʈ������� ���� ã������ ���� ������ �ش� Ʈ������� �ε����� ���� 
					return j;
				else if(p[j]>search){ // Ʈ������� �� ���� ã������ ���� ������ �����ڽ����� �̵� 
					j=2*j+1;
					if(p[j]==search){ // ���� �ڽ��� ���� ã������ ���� ������ �ش� Ʈ������� �ε��� ���� 
						return j;
					}
				}
				else{
					j=2*j+2;
					if(p[j]==search){ // ������ �ڽ��� ���� ã������ ���� ������ �ش� Ʈ������� �ε��� ����
						return j;
					}	
				}
			}
		}
		void show(){ // Ʈ����带 �迭�� ����ϴ� �Լ� 
			cout << "Ʈ��: ";
			for(int i=0;i<pow(2,level)-1;i++)
				cout << p[i] << " ";
			cout << endl;	
		}		
};
int main(){
	Tree t;
	int number,i=0,count=0,search,check;
	int tree[20];
	cout << "���ĵ��� ���� ���ڸ� �Է��ϼ���!(-1�� ������ �շ�)\n";		
	while(1){ // ���ĵ��� ���� ���ڸ� �迭�� �ִ� �ݺ��� 
		cin >> tree[i];
		if(tree[i]==-1)
			break;
		count++;
		i++;
	}
	for(int i=0;i<count;i++){ // �迭�� ũ�⸸ŭ Ʈ���� �����ϴ� �ݺ��� 
		t.insert(tree,i); // Ʈ���� ������ �����ϴ� �Լ� 
	}
	cout << "Ʈ������ ã������ ��>>";
	cin >> search;
	for(int i=0;i<count;i++){ // �迭�� ũ�⸸ŭ Ʈ������ ���ϴ� ���� ã�� �ݺ��� 
		check = t.search(search);// Ʈ������ ���ϴ� ���� ã�� �Լ� 
	}
	cout << "�Է� �迭: "; 
	for(int i=0;i<count;i++){	
		cout << tree[i] << " "; 
	}
	cout << endl;
	t.show(); // Ʈ���迭 ����ϴ� �Լ� 
	cout << "Ʈ������ ã������ ���� �ε���: " << check; 
}
