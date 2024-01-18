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

	// CPU 코어 개수
	int32 cnt = t.hardware_concurrency(); cout << cnt << endl;

	// 쓰레드 마다 id
	auto id1 = t.get_id(); cout << id1 << endl;

	t = std::thread(HelloThread);
	std::thread t2 = std::thread(HelloWorld2, 20);

	// std::thread객체에서 실제 쓰레드를 분리 (리눅스의 데몬 프로세스 -> 백 그라운드)
	// t.detach();

	auto id2 = t.get_id(); cout << id2 << endl;

	if (t.joinable())
		t.join();

	return 0;
}
