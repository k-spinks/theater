#pragma once
#include <iosream>
#include <string>
#include <iomanip>

using namespace std ;

private: 
  static const int SIZE = 15;
  static const int _ROWS = SIZE;
  static const int _COLS = SIZE;
  char seats[_ROWS][_COLS];
  double prices[_ROWS];
  char _open = '#';
  char _taken = '~';
  int _cRow = 0;
  int _cCols = 0;
  double _total = 0;
  int totalSoldSeats = 0;
  int _command;
  string _selectSeat = "SELECT SEAT";
  string _viewTotalTicketSales = "VIEW TOTAL SALES";
  string _soldSeats = "SOLD SEATS";
  string _availableSeatsInEachRow = "AVAILABLE SEATS PER ROW";
  string _totalAvailableSeats = "TOTAL AVAILABLE SEATS";
  string _help = "HELP";
  string _reset = "RESET THEATER";
  string _end = "END";

public:
  Theater();

  double getPrices();
  void totalPerRow();
  void seatPick();
  void totalSales();
  void reset();
  void display();
  void runProgram();

  ~Theater();
