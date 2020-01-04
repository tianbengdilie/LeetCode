#ifdef _DEBUG
#include"../head.h"
#endif

class FooBar {
private:
	int n;
	sem
public:
	FooBar(int n) {
		this->n = n;
		mb.lock();
		mf.unlock();
	}

	void foo(function<void()> printFoo) {
		for (int i = 0; i < n; i++) {
			mf.lock();
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			mb.unlock();
		}
	}

	void bar(function<void()> printBar) {
		for (int i = 0; i < n; i++) {
			mb.lock();
			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			mf.unlock();
			mb.lock();
		}
	}
};

#ifdef _DEBUG

void printFoo() {
	printf("Bar");
}

void printBar() {
	printf("Bar");
}

int main() {
	FooBar s(2);
	function<void()> printfBar = ::printBar;
	function<void()> printFoo = ::printFoo;
	thread th1(&FooBar::bar, &s, printfBar);
	thread th2(&FooBar::foo, &s, printFoo);
	th1.detach();
	th2.detach();
	Sleep(1000);
	return 0;
}
#endif