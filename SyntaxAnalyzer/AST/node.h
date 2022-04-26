#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <iostream>

class Node {
public:
    std::string nodeType;

    virtual std::string getName(){
        return "";
    } 
    virtual std::vector<Node*> getParameters(){
        return std::vector<Node*>();
    }       
    virtual Node* getDeclaration(){
        return NULL;
    }
    virtual Node* getExpression(){
        return NULL;
    }
    virtual std::vector <Node*> getListVal(){
         return std::vector<Node*>();
    }
    virtual int getIntVal(){
        return 0;
    }
    virtual double getRealVal(){
        return 0;
    }
    virtual bool getBooleanVal(){
        return 0;
    }
    virtual std::string getType(){
        return "";
    }   

    virtual void setDeclaration(Node* node){
        
    }
    virtual void setExpression(Node* node){

    }
    virtual void setName(std::string name){

    }
    virtual void addParameter(Node* node){

    }
    virtual void setIntVal(int x){

    }
    virtual void setRealVal(double x){

    }
    virtual void setBooleanVal(bool x){

    }
    virtual void addListVal(Node* x){

    }
    virtual void setType(std::string x){
        
    }
};

#endif //COMPILER_NODE_H