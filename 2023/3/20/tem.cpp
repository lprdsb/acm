#include "MilStatus.h"

MilStatus::MilStatus(string name, int age, std::array<std::string, MAX_CAPACITY> equipments, int equipNum)
    : age(age), name(name), equipments(equipments), equipNum(equipNum) {
    static int numberOfObjects;
    numberOfObjects++;
}
MilStatus::MilStatus() : MilStatus("", 15, { "" }, 0) {}  // 调用有参构造函数，代理构造

int MilStatus::getAge() { return age; }

std::string MilStatus::getName() { return name; }

std::array<std::string, MAX_CAPACITY> MilStatus::getEquipments() {
	return equipments;
}

// 下面的函数改为内联函数
// int MilStatus::getEquipNum() { return equipNum; }

void MilStatus::setAge(int age) { this->age = age; }
void MilStatus::setName(std::string name) { this->name = name; }
void MilStatus::setEquipments(std::array<std::string, MAX_CAPACITY> equip) {
	equipments = equip;
}
void MilStatus::setEquipNum(int num) { equipNum = num; }
MilStatus::~MilStatus() {
    numberOfObjects--;
}
