#include <iostream>
#include "Expr.h"
#include "Visitor.h"

//Test Cases

//Testing ConstExpr
void Test_Case_1_ConstExpr() {
    std::cout << "Test Case 1: ConstExpr" << std::endl;
    ConstExpr* c = new ConstExpr(42);
    Visitor* visitor = new NumVisitor();
    std::cout << "Expected: 42, Got: " << c->eval(visitor) << std::endl;
    //Cleanup
    delete c;
    delete visitor;
}

//Testing AddExpr
void Test_Case_2_AddExpr() {
    std::cout << "Test Case 2: AddExpr" << std::endl;
    ConstExpr* c1 = new ConstExpr(5);
    ConstExpr* c2 = new ConstExpr(3);
    AddExpr* add = new AddExpr(c1, c2);
    Visitor* visitor = new NumVisitor();
    std::cout << "Expected: 8, Got: " << add->eval(visitor) << std::endl;
    // Cleanup
    delete c1;
    delete c2;
    delete add;
    delete visitor;
}
//Testing SubExpr
void Test_Case_3_SubExpr() {
    std::cout << "Test Case 3: SubExpr" << std::endl;
    ConstExpr* c1 = new ConstExpr(10);
    ConstExpr* c2 = new ConstExpr(4);
    SubExpr* sub = new SubExpr(c1, c2);
    Visitor* visitor = new NumVisitor();
    std::cout << "Expected: 6, Got: " << sub->eval(visitor) << std::endl;
    // Cleanup
    delete c1;
    delete c2;
    delete sub;
    delete visitor;
}

//Testing MulExpr
void Test_Case_4_MulExpr() {
    std::cout << "Test Case 4: MulExpr" << std::endl;
    ConstExpr* c1 = new ConstExpr(7);
    ConstExpr* c2 = new ConstExpr(6);
    MulExpr* mul = new MulExpr(c1, c2);
    Visitor* visitor = new NumVisitor();
    std::cout << "Expected: 42, Got: " << mul->eval(visitor) << std::endl;
    // Cleanup
    delete c1;
    delete c2;
    delete mul;
    delete visitor;
}

//Testing DivExpr
void Test_Case_5_DivExpr() {
    std::cout << "Test Case 5: DivExpr" << std::endl;
    ConstExpr* c1 = new ConstExpr(8);
    ConstExpr* c2 = new ConstExpr(2);
    DivExpr* div = new DivExpr(c1, c2);
    Visitor* visitor = new NumVisitor();
    std::cout << "Expected: 4, Got: " << div->eval(visitor) << std::endl;
    // Cleanup
    delete c1;
    delete c2;
    delete div;
    delete visitor;
}

//Testing ModExpr
void Test_Case_6_ModExpr() {
    std::cout << "Test Case 6: ModExpr" << std::endl;
    ConstExpr* c1 = new ConstExpr(10);
    ConstExpr* c2 = new ConstExpr(3);
    ModExpr* mod = new ModExpr(c1, c2);
    Visitor* visitor = new NumVisitor();
    std::cout << "Expected: 1, Got: " << mod->eval(visitor) << std::endl;
    // Cleanup
    delete c1;
    delete c2;
    delete mod;
    delete visitor;
}

//Testing Nested Expressions
void Test_Case_7_NestedExpr() {
    std::cout << "Test Case 7: Nested Expressions" << std::endl;
    //Inner expressions
    ConstExpr* c1 = new ConstExpr(3);
    ConstExpr* c2 = new ConstExpr(4);
    AddExpr* add = new AddExpr(c1, c2); 
    ConstExpr* c3 = new ConstExpr(10);
    ConstExpr* c4 = new ConstExpr(8);
    SubExpr* sub = new SubExpr(c3, c4); 
    //Outer expression
    MulExpr* mul = new MulExpr(add, sub);
    Visitor* visitor = new NumVisitor();
    std::cout << "Expected: 14, Got: " << mul->eval(visitor) << std::endl;
    //Cleanup
    delete c1;
    delete c2;
    delete c3;
    delete c4;
    delete add;
    delete sub;
    delete mul;
    delete visitor;
}

//Main Function
int main() {
    Test_Case_1_ConstExpr();
    Test_Case_2_AddExpr();
    Test_Case_3_SubExpr();
    Test_Case_4_MulExpr();
    Test_Case_5_DivExpr();
    Test_Case_6_ModExpr();
    Test_Case_7_NestedExpr();

    return 0;
}
