//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include "clsQueueLine.h"
using namespace std;

int main()
{
  
	system("color A6");
	clsQueueLine PayBillsQueue("A0", 10);

	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();

	PayBillsQueue.PrintAllTickets();


}