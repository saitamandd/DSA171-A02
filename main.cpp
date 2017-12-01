#include <iostream>

#include "dsaLib.h"
#include "requestLib.h"
#include "dbLib.h"

using namespace std;



/// This function displays the content of database
void display(L1List<VM_Record>& bList) {
    cout.flush();
    bList.traverse(printVMRecord);
}

int main(int narg, char** argv) {
    L1List<VM_Request>  requestList;
    L1List<VM_Record>   db;

    loadRequests(argv[1], requestList);
    loadVMDB(argv[2], db);

    cout << fixed << setprecision(12);// preset for floating point numbers

    process(requestList, db);

    cout << resetiosflags(ios::showbase) << setprecision(-1);

    return 0;
}