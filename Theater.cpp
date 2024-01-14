#include <stdafx.h>
#include <Theater.h>

Theater::Theater(){
  reset() //Clear theater settings
}

double Theater::getPrices() {
  for(int i = 0; i < SIZE; i++){
    cout<< "Enter the price for row " << i + 1 << ": ";
    cin>> prices[i];
  }
  while (prices[i] < 0){
    cout<< "Invalid price. Enter a valid price" << i + 1 << ":";
    cin>>prices[i];
  }

  return prices[SIZE];
}

void Theater::totalPerRow(){
  int totalPerRow = 0;

  for(int i = 0; i < SIZE; i++) {
    totalPerRow = 0;
    for(int j = 0; j < SIZE; j++){
      if(seats[i][j] == _open){
        totalPerRow +=1
      }
    }
    cout<< "Row " << i + 1 << " has " << totalPerRow << "avalible";
  }
}

void Theater::seatPick(){
   cout<< "What row would you like to sit in? ";
   cin >> _cRow;

   while( _cRow <= 0 || _cRow > SIZE) {
    cout << "Invalid row number. Input new row:";
    cin >> _cRow;
   }

   cout << "What column would you like to sit in?"
   cin >> _cCol;

    while( _cCol <= 0 || _cCol > SIZE) {
    cout << "Invalid column number. Input new column:";
    cin >> _cCol;
   }

   while(seats[_cRow - 1][_cCol - 1] == _taken){
    cout << "Seats are taken pick a different seat";
    cout << "Select row";
    cin >> _cRow;

    while( _cRow <= 0 || _cRow > SIZE) {
    cout << "Invalid row number. Input new row:";
    cin >> _cRow;
   }

    cout << "Select column";
    cin >> _cCol;
    while( _cCol <= 0 || _cCol > SIZE) {
    cout << "Invalid column number. Input new column:";
    cin >> _cCol;
   }
   }

   seats[_cRow - 1][_cCol - 1] = _taken;

   _total = _total + prices[_cRow - 1];

   totalSoldSeats += 1;
   display();
   totalSales();
}

void Theater::totalSales() {
  cout << "Total Sales: $" << _total << endl;
}

void Theater::display() {
  cout<< setw(5) <<" ";

  for(int i = 0; i < 15; i++) {
    cout << right << setw(4) << i + 1;
  }

  cout<<endl;

  for(int i = 0; i < SIZE; i++) {

    cout << "Row " << left < setw(3) << i + 1;

    for(int j = 0; j < SIZE; j++) {
      cout << "|" <<seats[i][j] << "|";

    }

    cout << endl;
  }
}

void Theater::reset() {
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      seats[i][j] = _open;
    }
  }

  _total = 0;
  totalSoldSeats = 0;
}

void Theater::runProgram() {
  getPrices()
  display()

  do {
    cout <<"Available Commands: " <<endl;
    cout << "1) "<< _selectSeats <<endl;
    cout << "2) "<< _viewTotalTicketSales <<endl;
    cout << "3) "<< _soldSeats <<endl;
    cout << "4) "<< _availableSeatsInEachRow <<endl;
    cout << "5) "<< _totalAvailableSeats <<endl;
    cout << "6) "<< _reset <<endl;
    cout << "7) "<< _end <<endl;
    cin >> _command;

    switch (_command) {
    case 1:
    seatPick()
      break;
    
    case 2:
    cout << "Total Sales: $" << _total <<endl;
    break;

    case 3:
    cout << totalSoldSeats << "ticket(s) have been sold." <<endl;
    break;

    case 4:
    totalPerRow();
    break;

    case 5:
    cout << "There are " << 225 - totalSoldSeats << "seats available" << endl;
    break;

    case 6:
    reset();
    cout << "Program has been reset"<<endl;
    getPrices();
    display();
    break;

    case 7:
    break;

    default:
      cout << "Invalid command please input a valid command"<<endl;
      cout <<"Available Commands: " <<endl;
      cout << "1) "<< _selectSeats <<endl;
      cout << "2) "<< _viewTotalTicketSales <<endl;
      cout << "3) "<< _soldSeats <<endl;
      cout << "4) "<< _availableSeatsInEachRow <<endl;
      cout << "5) "<< _totalAvailableSeats <<endl;
      cout << "6) "<< _reset <<endl;
      cout << "7) "<< _end <<endl;
      cin >> _command;
      break;
    } 
  }while(_command != 7)
}

Theater:~Theater() {
  system("pause");
}