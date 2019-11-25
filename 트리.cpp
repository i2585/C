#include <iostream>
#include <cmath>
using namespace std;
 
class Tree{
	int *p; 
	int j,level=0;
	public:
	Tree(){
			p = new int[100]; // 트리 배열 동적할당 
			for(int i=0;i<100;i++) // 트리배열의 값을 -1로 초기화 
				p[i]=-1;	
		}
		void insert(int tree[],int i){ // 트리노드에 값을 삽입하는 함수  
			j=0;
			while(1){
				if(p[0]==-1){ // 루트값 삽입 
					p[0]=tree[i];
					level++;
					break;
				}
				else if(p[j]>tree[i]){ // 트리노드의 값보다 삽입하는 값이 작으면 왼쪽 자식에 삽입하는 조건문 
					j=2*j+1; // 왼쪽자식을 가리키는 인덱스 
					if(p[j]==-1){ // 왼쪽자식이 비어있으면 삽입값을 트리노드에 삽입 
						p[j]=tree[i];
						if(j<=pow(2,level+1)-2&&j>=pow(2,level)-1) // 트리의 높이를 구하는 조건문 
							level++;
						break;
					}
				}
				else{ // 트리노드의 값보다 삽입하는 값이 크면 오른쪽 자식에 삽입하는 조건문 
					j=2*j+2; // 오른쪽자식을 가리키는 인덱스 
					if(p[j]==-1){ // 오른쪽 자식이 비어있으면 삽입값을 트리노드에 삽입 
						p[j]=tree[i];
						if(j<=pow(2,level+1)-2&&j>=pow(2,level)-1) // 트리의 높이를 구하는 조건문
							level++;
						break;
					}	
				}
			}
		}
		int search(int search){ // 트리노드에서 원하는 값을 찾는 함수 
			j=0;
			while(1){
				if(p[j]==search) // 트리노드의 값과 찾으려는 값이 같으면 해당 트리노드의 인덱스를 리턴 
					return j;
				else if(p[j]>search){ // 트리노드의 값 보다 찾으려는 값이 작으면 왼쪽자식으로 이동 
					j=2*j+1;
					if(p[j]==search){ // 왼쪽 자식의 값과 찾으려는 값이 같으면 해당 트리노드의 인덱스 리턴 
						return j;
					}
				}
				else{
					j=2*j+2;
					if(p[j]==search){ // 오른쪽 자식의 값과 찾으려는 값이 같으면 해당 트리노드의 인덱스 리턴
						return j;
					}	
				}
			}
		}
		void show(){ // 트리노드를 배열로 출력하는 함수 
			cout << "트리: ";
			for(int i=0;i<pow(2,level)-1;i++)
				cout << p[i] << " ";
			cout << endl;	
		}		
};
int main(){
	Tree t;
	int number,i=0,count=0,search,check;
	int tree[20];
	cout << "정렬되지 않은 숫자를 입력하세요!(-1이 나오면 죵료)\n";		
	while(1){ // 정렬되지 않은 숫자를 배열에 넣는 반복문 
		cin >> tree[i];
		if(tree[i]==-1)
			break;
		count++;
		i++;
	}
	for(int i=0;i<count;i++){ // 배열의 크기만큼 트리에 삽입하는 반복문 
		t.insert(tree,i); // 트리에 값들을 삽입하는 함수 
	}
	cout << "트리에서 찾으려는 값>>";
	cin >> search;
	for(int i=0;i<count;i++){ // 배열의 크기만큼 트리에서 원하는 값을 찾는 반복문 
		check = t.search(search);// 트리에서 원하는 값을 찾는 함수 
	}
	cout << "입력 배열: "; 
	for(int i=0;i<count;i++){	
		cout << tree[i] << " "; 
	}
	cout << endl;
	t.show(); // 트리배열 출력하는 함수 
	cout << "트리에서 찾은려는 값의 인덱스: " << check; 
}
