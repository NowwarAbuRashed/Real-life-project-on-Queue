#include <iostream>
#include"clsQueueLine.h"
using namespace std;

int main()
{
	clsQueueLine PayBillsQueue("A0", 10);
	clsQueueLine SubscriptionsQueue("B0", 5);

	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();

	cout << "\nPay Bills Queue Info:\n";
	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintTicketsLineRTL();
	PayBillsQueue.PrintTicketsLineLTR();

	PayBillsQueue.PrintAllTickets();

	cout << "\nPay Bills Queue After Serving One Client\n";
	PayBillsQueue.ServeNextClient();

	PayBillsQueue.PrintInfo();


	SubscriptionsQueue.IssueTicket();
	SubscriptionsQueue.IssueTicket();
	SubscriptionsQueue.IssueTicket();

	cout << "\nSubscriptions Queue Info:\n";
	SubscriptionsQueue.PrintInfo();
	SubscriptionsQueue.PrintTicketsLineRTL();
	SubscriptionsQueue.PrintTicketsLineLTR();
	
	SubscriptionsQueue.PrintAllTickets();

	cout << "\nSubscriptions Queue After Serving One Client\n";
	SubscriptionsQueue.ServeNextClient();
	SubscriptionsQueue.PrintInfo();



}
