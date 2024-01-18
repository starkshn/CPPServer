#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include <thread>

void HelloThread()
{
	cout << "Hello Thread!" << endl;
}

void HelloWorld2(int32 num)
{
	cout << "Hello Thread : " << num << endl;
}

int main()
{
	std::thread t;

	// CPU �ھ� ����
	int32 cnt = t.hardware_concurrency(); cout << cnt << endl;

	// ������ ���� id
	auto id1 = t.get_id(); cout << id1 << endl;

	t = std::thread(HelloThread);
	std::thread t2 = std::thread(HelloWorld2, 20);

	// std::thread��ü���� ���� �����带 �и� (�������� ���� ���μ��� -> �� �׶���)
	// t.detach();

	auto id2 = t.get_id(); cout << id2 << endl;

	if (t.joinable())
		t.join();

	return 0;
}
