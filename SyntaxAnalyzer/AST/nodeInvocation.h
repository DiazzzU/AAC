#ifndef COMPILER_NODEINVOCATION_H
#define COMPILER_NODEINVOCATION_H

#include <string>
#include <vector>
#include "node.h"
#include <SyntaxAnalyzer/Semantics/Literal.h>
#include <SyntaxAnalyzer/Semantics/Integer.h>
#include <SyntaxAnalyzer/Semantics/Real.h>
#include <SyntaxAnalyzer/Semantics/Boolean.h>
#include <SyntaxAnalyzer/Semantics/String.h>
#include <SyntaxAnalyzer/Semantics/List.h>
#include <SyntaxAnalyzer/Semantics/Array.h>


class NodeInvocation: public Node {
public:
    std::string name;
    std::vector<Node*> parameters;
    Node* declaration;
    std::string type;
    std::string invocType;

    NodeInvocation() {
        this->nodeType = "Invocation";
        this->invocType = "Default";
    }

    std::string getName() {
        return name;
    }
    std::vector <Node*> getParameters() {
        return parameters;
    }
    Node* getDeclaration() {
        return declaration;
    }
    std::string getType() {
        return type;
    }
    std::string getInvocType() {
        return invocType;
    }

    void setDeclaration(Node* declaration) {
        this->declaration = declaration;
    }
    void setName(std::string name) {
        this->name = name;
    }
    void addParameter(Node* node) {
        parameters.push_back(node);
    }
    void setType(std::string type) {
        this->type = type;
    }
    void setInvocType(std::string x){
        this->invocType = x;
    }


    Literal* codegen(Memory* memory) {
        if (name == "plus") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);

            if (element1->getType() != "Integer" && element1->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer" && element2->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }

            if (element1->getType() == "Real" || element2->getType() == "Real") {
                Real* nodeReal = new Real();
                nodeReal->setRealVal((element1->getRealVal() + element1->getIntVal()) + (element2->getRealVal() + element2->getIntVal()));
                return nodeReal;
            }

            Integer* node = new Integer();
            node->setIntVal(element1->getIntVal() + element2->getIntVal());
            return node;
        }
        else if (name == "minus") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);

            if (element1->getType() != "Integer" && element1->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer" && element2->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }

            if (element1->getType() == "Real" || element2->getType() == "Real") {
                Real* node = new Real();
                node->setRealVal((element1->getRealVal() + element1->getIntVal()) - (element2->getRealVal() + element2->getIntVal()));
                return node;
            }

            Integer* node = new Integer();
            node->setIntVal(element1->getIntVal() - element2->getIntVal());
            return node;
        } 
        else if (name == "div") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);

            if (element1->getType() != "Integer" && element1->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer" && element2->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }

            Real* node = new Real();
            node->setRealVal((element1->getRealVal() + element1->getIntVal()) / (element2->getRealVal() + element2->getIntVal()));
            return node;   
        }
        else if (name == "mul") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);

            if (element1->getType() != "Integer" && element1->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer" && element2->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }

            if (element1->getType() == "Real" || element2->getType() == "Real") {
                Real* node = new Real();
                node->setRealVal((element1->getRealVal() + element1->getIntVal()) * (element2->getRealVal() + element2->getIntVal()));
                return node;
            }

            Integer* node = new Integer();
            node->setIntVal(element1->getIntVal() * element2->getIntVal());
            return node;
        }
        else if (name == "equal") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);

            if (element1->getType() != "Integer" && element1->getType() != "Real" && element1->getType() != "String") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer" && element2->getType() != "Real" && element2->getType() != "String") {
                std::cout << "TypeError";
                exit(0);
            }

            if (element1->getType() !=  element1->getType()) {
                std::cout << "TypeError";
                exit(0);
            }
            const double eps = 1e-10;
            bool res = (abs(element1->getIntVal() - element2->getIntVal()) < eps &&
                        fabs(element1->getRealVal() - element2->getRealVal()) < eps && 
                        element1->getStringVal() == element2->getStringVal());

            Boolean* node = new Boolean();
            node->setBooleanVal(res);
            return node;
        }
        else if (name == "nonequal") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);

            if (element1->getType() != "Integer" && element1->getType() != "Real" && element1->getType() != "String") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer" && element2->getType() != "Real" && element2->getType() != "String") {
                std::cout << "TypeError";
                exit(0);
            }

            if (element1->getType() !=  element1->getType()) {
                std::cout << "TypeError";
                exit(0);
            }

            Boolean* node = new Boolean();
            const double eps = 1e-10;
            if (element1->getType() == "Integer") {
                node->setBooleanVal(element1->getIntVal() != element2->getIntVal());
            }
            if (element1->getType() == "String") {
                node->setBooleanVal(element1->getStringVal() != element2->getStringVal());
            }
            if (element1->getType() == "Real") {
                node->setBooleanVal(fabs(element1->getRealVal() - element2->getRealVal()) > eps);
            }
            return node;
        }
        else if (name == "less") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);

            if (element1->getType() != "Integer" && element1->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer" && element2->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }

            if (element1->getType() !=  element1->getType()) {
                std::cout << "TypeError";
                exit(0);
            }

            Boolean* node = new Boolean();
            const double eps = 1e-10;
            if (element1->getType() == "Integer") {
                node->setBooleanVal(element1->getIntVal() < element2->getIntVal());
            }
            if (element1->getType() == "Real") {
                node->setBooleanVal(element1->getRealVal() - element2->getRealVal() < -eps);
            }
            return node;
        }
        else if (name == "lesseq") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);

            if (element1->getType() != "Integer" && element1->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer" && element2->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }

            if (element1->getType() !=  element1->getType()) {
                std::cout << "TypeError";
                exit(0);
            }

            Boolean* node = new Boolean();
            const double eps = 1e-10;
            if (element1->getType() == "Integer") {
                node->setBooleanVal(element1->getIntVal() <= element2->getIntVal());
            }
            if (element1->getType() == "Real") {
                node->setBooleanVal(element1->getRealVal() - element2->getRealVal() < eps);
            }
            return node;
        }
        else if (name == "greater") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);

            if (element1->getType() != "Integer" && element1->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer" && element2->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }

            if (element1->getType() !=  element1->getType()) {
                std::cout << "TypeError";
                exit(0);
            }

            Boolean* node = new Boolean();
            const double eps = 1e-10;
            if (element1->getType() == "Integer") {
                node->setBooleanVal(element1->getIntVal() > element2->getIntVal());
            }
            if (element1->getType() == "Real") {
                node->setBooleanVal(element1->getRealVal() - element2->getRealVal() > eps);
            }
            return node;
        }
        else if(name == "greatereq") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);

            if (element1->getType() != "Integer" && element1->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer" && element2->getType() != "Real") {
                std::cout << "TypeError";
                exit(0);
            }

            if (element1->getType() !=  element1->getType()) {
                std::cout << "TypeError";
                exit(0);
            }

            Boolean* node = new Boolean();
            const double eps = 1e-10;
            if (element1->getType() == "Integer") {
                node->setBooleanVal(element1->getIntVal() >= element2->getIntVal());
            }
            if (element1->getType() == "Real") {
                node->setBooleanVal(element1->getRealVal() - element2->getRealVal() > -eps);
            }
            return node;
        }
        else if (name == "isint") {
            Literal* element1 = parameters[0]->codegen(memory);
            Boolean* node = new Boolean();
            node->setBooleanVal(false);
            if(element1->getType() == "Integer") {
                node->setBooleanVal(true);
            }
            return node;
        }
        else if (name == "isreal") {
            Literal* element1 = parameters[0]->codegen(memory);
            Boolean* node = new Boolean();
            node->setBooleanVal(false);
            if(element1->getType() == "Real") {
                node->setBooleanVal(true);
            }
            return node;
        }
        else if (name == "isbool") {
            Literal* element1 = parameters[0]->codegen(memory);
            Boolean* node = new Boolean();
            node->setBooleanVal(false);
            if(element1->getType() == "Boolean") {
                node->setBooleanVal(true);
            }
            return node;
        }
        else if (name == "islist") {
            Literal* element1 = parameters[0]->codegen(memory);
            Boolean* node = new Boolean();
            node->setBooleanVal(false);
            if(element1->getType() == "List") {
                node->setBooleanVal(true);
            }
            return node;
        }
        else if (name == "isstring") {
            Literal* element1 = parameters[0]->codegen(memory);
            Boolean* node = new Boolean();
            node->setBooleanVal(false);
            if(element1->getType() == "String") {
                node->setBooleanVal(true);
            }
            return node;
        }
        else if (name == "or") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);
            Boolean* node = new Boolean();
            if (element1->getType() != "Boolean" || element2->getType() != "Boolean") {
                std::cout << "TypeError";
                exit(0);
            }
            node->setBooleanVal(element1->getBooleanVal() | element2->getBooleanVal());
            return node;
        }
        else if (name == "and") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);
            Boolean* node = new Boolean();
            if (element1->getType() != "Boolean" || element2->getType() != "Boolean") {
                std::cout << "TypeError";
                exit(0);
            }
            node->setBooleanVal(element1->getBooleanVal() & element2->getBooleanVal());
            return node;
        }
        else if (name == "xor") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);
            Boolean* node = new Boolean();
            if (element1->getType() != "Boolean" || element2->getType() != "Boolean") {
                std::cout << "TypeError";
                exit(0);
            }
            node->setBooleanVal(element1->getBooleanVal() ^ element2->getBooleanVal());
            return node;
        }
        else if (name == "not") {
            Literal* element1 = parameters[0]->codegen(memory);
            Boolean* node = new Boolean();
            if (element1->getType() != "Boolean") {
                std::cout << "TypeError";
                exit(0);
            }
            node->setBooleanVal(!element1->getBooleanVal());
            return node;
        }
        else if (name == "read-line") {
            std::string x;
            int intVal = 0;
            double realVal = 0;
            std::cin >> x;

            bool real = false;
            bool integer = true;
            for (int i = 0; i < x.size(); i++) {
                if (x[i] == '.') {
                    real = true;
                    continue;
                }
                integer &= isdigit(x[i]);
            }

            if (type == "String") {
                String* node = new String();
                node->setStringVal(x);
                return node;
            }

            if (type == "Integer" && !real && integer) {
                Integer* node = new Integer();
                node->setIntVal(stoi(x));
                return node;
            }
            if (type == "Real" && real && integer) {
                Real* node = new Real();
                node->setRealVal(stoi(x));
                return node;
            }
            if (type == "Boolean" && x == "true") {
                Boolean* node = new Boolean();
                node->setBooleanVal(true);
                return node;
            }
            if (type == "Boolean" && x == "false") {
                Boolean* node = new Boolean();
                node->setBooleanVal(false);
                return node;
            }
            
            std::cout << "TypeError";
            exit(0);
        }
        else if (name == "cond") {
            for (int i = 0; i < parameters.size(); i += 2){
                Literal* element1 = parameters[i]->codegen(memory);
                if (element1->getType() != "Boolean") {
                    std::cout << "TypeError";
                    exit(0);
                }
                if (element1->getBooleanVal() == true) {
                    return parameters[i+1]->codegen(memory);
                }
            }
            return new Literal();
        }
        else if (name == "head") {
            Literal* element = parameters[0]->codegen(memory);
            if (element->getType() != "List") {
                std::cout << "TypeError";
                exit(0);
            }

            if (element->getListVal().size() == 0) {
                std::cout << "Empty List Exception";
                exit(0);
            }

            return element->getListVal()[0];
        }
        else if (name == "tail") {
            Literal* element = parameters[0]->codegen(memory);
            if (element->getType() != "List") {
                std::cout << "TypeError";
                exit(0);
            }
            std::vector <Literal*> lst = element->getListVal();

            if (lst.size() == 0) {
                std::cout << "Empty List Exception";
                exit(0);
            }

            return lst[lst.size() - 1];
        }
        else if (name == "rest") {
            Literal* element = parameters[0]->codegen(memory);
            if (element->getType() != "List") {
                std::cout << "TypeError";
                exit(0);
            }

            std::vector <Literal*> lst = element->getListVal();
            List* node = new List();

            if (lst.size() == 0) {
                std::cout << "Empty List Exception";
                exit(0);
            }
            
            for (int i = 1; i < lst.size(); i++) {
                node->addListVal(lst[i]);
            }
            return node;
        }
        else if (name == "empty") {
            Literal* element = parameters[0]->codegen(memory);
            if (element->getType() != "List") {
                std::cout << "TypeError";
                exit(0);
            }
            bool res = (element->getListVal().size() == 0);
            Boolean* node = new Boolean();
            node->setBooleanVal(res);
            return node;
        }
        else if (name == "append") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);
            if (element1->getType() != "List") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "List") {
                std::cout << "TypeError";
                exit(0);
            }
            std::vector <Literal*> lst1 = element1->getListVal();
            std::vector <Literal*> lst2 = element2->getListVal();

            List* node = new List();

            for (auto x : lst1) {
                node->addListVal(x);
            }
            for (auto x : lst2) {
                node->addListVal(x);
            }
            return node;
        }
        else if (name == "array-rem") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);
            if (element1->getType() != "Array") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer") {
                std::cout << "TypeError";
                exit(0);
            }

            std::vector <Literal*> arr = element1->getArrayVal();
            Array* node = new Array();
            int index = element2->getIntVal();

            if (index >= arr.size()) {
                std::cout << "Array out of bound rxception";
                exit(0);
            }

            for (int i = 0; i < index; i ++) {
                node->addArrayVal(arr[i]);
            }
            for (int i = index + 1; i < arr.size(); i ++) {
                node->addArrayVal(arr[i]);
            }

            return node;
        }
        else if (name == "array-get") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);
            if (element1->getType() != "Array") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer") {
                std::cout << "TypeError";
                exit(0);
            }

            std::vector <Literal*> arr = element1->getArrayVal();
            int index = element2->getIntVal();

            if (index >= arr.size()) {
                std::cout << "Array out of bound rxception";
                exit(0);
            }
            return arr[index];
        }
        else if (name == "array-add") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);
            Literal* element3 = parameters[2]->codegen(memory);
            if (element1->getType() != "Array") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer") {
                std::cout << "TypeError";
                exit(0);
            }

            std::vector <Literal*> arr = element1->getArrayVal();
            int index = element2->getIntVal();

            if (arr.size() && arr[0]->getType() != element3->getType()) {
                std::cout << "TypeError";
                exit(0);
            }

            if (index > arr.size()) {
                std::cout << "Array out of bound rxception";
                exit(0);
            }
            
            Array* node = new Array();
            for (int i = 0; i < index; i++) {
                node->addArrayVal(arr[i]);
            }
            node->addArrayVal(element3);
            for (int i = index; i < arr.size(); i++) {
                node->addArrayVal(arr[i]);
            }
            return node;
        }
        else if (name == "array-set") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);
            Literal* element3 = parameters[2]->codegen(memory);
            if (element1->getType() != "Array") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "Integer") {
                std::cout << "TypeError";
                exit(0);
            }

            std::vector <Literal*> arr = element1->getArrayVal();
            int index = element2->getIntVal();

            if (arr.size() && arr[0]->getType() != element3->getType()) {
                std::cout << "TypeError";
                exit(0);
            }

            if (index >= arr.size()) {
                std::cout << "Array out of bound rxception";
                exit(0);
            }
            
            Array* node = new Array();
            for (int i = 0; i < index; i++) {
                node->addArrayVal(arr[i]);
            }
            node->addArrayVal(element3);
            for (int i = index + 1; i < arr.size(); i++) {
                node->addArrayVal(arr[i]);
            }
            return node;
        }
        else if (name == "record-keywords") {
            Literal* element = parameters[0]->codegen(memory);
            if (element->getType() != "Record") {
                std::cout << "TypeError";
                exit(0);
            }
            List* node = new List();
            std::map < std::string, Literal*> record = element->getRecordVal();
            for(auto x : record) {
                String* nodeString = new String();
                nodeString->setStringVal(x.first);
                node->addListVal(nodeString);
            }
            return node;
        }
        else if (name == "record-values") {
            Literal* element = parameters[0]->codegen(memory);
            if (element->getType() != "Record") {
                std::cout << "TypeError";
                exit(0);
            }
            List* node = new List();
            std::map < std::string, Literal*> record = element->getRecordVal();
            for(auto x : record) {
                node->addListVal(x.second);
            }
            return node;
        }
        else if (name == "record-field") {
            Literal* element1 = parameters[0]->codegen(memory);
            Literal* element2 = parameters[1]->codegen(memory);
            if (element1->getType() != "Record") {
                std::cout << "TypeError";
                exit(0);
            }
            if (element2->getType() != "String") {
                std::cout << "TypeError";
                exit(0);
            }
            std::map < std::string, Literal*> record = element1->getRecordVal();
            if (record.count(element2->getStringVal()) == 0) {
                std::cout << "Record Exception, value does not exist";
                exit(0);
            }
            return record[element2->getStringVal()];
        }
        else if (name == "set") {
            Literal* element2 = parameters[1]->codegen(memory);
            std::string varName = parameters[0]->getName();
            if (memory->variables.count(varName) == 0) {
                std::cout << "Variable with name " + varName + " does not exist";
                exit(0);
            }
            memory->variables[varName] = element2;
            return new Literal();
        }
        else if (invocType == "Variable") {
            if (memory->variables.count(name) == 0) {
                std::cout << "Variable with name " + name + " does not exist";
                exit(0);
            }
            return memory->variables[name];
        }
        else if (name == "for") {
            Memory* memory2 = new Memory();
            memory2->variables = memory->variables;
            memory2->functions = memory->functions;
            std::string it = parameters[0]->getName();
            Literal* element = parameters[1]->codegen(memory);

            if (element->getType() == "Integer") {
                for (int i = 0; i < element->getIntVal(); i++){
                    Integer* nodeInt = new Integer();
                    nodeInt->setIntVal(i);
                    memory2->variables[it] = nodeInt;
                    parameters[2]->codegen(memory2);
                }
            }
            else if (element->getType() == "List") {
                std::vector <Literal*> lst = element->getListVal();
                for (int i = 0; i < lst.size(); i ++) {
                    memory2->variables[it] = lst[i];
                    parameters[2]->codegen(memory2);
                }
            }
            else {
                std::cout << "TypeError";
                exit(0);
            }

            for (auto x : memory->variables) {
                memory->variables[x.first] = memory2->variables[x.first];
            }
            return new Literal();
        }
        else if (name == "for/list") {
            Memory* memory2 = new Memory();
            memory2->variables = memory->variables;
            memory2->functions = memory->functions;
            std::string it = parameters[0]->getName();
            Literal* element = parameters[1]->codegen(memory);
            
            List* nodeList = new List();

            if (element->getType() == "Integer") {
                for (int i = 0; i < element->getIntVal(); i++){
                    Integer* nodeInt = new Integer();
                    nodeInt->setIntVal(i);
                    memory2->variables[it] = nodeInt;
                    nodeList->addListVal(parameters[2]->codegen(memory2));
                }
            }
            else if (element->getType() == "List") {
                std::vector <Literal*> lst = element->getListVal();
                for (int i = 0; i < lst.size(); i ++) {
                    memory2->variables[it] = lst[i];
                    nodeList->addListVal(parameters[2]->codegen(memory2));
                }
            }
            else {
                std::cout << "TypeError";
                exit(0);
            }

            for (auto x : memory->variables) {
                memory->variables[x.first] = memory2->variables[x.first];
            }
            return nodeList;
        } 
        else if (name == "return") {
            return parameters[0]->codegen(memory);
        } 
        else if (invocType == "Function") {
            Memory* memory2 = new Memory();
            memory2->variables = memory->variables;
            memory2->functions = memory->functions;

            if (memory->functions.count(name) == 0) {
                std::cout << "Function with name " << name << " does not exist";
                exit(0); 
            }
            Node* func = memory->functions[name];
            std::vector <Node*> params = func->getParameters();
            std::map <std::string, bool> existParams; 

            if (params.size() > parameters.size()) {
                std::cout << "Not enough parameters";
                exit(0);
            }
            if (params.size() < parameters.size()) {
                std::cout << "Too many parameters";
                exit(0);
            }

            int i = 0;
            for(auto param : params) {
                if (existParams[param->getName()]) {
                    std::cout << "Parameter with name " << param->getName() << " already exist";
                    exit(0);
                }
                existParams[param->getName()] = 1;
                Literal* element = parameters[i]->codegen(memory);
                if (element->getType() != param->getType()) {
                    std::cout << "Not correct parameter given";
                    exit(0);
                }
                memory2->variables[param->getName()] = element;
            }

            Literal* res = func->getBody()->codegen(memory2);

            if (func->getType() != "Any" && res->getType() != func->getType()) {
                std::cout << "TypeError";
                exit(0);
            }

            for (auto x : memory->variables) {
                if (!existParams[x.first])
                    memory->variables[x.first] = memory2->variables[x.first];
            }
            return res;
        }
        else {
            std::cout << "Forgot something";
            exit(0);
        }
    }
};

#endif