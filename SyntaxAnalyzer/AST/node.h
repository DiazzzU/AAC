#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <SyntaxAnalyzer/AST/memory.h>

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
    virtual std::string getStringVal(){
        return "";
    }
    virtual std::string getType(){
        return "";
    }   
    virtual Node* getBody(){
        return NULL;
    }
    virtual std::vector<Node*> getExpressions(){
        return std::vector<Node*>();
    }
    virtual std::vector <Node*> getArrayVal() {
        return std::vector<Node*>();
    }
    virtual std::map < std::string, Node*> getRecordVal() {
        return std::map < std::string, Node*>();
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
     virtual void setStringVal(std::string x){
       
    }
    virtual void addListVal(Node* x){

    }
    virtual void setType(std::string x){
        
    }
    virtual void setBody(Node* body){

    }
    virtual void addExpression(Node* expression){

    }
    virtual void addArrayVal(Node* val){

    }
    virtual void addRecordVal(std::string key, Node* val){

    }

    virtual Node* codegen(Memory* memory) {
        return NULL;
    };
    virtual void print() {

    }

};

#endif //COMPILER_NODE_H