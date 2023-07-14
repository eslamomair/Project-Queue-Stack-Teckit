#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <stack>
using namespace std;
class clsQueueLine
{
private:
	short _TotalTickets = 0;
	short _AverageServerTime = 0;
	string _Prefix = "";

	class clsTicket
	{
		
		short _Number = 0;
		string _Prefix;
		string _TicketTime;
		short _WaitingClients = 0;
		short _AverageServeTime = 0;
		short _ExpectdServeTime = 0;

		string _SetTime()
		{
			time_t t = time(0);
			tm *now  = localtime(&t);

			string TimeAndDate =
				to_string(now->tm_year + 1900) + "/" + to_string(
					now->tm_mon + 1) + "/" + to_string(now->tm_wday) + "   -    " + to_string(
						now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(
							now->tm_sec);
			return TimeAndDate;
		}
	public:
		clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
		{
			_Number = Number;
			_TicketTime = _SetTime();
			_Prefix = Prefix;
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
		}

		string Prefix()
		{
			return _Prefix;
		}

		short Number()
		{
			return _Number;
		}

		string FullNumber()
		{
			return _Prefix + to_string(_Number);
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		short WaitingClients()
		{
			return _WaitingClients;
		}

		short ExpectedServeTIme()
		{
			return _AverageServeTime * _WaitingClients;
		}

		void Print()
		{
			cout << "\n\t\t\t________________________\n";
			cout << "\n\t\t\t             " << FullNumber();
			cout << "\n\t\t\t    " << _TicketTime;
			cout << "\n\t\t\t    Waiting Clients = " << _WaitingClients;
			cout << "\n\t\t\t    Serve Time In";
			cout << "\n\t\t\t    " << ExpectedServeTIme() << "  Minutes";
			cout << "\n\t\t\t________________________\n";
		}
	};

public:

	queue <clsTicket> QueueLine;

	clsQueueLine(string Prefix, short AverageServeTIme)
	{
		_Prefix = Prefix;
		_TotalTickets = 0;
		_AverageServerTime = AverageServeTIme;
		
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets,WaitingClients(), _AverageServerTime);
		QueueLine.push(Ticket);
	}

	int WaitingClients()
	{
		return QueueLine.size();
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
		{
			return "No Clients Left .";
		}
		else
		{
			return QueueLine.front().FullNumber();
		}
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
		{
			return false;
		}
		QueueLine.pop();
		true;

	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t_______________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t_______________________________\n";
		cout << "\n\t\t\t       Prefix  = " << _Prefix;
		cout << "\n\t\t\t       Total Tickets  =" << _TotalTickets;
		cout << "\n\t\t\t       Served Clients  =" << ServedClients();
		cout << "\n\t\t\t       Waiting Clients =" << WaitingClients();
		cout << "\n\t\t\t_______________________________\n";
		cout << "\n";

	}

	void PrintTicketsLineRTL()
	{
		if (QueueLine.empty()) cout << "\n\t\tTickets : No Tickets>";
		else cout << "\n\t\tTickets";

		queue<clsTicket>TempQueueuLine = QueueLine;

		while (!TempQueueuLine.empty())
		{
			clsTicket Ticket = TempQueueuLine.front();
			cout << "  " << Ticket.FullNumber() << "<--";
			TempQueueuLine.pop();
		}
		cout << "\n";
	}

	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty()) cout << "\n\t\tTickets : No Tickets>";
		else cout << "\n\t\tTickets";

		queue<clsTicket>TempQueueuLine = QueueLine;
		stack<clsTicket>TempStackLine;

		while (!TempQueueuLine.empty())
		{
			TempStackLine.push(TempQueueuLine.front());
			TempQueueuLine.pop();
		}

		while (!TempStackLine.empty())
		{
			clsTicket Ticket = TempStackLine.top();
			cout << "  " << Ticket.FullNumber() << " -->";
			TempStackLine.pop();
		}
		cout << "\n";
	}

	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t        ---Tickets---";
		if (QueueLine.empty())
			cout << "\n\n\t\t\t    --No Tickets--\n";

		queue <clsTicket>TempQueueLine = QueueLine;

		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}
	}
};