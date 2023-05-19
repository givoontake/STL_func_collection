#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct stl_func {
	string funcName;
	string argument;
	string info;
    string return_type;

    void print() {
        cout << "이름: " << funcName << endl;
        cout << "인자: " << argument << endl;
        cout << "함수정보: " << info << endl;
        cout << "반환 타입: " << return_type << endl;
        cout << endl;
    }
};

void readFile();
void stl_info(string fName);

vector<stl_func> funcs;

int main()
{
    readFile();
    cout << "저장되어 있는 함수의 수: " << funcs.size() << endl;

    string fName;

    while (true) {
        cout << "찾는 함수 이름 입력: ";
        cin >> fName;

        stl_info(fName);
    }
}

void readFile()
{
    ifstream file("STL_functions.txt");

    if (!file) {
        cout << "Unable to open file.";
        exit(1);
    }

    string funcName, argument, info, return_type;

    while (getline(file, funcName) && getline(file, argument) && getline(file, info) && getline(file, return_type)) {
        stl_func temp;
        temp.funcName = funcName;
        temp.argument = argument;
        temp.info = info;
        temp.return_type = return_type;

        funcs.emplace_back(temp);
    }

    file.close();
}

void stl_info(string fName)
{
    bool found = false;
    for_each(funcs.begin(), funcs.end(), [&fName, &found](stl_func& f) {
        if (f.funcName == fName) {
            f.print();
            found = true;
        }
        });

    if (!found) {
        cout << "정보가 없는 함수이거나 잘못된 함수 이름입니다" << endl;
        found = false;
    }
}