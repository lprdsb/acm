#include<iostream>
#include<filesystem>
#include<fstream>
#include<array>

namespace fs = std::filesystem;
using namespace std;
int main(){
	std::filesystem::path pi{ "in.txt" };
	bool exists = std::filesystem::exists(pi);
	if (exists) {
		std::cout << "The file exists.\n";
	}
    else {
		std::cout << "The file" << pi.filename() << "does not exist.\n";
	}
	std::error_code ec;
	std::uintmax_t size = fs::file_size(pi, ec);

	if (ec) {
		std::cout << "Error:" << ec.message() << "\n";
	}
	else {
		std::cout << "The file" << pi.filename() << "occupies" << size << "bytes\n";
	}
	//用ostream的构造函数打开文件
	std::wifstream ifs(pi);//打开103.json

	for (auto i = 0; i < 10; i++) {
		wchar_t s[10001];
		ifs.getline(s, 1000);
		wcout << s << endl;
	}
	return 0;
}