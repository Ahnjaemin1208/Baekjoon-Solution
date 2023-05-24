#include <bits/stdc++.h>

using namespace std;

#define start 65
#define SIZE 51

int K, N, A;

string str;

bool Check(int idx) {
	//���ݱ����� Ȯ�ε� string
	string curr = str.substr(1, idx);

	//ã�ƾ��� ���� ������
	for (int i = curr.length() / K; i >= 1; i--) {

		//curr�� ������ ������ �񱳿� �����̵Ǵ� ���ڿ�
		string next = curr.substr(idx - i + 1, i);
		int curr_idx = idx - i - 1;

		for (int j = 2; j <= K; j++) {
			//���ӵ� ���ڿ��� �ֳ� üũ�ؾ� �ϴ� ���ڿ�
			string check = curr.substr(idx - j * i + 1, i);
			int check_idx = check.find(next);

			//���ӵ� ���ڿ��� �������� ����
			if (curr_idx == check_idx) break;
			//���ӵ� ���ڿ��� ������
			else if (j == K) return false;

			curr_idx = check_idx;
		}
	}
	return true;
}

int Backtracking(int idx) {
	//���� �ε����� ���ĺ��� �Ѿ�� �ʾ��� ��
	while (str[idx] < start + A) {
		//���ӵ� ���ڿ��� ���� �� ���� �ε����� �Ѿ��
		if (Check(idx))
			Backtracking(idx + 1);
		//���ӵ� ���ڿ��� ���� �� 
		//���� �ε����� ���� ���� ���ĺ����� �Ѿ��

		char temp[1] = { str[idx] + 1 };
		string t(temp);
		str.replace(idx, 1, t);
	}

	//���� �ε����� ���� ���ĺ����� �Ѿ�� ���
	//�� �� �ε����� ����
	//�� �� idx�� 1�϶��� ��¥ ������� ���
	if (idx == 1) {
		cout << -1;
		exit(0);
	}
	return;
}

int main(void) {
	cin >> K >> N >> A;

	char temp[SIZE];
	memset(temp, A, SIZE);
	str = string(temp);

	Backtracking(1);

}
