#include "ring.h"

void logics1(ring&);

void logics()
{	
	int key = 0;
	std::cout << "To create an empty buffer enter 1 " <<'\n';
	std::cout << "To create a buffer with elements, enter 2 " <<'\n';
	std::cout <<'\n';
	std::cout << "Enter 0 to exit" <<'\n';
	std::cin >> key;
	std::cout <<'\n';
	if(key == 1){
		ring a;
		std::cout << " Your buffer was created successfully " <<'\n';
		std::cout <<'\n';
		logics1(a);
	}
	if(key == 2){
		int size = 0;
		std::cout << "Enter the number of elements in the buffer, (minimum number of elements 1)" <<'\n';
		std::cout <<'\n';
		std::cin >> size;
		std::cout <<'\n';
		assert(size >= 1);
		ring a(size, 0);
		std::cout << "Your buffer of  "<< size <<"  elements has been successfully created"<<'\n';
		std::cout <<'\n';
		logics1(a);
	}
	if(key == 0){
    	std::cout << "goodbye"<<'\n';
		exit(0);
	}
	else{
		std::cout << "wrong input !" <<'\n';
		std::cout <<'\n';
		logics();
	}
}

void logics1(ring& a)
{
    int key = 0;
    std::cout << "To add data to the next container, enter 1" <<'\n';
    std::cout << "To add data to the previous container, enter 2" <<'\n';
	std::cout << "To see the data in the current container, type 3" <<'\n';
	std::cout << "To see the entire list, enter 4" <<'\n';
	std::cout << "To move to the next container, enter 5" <<'\n';
    std::cout << "To go to the previous container type 6" <<'\n';
	std::cout << "To remove the current container, enter 7" <<'\n';
	std::cout << "To reset the buffer, enter 8" <<'\n';
    std::cout << "To delete the buffer enter 9" <<'\n';
	std::cout << "To change the value of the current container, enter 10" <<'\n';
	std::cout << "To find out if the buffer is empty or not enter 11" <<'\n';
	std::cout <<'\n';
	std::cout << "To return to the previous menu enter 0" <<'\n';
    std::cin >>key;
    std::cout <<'\n';
    if(key == 1){
        int value = 0;
		std::cout <<'\n';
        std::cout << "Enter what you want to add " <<'\n';
        std::cin >>value;
        std::cout << '\n';
        a.push_next(value);
        std::cout <<"Adding was successful"<<'\n';
        std::cout << '\n';
		logics1(a);
    }
    if(key == 2){
        int value = 0;
        std::cout << "Enter what you want to add " <<'\n';
        std::cin >>value;
        std::cout << '\n';
        a.push_prev(value);
		std::cout <<'\n';
        std::cout <<"Adding was successful"<<'\n';
        std::cout << '\n';
		logics1(a);
    }
	if(key == 3){
    	std::cout <<'\n';
    	a.print();
		std::cout <<'\n';
		logics1(a);
	}
	if(key == 4){
		std::cout <<'\n';
        a.print_all();
		std::cout <<'\n';
        logics1(a);
	}
	if(key == 5){
		a.go_next();
		std::cout <<'\n';
		logics1(a);
	}
	if(key == 6){
        a.go_prev();
		std::cout <<'\n';
        logics1(a);
    }
	if(key == 7){
		a.pull();
		std::cout <<'\n';
		logics1(a);
	}
	if(key == 8){
		a.reset();
		std::cout <<'\n';
		logics1(a);
	}
	if(key == 9){
		a.clear();
		std::cout <<'\n';
		logics();
	}
	if(key == 10){
		int value = 0;
		std::cout << "Enter new value" <<'\n';
		std::cin >> value;
		a.change(value);
		std::cout <<'\n';
        logics1(a);
	}
	if(key == 11){
		std::cout <<'\n';
		std::cout<<a.size()<<'\n';
		std::cout <<'\n';
		logics1(a);
	}
	if(key == 0){
    	
	}
    else{
		std::cout <<'\n';
        std::cout << "wrong input !" <<'\n';
        std::cout <<'\n';
		logics1(a);
    }
logics();
}

int main()
{
	logics();
	return 0;
}

