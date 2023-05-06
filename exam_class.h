#include<iostream>
#include<string>
#include<fstream>
#include<authorization.h>
#include<essay_class.h>
#include<obj_class.h>
using namespace std;
class exam_system:public essay,public objective,public teacher, public student {
};