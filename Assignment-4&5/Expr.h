#ifndef EXPR_H
#define EXPR_H

#include <iostream>
#include "Visitor.h"

class Visitor;
//base class for all expressions
class Expr{
public:

    virtual ~Expr()= default;
     /**
     * Evaluate the expression using a visitor
     * @param visitor Pointer to the visitor that performs the evaluation
     * @return Result of evaluating the expression as a double
     */
    virtual double eval (Visitor* visitor)=0;

    
};
//class representing a constant expression
class ConstExpr :public Expr{
private:
    double value; 

public:
    /**
     * Constructor for ConstExpr
     * @param val The constant numerical value
     */
    ConstExpr (double val);

    //retrieve the constant value of the expression
    double getValue()const;

    //evaluate the constant expression using a visitor
    double eval( Visitor* visitor)override;
    
};
//class representing an addition expression
class AddExpr :public Expr {
private:
    Expr* left;  //left sub-expression
    Expr* right; //right sub-expression
public:
    /**
     * Constructor for AddExpr
     * @param l A pointer to the left sub-expression
     * @param r A pointer to the right sub-expression
     */
    AddExpr (Expr* l, Expr*r);

    //retrieve the left sub-expression
    Expr*getLeft()const;
    //retrieve the right sub-expression
    Expr* getRight() const;

   //evaluate the constant expression using a visitor
    double eval(Visitor* visitor) override;
};
//class representing a subtraction expression
class SubExpr : public Expr {
private:
    Expr* left;  //left sub-expression
    Expr*right; //right sub-expression

public:
    /**
     * Constructor for SubExpr
     * @param l Pointer to the left sub-expression
     * @param r pointer to the right sub-expression
     */
    SubExpr(Expr*l, Expr* r);

    //retrieve the left sub-expression
    Expr* getLeft()const;

    //retrieve the right sub-expression
    Expr*getRight() const;

   //evaluate the constant expression using a visitor
    double eval(Visitor* visitor)override;

};

//class representing a multiplication expression
class MulExpr: public Expr{
private:
    Expr* left;  //left sub-expression
    Expr* right; //right sub-expression

public:
    /**
     * Constructor for MulExpr
     * @param l pointer to the left sub-expression
     * @param r Pointer to the right sub-expression
     */
    MulExpr (Expr*l,Expr*r);

    //retrieve the left sub-expression
    Expr* getLeft()const;

    //retrieve the right sub-expression
    Expr*getRight()const;

   //evaluate the constant expression using a visitor
    double eval(Visitor* visitor) override;
};
//class representing a division expression
class DivExpr :public Expr{
private:

    Expr* left;  //left sub-expression
    Expr* right; //right sub-expression
public:

    /**
     * Constructor for DivExpr
     * @param l Pointer to the left sub-expression
     * @param r Pointer to the right sub-expression
     */
    DivExpr(Expr*l,Expr* r);

    //retrieve the left sub-expression
    Expr* getLeft()const;

    //retrieve the right sub-expression
    Expr*getRight() const;

   //evaluate the constant expression using a visitor
    double eval(Visitor* visitor) override;
};
//class representing a modulus expression
class ModExpr : public Expr{
private:
    Expr* left;  //left sub-expression
    Expr*right; //right sub-expression
public:
    /**
     * Constructor for ModExpr
     * @param l Pointer to the left sub-expression
     * @param r Pointer to the right sub-expression
     */
    ModExpr (Expr*l, Expr*r);

    //retrieve the left sub-expression
    Expr*getLeft()const;

    //retrieve the right sub-expression
    Expr*getRight() const;

   //evaluate the constant expression using a visitor
    double eval(Visitor* visitor) override;
};

#endif 
