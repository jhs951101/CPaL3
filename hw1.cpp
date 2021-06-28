#include <iostream>
#include <iomanip>
#define TABLE_SIZE			10

using namespace std;

int a_n;  // a_n: n�� ���� �����ϴ� ����(VerifyMabangjin()������ ���)

void Mabangjin(int table[][TABLE_SIZE], const int size)
{

	int n;  // n: Ȧ���������� ǥ ����(n*n, �Է¹���)

	do{

		cout << "Input the number(1-10): ";
		cin >> n;  // ǥ ���̸� �Է¹���

		if( n>=1 && n<=10 ){  // n�� ���� ���� ���� ��쿡�� ����

			if(n == 10) break;  // n=11(10+1) �̹Ƿ� ��� �Ұ���, ����
			else{

				for (int x=0; x<TABLE_SIZE; x++)      // x: �迭�� ���� ����, y: �迭�� ���� ����
					for (int y=0; y<TABLE_SIZE; y++)
						table[x][y] = 0;  // table[][]: Ȧ���������� �����ϱ� ���� 2���� �迭
			}                                         // 2���� �迭 ��ü�� 0�� ������

			if(n%2 == 0) n = n+1;  // n�� ���� ¦���̸� n+1
			a_n = n;  // n�� ���� �������� a(���κ� ����)�� �־���

			for(int x=0; x<=n-1; x++){
				for(int y=0; y<=n-1; y++){  // x: �迭�� ���� ����, y: �迭�� ���� ����

					table[x][y] = -1;  /* Ȧ�������� ǥ ���θ� ���� -1�� ��
							              �� 0: Ȧ�������� ǥ �ܺ�, -1: ǥ ����(�� ĭ) */
				}
			}

			table[ n-1 ][ (n-1)/2 ] = 1;  // ǥ �� ���� ��� ���� 1�� ������
			int point_x = n-1;      // point_x: �迭�� �� ������
			int point_y = (n-1)/2;  // point_y: �迭�� �� ������
									// �ʱ⿡�� 1�� ����� ���� �����ͷ� ������


			for(int a=2; a<=pow(n,2); a++){  // a: Ȧ�������� ǥ�� ������ ����
						                     /* Ȧ�������� ǥ�� ���ڸ� �����ϴ� �κ� */

				if( table[ point_x +1 ][ point_y +1 ] == -1){  // �������� �����ʾƷ��� �� ĭ(ǥ ����)�� ���

					table[ point_x +1 ][ point_y +1 ] = a;  // Ȧ�������� ǥ�� ���ڸ� ������
					point_x = point_x +1;
					point_y = point_y +1;  /* �����͸� ���� */

				} else if( table[ point_x +1 ][ point_y +1 ] > 0){  // �������� �����ʾƷ��� ���ڰ� ������ ���

					table[ point_x -1 ][ point_y ] = a;  // Ȧ�������� ǥ�� ���ڸ� ������
					point_x = point_x -1;  // �����͸� ����

				} else{  // �������� �����ʾƷ��� ǥ �ܺ��� ���

					if( table[ 0 ][ point_y +1 ] != 0){ // �������� �����ʾƷ��� ���������� ǥ������ ���

						table[ 0 ][ point_y +1 ] = a;  // Ȧ�������� ǥ�� ���ڸ� ������
						point_x = 0;
						point_y = point_y +1;  /* �����͸� ���� */

					} else if( table[ point_x +1 ][ 0 ] != 0){  // �������� �����ʾƷ��� ���� ������ ǥ ������ ���

						table[ point_x +1 ][ 0 ] = a;  // Ȧ�������� ǥ�� ���ڸ� ������
						point_x = point_x +1;
						point_y = 0;          /* �����͸� ���� */

					}else{  // �������� �����ʾƷ��� ���� ���ʵ� ���ʵ� ǥ �ܺ��� ���

						table[ point_x -1 ][ point_y ] = a; // �������� �ٷ����κп� ���ڸ� ������
						point_x = point_x -1;  // �����͸� ����

					}

				}
			}

			for(int x=0; x<=n-1; x++){      /* Ȧ�������� ǥ�� ����ϴ� �κ� */
				for(int y=0; y<=n-1; y++){

					cout << table[x][y] << " ";  // ���� �ϳ��ϳ��� �����
				}
				cout << endl;

			}

			cout << endl;

		}

	}while( n>=1 && n<=10 );  // n�� ���� ���� ���� �ƴ� ��� ����

}

void VerifyMabangjin(const int table[][TABLE_SIZE], const int size)
{

	int k = 0;  // k: �迭 sum[]�� ���� ������ �ϴ� ����
	int sum[20] = { 0 };  // sum[]: ��, ��, �밢���� �հ踦 �����ϴ� ����

	for(int x=0; x<=a_n-1; x++){      /* Ȧ�������� ǥ�� �� ���� �հ踦 ���ϴ� �κ� */
		for(int y=0; y<=a_n-1; y++){

			sum[k] = table[x][y] + sum[k];  // �� ���� �հ踦 ����
		}

		if(x+1 == 1) cout << "The sum of " << x+1 << "st row is " << sum[k] << "." << endl;
		else if(x+1 == 2) cout << "The sum of " << x+1 << "nd row is " << sum[k] << "." << endl;
		else if(x+1 == 3) cout << "The sum of " << x+1 << "rd row is " << sum[k] << "." << endl;
		else cout << "The sum of " << x+1 << "th row is " << sum[k] << "." << endl;               // �� ���� �հ踦 ���

		k++;
	}

	for(int y=0; y<=a_n-1; y++){      /* Ȧ�������� ǥ�� �� ���� �հ踦 ���ϴ� �κ� */
		for(int x=0; x<=a_n-1; x++){

			sum[k] = table[x][y] + sum[k];  // �� ���� �հ踦 ����
		}

		if(y+1 == 1) cout << "The sum of " << y+1 << "st column is " << sum[k] << "." << endl;
		else if(y+1 == 2) cout << "The sum of " << y+1 << "nd column is " << sum[k] << "." << endl;
		else if(y+1 == 3) cout << "The sum of " << y+1 << "rd column is " << sum[k] << "." << endl;
		else cout << "The sum of " << y+1 << "th column is " << sum[k] << "." << endl;               // �� ���� �հ踦 ���

		k++;
	}

	for(int x=0; x<=a_n-1; x++){  //  Ȧ�������� ǥ�� ���� �밢���� �հ踦 ���ϴ� �κ�

		sum[k] = table[x][x] + sum[k];  // ���� �밢���� �հ踦 ����
	}
	cout << "The sum of left diagonal line is " << sum[k] << "." << endl;  // ���� �밢���� �հ踦 ���
	k++;

	for(int x=0; x<=a_n-1; x++){  //  Ȧ�������� ǥ�� ������ �밢���� �հ踦 ���ϴ� �κ�

		sum[k] = table[ x ][ (a_n-1)-x ] + sum[k];  // ������ �밢���� �հ踦 ����
	}
	cout << "The sum of right diagonal line is " << sum[k] << "." << endl;  // ������ �밢���� �հ踦 ���

	cout << "All of sums are equal" << endl;

}

int main()
{
	int table[TABLE_SIZE][TABLE_SIZE];
	int size = TABLE_SIZE;

	Mabangjin(table, size);
	VerifyMabangjin(table, size);

	return 0;
}