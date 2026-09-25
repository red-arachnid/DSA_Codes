// You're given a list of students, each with (name, grade, age). Sort them with the following priority: 
// by grade descending, then by age ascending, then by name alphabetically.

#include<bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int grade;
    int age;

    Student(string name, int grade, int age) : name(name), grade(grade), age(age) {}

    bool operator<(const Student& o) const {
        // return o.grade < grade;
        // return age < o.age;
        // return name < o.name;
        return tie(o.grade, age, name) < tie(grade, o.age, o.name);
    }
};

int main() {
    vector<Student> students = {
        Student("Alice", 90, 20), 
        Student("Bob",85,22), 
        Student("Charlie",90,19), 
        Student("Dave",85,22), 
        Student("Eve",90,20)
    };

    for(Student s : students) {
        cout << s.name << "(" << s.grade << "," << s.age << ") ";
    }
    cout << '\n';

    sort(students.begin(), students.end());

    for(Student s : students) {
        cout << s.name << "(" << s.grade << "," << s.age << ") ";
    }
    cout << '\n';
    return 0;
}