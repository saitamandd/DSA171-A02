/*
 * ==========================================================================================
 * Name        : processData.cpp
 * Description : student code for Assignment 2 - Data structures and Algorithms - Fall 2017
 * ==========================================================================================
 */
#include <iostream>
#include <vector>
#include <functional>
#include <math.h>
#include "requestLib.h"
#include "dbLib.h"

using namespace std;

#define GPS_DISTANCE_ERROR 0.005

bool initVMGlobalData(void **pGData)
{
      // TODO: allocate and initialize global data
      // return false if failed
      return true;
}

void releaseVMGlobalData(void *pGData)
{
      // TODO: do your cleanup, left this empty if you don't have any dynamically allocated data
}

void request1();
void request2();
void request3();
void request4();
void request5();
void request6();
void request7();
void request8();
void request9();

bool processRequest(VM_Request &request, L1List<VM_Record> &recordList, void *pGData)
{
      // TODO: Your code goes here
      // return false for invlaid events
      int event = request.code[0] - '0';

      switch (event)
      {
      case 1:
            request1();
            break;

      case 2:
            request2();
            break;

      case 3:
            request3();
            break;

      case 4:
            request4();
            break;

      case 5:
            request5();
            break;

      case 6:
            request6();
            break;

      case 7:
            request1();
            break;

      case 8:
            request1();
            break;

      case 9:
            request1();
            break;

      default:
            break;
      }
            return true;
      }

      void request1();
      void request2();
      void request3();
      void request4();
      void request5();
      void request6();
      void request7();
      void request8();
      void request9();