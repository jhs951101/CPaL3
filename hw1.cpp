#include <iostream>
#include <iomanip>
#define TABLE_SIZE			10

using namespace std;

int a_n;  // a_n: n의 값을 저장하는 변수(VerifyMabangjin()에서만 사용)

void Mabangjin(int table[][TABLE_SIZE], const int size)
{

	int n;  // n: 홀수마방진의 표 길이(n*n, 입력받음)

	do{

		cout << "Input the number(1-10): ";
		cin >> n;  // 표 길이를 입력받음

		if( n>=1 && n<=10 ){  // n의 값이 범위 내일 경우에만 진행

			if(n == 10) break;  // n=11(10+1) 이므로 출력 불가능, 종료
			else{

				for (int x=0; x<TABLE_SIZE; x++)      // x: 배열의 행을 제어, y: 배열의 열을 제어
					for (int y=0; y<TABLE_SIZE; y++)
						table[x][y] = 0;  // table[][]: 홀수마방진을 진행하기 위한 2차원 배열
			}                                         // 2차원 배열 전체에 0을 저장함

			if(n%2 == 0) n = n+1;  // n의 값이 짝수이면 n+1
			a_n = n;  // n의 값을 전역변수 a(윗부분 참고)에 넣어줌

			for(int x=0; x<=n-1; x++){
				for(int y=0; y<=n-1; y++){  // x: 배열의 행을 제어, y: 배열의 열을 제어

					table[x][y] = -1;  /* 홀수마방진 표 내부를 전부 -1로 함
							              ※ 0: 홀수마방진 표 외부, -1: 표 내부(빈 칸) */
				}
			}

			table[ n-1 ][ (n-1)/2 ] = 1;  // 표 맨 밑줄 가운데 열에 1을 저장함
			int point_x = n-1;      // point_x: 배열의 행 포인터
			int point_y = (n-1)/2;  // point_y: 배열의 열 포인터
									// 초기에는 1이 저장된 곳을 포인터로 지정함


			for(int a=2; a<=pow(n,2); a++){  // a: 홀수마방진 표에 저장할 숫자
						                     /* 홀수마방진 표에 숫자를 저장하는 부분 */

				if( table[ point_x +1 ][ point_y +1 ] == -1){  // 포인터의 오른쪽아래가 빈 칸(표 내부)일 경우

					table[ point_x +1 ][ point_y +1 ] = a;  // 홀수마방진 표에 숫자를 저장함
					point_x = point_x +1;
					point_y = point_y +1;  /* 포인터를 변경 */

				} else if( table[ point_x +1 ][ point_y +1 ] > 0){  // 포인터의 오른쪽아래에 숫자가 존재할 경우

					table[ point_x -1 ][ point_y ] = a;  // 홀수마방진 표에 숫자를 저장함
					point_x = point_x -1;  // 포인터를 변경

				} else{  // 포인터의 오른쪽아래에 표 외부일 경우

					if( table[ 0 ][ point_y +1 ] != 0){ // 포인터의 오른쪽아래의 제일위쪽이 표내부일 경우

						table[ 0 ][ point_y +1 ] = a;  // 홀수마방진 표에 숫자를 저장함
						point_x = 0;
						point_y = point_y +1;  /* 포인터를 변경 */

					} else if( table[ point_x +1 ][ 0 ] != 0){  // 포인터의 오른쪽아래의 제일 왼쪽이 표 내부일 경우

						table[ point_x +1 ][ 0 ] = a;  // 홀수마방진 표에 숫자를 저장함
						point_x = point_x +1;
						point_y = 0;          /* 포인터를 변경 */

					}else{  // 포인터의 오른쪽아래의 제일 위쪽도 왼쪽도 표 외부일 경우

						table[ point_x -1 ][ point_y ] = a; // 포인터의 바로윗부분에 숫자를 저장함
						point_x = point_x -1;  // 포인터를 변경

					}

				}
			}

			for(int x=0; x<=n-1; x++){      /* 홀수마방진 표를 출력하는 부분 */
				for(int y=0; y<=n-1; y++){

					cout << table[x][y] << " ";  // 숫자 하나하나씩 출력함
				}
				cout << endl;

			}

			cout << endl;

		}

	}while( n>=1 && n<=10 );  // n의 값이 범위 내가 아닐 경우 종료

}

void VerifyMabangjin(const int table[][TABLE_SIZE], const int size)
{

	int k = 0;  // k: 배열 sum[]의 보조 역할을 하는 변수
	int sum[20] = { 0 };  // sum[]: 행, 열, 대각선의 합계를 저장하는 변수

	for(int x=0; x<=a_n-1; x++){      /* 홀수마방진 표의 각 행의 합계를 구하는 부분 */
		for(int y=0; y<=a_n-1; y++){

			sum[k] = table[x][y] + sum[k];  // 각 행의 합계를 구함
		}

		if(x+1 == 1) cout << "The sum of " << x+1 << "st row is " << sum[k] << "." << endl;
		else if(x+1 == 2) cout << "The sum of " << x+1 << "nd row is " << sum[k] << "." << endl;
		else if(x+1 == 3) cout << "The sum of " << x+1 << "rd row is " << sum[k] << "." << endl;
		else cout << "The sum of " << x+1 << "th row is " << sum[k] << "." << endl;               // 각 행의 합계를 출력

		k++;
	}

	for(int y=0; y<=a_n-1; y++){      /* 홀수마방진 표의 각 열의 합계를 구하는 부분 */
		for(int x=0; x<=a_n-1; x++){

			sum[k] = table[x][y] + sum[k];  // 각 열의 합계를 구함
		}

		if(y+1 == 1) cout << "The sum of " << y+1 << "st column is " << sum[k] << "." << endl;
		else if(y+1 == 2) cout << "The sum of " << y+1 << "nd column is " << sum[k] << "." << endl;
		else if(y+1 == 3) cout << "The sum of " << y+1 << "rd column is " << sum[k] << "." << endl;
		else cout << "The sum of " << y+1 << "th column is " << sum[k] << "." << endl;               // 각 행의 합계를 출력

		k++;
	}

	for(int x=0; x<=a_n-1; x++){  //  홀수마방진 표의 왼쪽 대각선의 합계를 구하는 부분

		sum[k] = table[x][x] + sum[k];  // 왼쪽 대각선의 합계를 구함
	}
	cout << "The sum of left diagonal line is " << sum[k] << "." << endl;  // 왼쪽 대각선의 합계를 출력
	k++;

	for(int x=0; x<=a_n-1; x++){  //  홀수마방진 표의 오른쪽 대각선의 합계를 구하는 부분

		sum[k] = table[ x ][ (a_n-1)-x ] + sum[k];  // 오른쪽 대각선의 합계를 구함
	}
	cout << "The sum of right diagonal line is " << sum[k] << "." << endl;  // 오른쪽 대각선의 합계를 출력

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