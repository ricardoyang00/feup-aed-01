/**
 * @file Data.h
 * @brief Definition of the Class, Schedule, and Student classes and the StudentBST data structure.
 */

#ifndef PROJETO_AED_DATA_H
#define PROJETO_AED_DATA_H

#include "UtilityFunctions.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <set>
#include <fstream>

/**
 * @brief Class represents a course class.
 */
class Class {
public:
    string UcCode;
    string ClassCode;

    Class(string ucCode, string classCode);
    Class();
    bool operator==(const Class& other) const;
    bool operator<(const Class& other) const;
};

class Schedule {
public:
    Class UcToClasses;
    string WeekDay;
    float StartHour;
    float Duration;
    string Type;

    Schedule(Class ucToClass, string weekday, float startHour, float duration, string type);
    Schedule();
    bool operator<(const Schedule& other) const;
};

class Student {
public:
    int StudentCode;
    string StudentName;
    vector<Class> UcToClasses;

    Student(int studentCode, string studentName);
    Student();
    bool operator<(const Student& other) const;
};

// Structure used in the construction of StudentBST
struct Node {
    Student data;
    Node* left;
    Node* right;

    Node(const Student& student) : data(student), left(nullptr), right(nullptr) {}
};

// Binary search tree to store 'Student' objects
class StudentBST {
private:
    Node* root; // Pointer to the root of the BST
    Node* insertStudent(Node* root, const Student& student); // Recursive method to insert a student into the BST
    // Recursive method for in-order traversal
    Student* searchByCode(Node* root, int studentCode); // Recursive method to search for a student with its StudentCode
    void inOrderTraversal(Node* node, function<void(const Student&)> action);
public:
    StudentBST();
    Node* getRoot();
    void setRoot(Node* newRoot);
    void insertStudent(int studentCode, const string& studentName, vector<Class> ucToClasses); // Insert a new student into the BST
    Student* searchByCode(int studentCode); // Search for a student with its StudentCode
    // Search for all students with StudentName or partial StudentName (case insensitive)
    void searchAllByName(const string& searchName, vector<Student>& matchingStudents);
    void searchStudentsInAtLeastNUCs(const int n, set<Student>& matchingStudents);
    void searchStudentsWithin(const function<bool(const Class&)> searchCriteria, set<Student>& matchingStudents);

    void getStudentsCountInClass(const string& ucCode, map<string, int>& classStudentsCount);
    void getStudentsCountInUc(const string& ucCode, map<string, int>& ucStudentsCount);

    int countStudentsInClass(const string& classCode);
    int countStudentsInUC(const string& ucCode);
    int countStudentsInYear(const string& year);

    void saveToCSV(const string& filename);
};

#endif //PROJETO_AED_DATA_H