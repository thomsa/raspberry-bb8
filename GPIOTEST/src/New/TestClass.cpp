#include "TestClass.h"
#include <stdio.h>

void TestClass::doThis()
{
    printf("hurray\n");

}

TestClass::TestClass()
{
    printf("initiating testclass\n");
    //ctor
}

TestClass::~TestClass()
{
    //dtor
}

int TestClass::asd() {
return 0;
}
