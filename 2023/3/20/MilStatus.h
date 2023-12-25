#pragma once
#include <array>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
constexpr int MAX_CAPACITY = 10;

class member
{
private:
    static int numberOfObjects;
public:
    static int getNumberOfObjects() { return numberOfObjects; }
    friend class MilStatus;
};

class MilStatus {
private:
    int age{ 0 };
    string name;
    // std::string equipments[10]{"Armor", "Blade", "Horse", "Sword"};
    std::array<std::string, MAX_CAPACITY> equipments;
    int equipNum{ 0 };
    
public:
    // friend class member;
    friend int getNumberOfObjects();

    MilStatus(string name, int age,
        std::array<std::string, MAX_CAPACITY> equipments, int equipNum);
    MilStatus();
    MilStatus(MilStatus&);
    int getAge();

    std::string getName();

    std::array<std::string, MAX_CAPACITY> getEquipments();
    int getEquipNum() { return equipNum; }  // 内联函数

    void setAge(int age);
    void setName(std::string name);
    void setEquipments(std::array<std::string, MAX_CAPACITY> equip);
    void setEquipNum(int num);
    //int getNumberOfObjects2() { return numberOfObjects; }
    ~MilStatus();
};