/*
 * =========================================================================================
 * Name        : requestLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 2 - Data structures and Algorithms - Fall 2017
 *               This library contains functions used for event management
 * =========================================================================================
 */

#ifndef DSA171A2_REQUESTLIB_H
#define DSA171A2_REQUESTLIB_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>

#include "dsaLib.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define REQUEST_CODE_SIZE     16
#define MAX_PARAM_SIZE         6
using namespace std;

typedef struct VM_Request {
    char        code[REQUEST_CODE_SIZE];
    double      params[MAX_PARAM_SIZE];

    VM_Request() {
        *code   = '0';// default event is "0"
        code[1] = 0;
    }
    VM_Request(char* str) {
        strncpy(code, str, REQUEST_CODE_SIZE - 1);
    }
    VM_Request(string& str) {
        strncpy(code, str.data(), REQUEST_CODE_SIZE - 1);
    }
    VM_Request(VM_Request& a) { // copy constructor
        memcpy(code, a.code, REQUEST_CODE_SIZE);
        memcpy(params, a.params, MAX_PARAM_SIZE * sizeof(double));
    }

    VM_Request(VM_Request&& a) { // move constructor
        int i = 0;
        while(a.code[i]) {
            code[i] = a.code[i];
            i++;
        }
        code[i] = 0;
    }

    bool operator==(VM_Request &b) {
        return strcmp(code, b.code) == 0;
    }
};

void loadRequests(char* fName, L1List<VM_Request> &);

#endif //DSA171A2_REQUESTLIB_H
